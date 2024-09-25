#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* pre;

};

struct list
{
	node* head;
	node* tail;
};

node* createnode(int data)
{
	node* p = new node;
	p->data = data;
}
void createlist(list* l)
{
	l->head = NULL;
	l->tail = NULL;
}

void addtail(list* l, int data)
{
	node* p = createnode(data);
	if (l->head == nullptr)
	{
		l->head = p;
		l->tail = p;
	}
	else
	{
		l->tail->next = p;
	}

}