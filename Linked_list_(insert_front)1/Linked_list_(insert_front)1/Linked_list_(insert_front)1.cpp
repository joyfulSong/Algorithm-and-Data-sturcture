//linked list : insert a node at beginning

#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head;

void Insert(int x)
{
	Node* temp = new Node[sizeof(Node)];
	(*temp).data = x;
	temp->next = head;
	head = temp;
}

void Print()
{
	Node* temp = head;
	cout << "list is: ";

	while (temp != NULL)
	{
		cout << temp->data;
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	head = NULL; // empty at first
	cout << "how many numbers? " << endl;

	int n, i, x;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "enter the number " << endl;
		cin >> x;

		Insert(x);
		Print();
	}
}