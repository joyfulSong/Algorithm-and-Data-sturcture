//linked list : insert a node at beginning
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};


Node* Insert(Node* head, int x)
{
	Node* temp = new Node[sizeof(Node)];
	(*temp).data = x;
	temp->next = head;
	head = temp;

	return head;
}

void Print(Node* head)
{
	Node* temp = head;
	cout << "list is: ";

	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Node* head = NULL; // empty at first
	cout << "how many numbers? " << endl;

	int n, i, x;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "enter the number " << endl;
		cin >> x;

		head = Insert(head, x);
		Print(head);
	}
}