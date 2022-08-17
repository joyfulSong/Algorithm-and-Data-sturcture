// https://www.studytonight.com/data-structures/binary-search-tree
// https://happysalmon.tistory.com/85 전위중위후위
#include <iostream>

struct tree_node
{
	int data;
	tree_node* left, * right; //자기가 속한 구조체에 대한 포인터?
};

class BST
{
	tree_node* root; //이게 감춰져있으므로, 외부함수 통해서 내부함수로 들어와야함. 감춘 이유: 외부에서 시작점을 일일이 알 필요가 없어서.
	// 내부 함수. main에선 root와 이 함수들에 직접 접근 안되고 public 함수 통해서 접근해야함 (객체를 통해 접근해서 그런거지?)
	void insert(tree_node*, int);
	bool search(int, tree_node*);
	void inorder(tree_node*);
	void preorder(tree_node*);
	void postorder(tree_node*);

public:
	BST()
	{
		root = NULL;
	}

	//public 함수
	void insert(int);
	bool search(int key);
	void inorder();
	void preorder();
	void postorder();
};

// 내부 함수가 외부함수보다 먼저 선언되어있어야함.
void BST::insert(tree_node* node, int d)
{
	// element to be inserted is lesser than node’s data
	if (d < node->data)
	{
		// if left subtree is present
		if (node->left != NULL)
			insert(node->left, d);

		// create new node
		else
		{
			node->left = new tree_node;
			node->left->data = d;
			node->left->left = NULL;
			node->left->right = NULL;
		}
	}

	// element to be inserted is greater than node’s data
	else if (d >= node->data)
	{
		// if left subtree is present
		if (node->right != NULL)
			insert(node->right, d);

		// create new node
		else
		{
			node->right = new tree_node;
			node->right->data = d;
			node->right->left = NULL;
			node->right->right = NULL;
		}
	}

}

void BST::insert(int d)
{
	if (root != NULL)
		insert(root, d);
	else
	{
		root = new tree_node;
		root->data = d;
		root->left = NULL;
		root->right = NULL;
	}
}
bool BST::search(int d, tree_node* node)
{
	bool ans = false;

	// node is not present
	if (node == NULL)
		return false;

	// Node’s data is equal to value searched
	if (d == node->data)
		return true;

	// Node’s data is greater than value searched
	else if (d < node->data)
		ans = search(d, node->left); // 11찾을때 여기 먼저 갔다가 1.

	// Node’s data is lesser than value searched
	else
		ans = search(d, node->right); // 11찾을 때 여기로 2. 여기서 false 되고 서 1.로 stack 푸는데, return은 계속 false인가?

	return ans;
}

bool BST::search(int d)
{
	if (root == NULL)
		return false;
	else
		return  search(d, root);
}

void BST::preorder(tree_node* node)
{
	if (node != NULL)
	{
		// std::cout << node->data << std::endl;
		std::cout << node->data << " ";
		preorder(node->left); // left의 끝까지 갔다가 null이 되면 스택다 풀어서 처음 갈래로 돌아와서 right로 내려감
		preorder(node->right);
	}
}

void BST::postorder(tree_node* node)
{
	if (node != NULL)
	{
		postorder(node->left);
		postorder(node->right);
		// std::cout << node->data << std::endl;
		std::cout << node->data << " ";
	}
}

void BST::inorder(tree_node* node)
{
	if (node != NULL)
	{
		inorder(node->left);
		// std::cout << node->data << std::endl;
		std::cout << node->data << " ";
		inorder(node->right);
	}
}

void BST::preorder()
{
	if (root == NULL)
		std::cout << "TREE IS  EMPTY\n";
	else
		preorder(root);
}

void BST::postorder()
{
	if (root == NULL)
		std::cout << "TREE IS  EMPTY\n";
	else
		postorder(root);
}

void BST::inorder()
{
	if (root == NULL)
		std::cout << "TREE IS EMPTY\n";
	else
		inorder(root);
}

int main(void)
{
	BST bst;

	bst.insert(20);

	bst.insert(10);
	bst.insert(30);

	bst.insert(5);
	bst.insert(25);
	bst.insert(35);

	if (bst.search(10))
		std::cout << "111" << std::endl;
	else
		std::cout << "222" << std::endl;

	if (bst.search(11))
		std::cout << "333" << std::endl;
	else
		std::cout << "444" << std::endl;

	bst.preorder();
	std::cout << std::endl;

	bst.postorder();
	std::cout << std::endl;

	return 0;
}

///////////////////////////////////
//
//        20
//    10      30
//  05  xx  25  35
///////////////////////////

// output :
// 111
// 444
// 20 10 5 30 25 35
// 5 10 25 35 30 20
