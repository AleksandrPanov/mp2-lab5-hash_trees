#pragma once
#pragma once
#include <iostream>

using namespace std;

template <class Data>
struct Node
{
	Data data;
	Node* next;
	Node()
	{

	}
	Node(const Node<Data> &n)
	{
		data = n.data;
		next = n.next;
	}
};

template <class Data>
class List
{
protected:
	Node <Data> *head;
	int size = 0;
public:
	List() : head(0) {};
	bool isEmpty() { return (head == NULL); }
	Data quick_pop_front()
	{
			Node<Data> tmp = *head;
			Node<Data> *p = head;
			if (head->next)
			{
				head = head->next;
				delete p;
			}
			else 
			{
				delete head;
				head = 0;
			}
			size--;
			return tmp.data;
	}
	void push_front(Data obj)
	{
		Node<Data> *newNode = new Node<Data>;
		newNode->data = obj;
		newNode->next = head;
		head = newNode;
		size++;
	}
	Node<Data>* find(Data &obj)
	{
		Node <Data> *tmp = head;
		while (tmp)
		{
			if (tmp->data == obj)
				return tmp;
			tmp = tmp->next;
		}
		delete tmp;
		return 0;
	}
	void update(Node <Data> *p, Data &n)
	{
		p->data = n;
	}
	int getSize()
	{
		return size;
	}
	int reverce()
	{
		int count = 0;
		Node<Data> *tmp = 0;
		Node<Data> *next = 0;
		if (head)
			next = head->next;
		while (next != 0)
		{
			head->next = tmp;
			tmp = head;
			head = next;
			next = head->next;
			count++;
		}
		count = count + 1;
		head->next = tmp;
		return count;
	}
	~List()
	{
		Node <Data> *tmp;
		while (!isEmpty())
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}
};