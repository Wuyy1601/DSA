#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int node_data)
	{
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList
{
public:
	Node* head;
	Node* tail;

	SinglyLinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

	void Insert_node(int data)
	{
		Node* node = new Node(data);
		if (!this->head)
		{
			this->head = node;
		}
		else
		{
			this->tail->next = node;
		}
		this->tail = node;
	}
	void Print()
	{
		Node* p = head;
		while (p != nullptr)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}

	Node* Search(int x)
	{
		Node* p = head;
		while (p != nullptr)
		{
			if (p->data == x)
			{
				return p;
			}
		}
		return nullptr;
	}

	void XoaHead()
	{
		Node* p = head;
		if (p == nullptr) { return; }
		else {
			head = head->next;
			delete p;
		}
	}

	void DeleteNode(int x)
	{
		Node* p = head;
		while (p != nullptr)
		{
			if (p->data = x)
			{

			}
		}
	}

};

int main()
{
	SinglyLinkedList* List1 = new SinglyLinkedList();
	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int data;
		cin >> data;
		List1->Insert_node(data);
	}

	List1->Print();


}