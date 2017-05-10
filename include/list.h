#pragma once
#pragma once
#include <iostream>
#include "cont.h"
using namespace std;

template <class Data>
struct Node
{
	Data data;
	Node* next;
	Node(): next(0)	{}
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
public:
	int size;

	List() : head(0), size(0) {};
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
	void erase(Data &obj)
	{
		Node <Data> *tmp = head, *pre = 0;
		while (tmp)
		{
			if (tmp->data == obj)
			{
				if (pre)
					pre->next = tmp->next;
				else head = tmp->next;

				delete tmp;

				return;
			}
			pre = tmp;
			tmp = tmp->next;
		}
	}
	int getSize()
	{
		return size;
	}
	void reverce()
	{
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
		}
		head->next = tmp;
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
