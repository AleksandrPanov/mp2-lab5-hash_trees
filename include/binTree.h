#pragma once
#include <queue>
#include "cont.h"
#define node NodeTree<Cont<Key, Data>>
#define cont Cont<Key, Data>

template <class Data>
struct NodeTree
{
	Data data;
	NodeTree* left;
	NodeTree* right;

	NodeTree(): left(0), right(0){}
	NodeTree(const Data &d)
	{
		data = d;
		left = 0;
		right = 0;
	}
	NodeTree(const NodeTree<Data> &n)
	{
		data = n.data;
		left = n.left;
		right = n.right;
	}
};

template <class Key, class Data>
class BinTree
{
private:
	int size;
	NodeTree<Cont<Key, Data>> *root;
	void insertAfterTmp(node *tmp, node *ins)//начиная с узла tmp вставь узел ins
	{
		node *pred;
		int i;
		while (tmp)
		{
			pred = tmp;
			if (ins->data < tmp->data)
			{
				i = 0;
				tmp = tmp->left;
			}
			else if (ins->data > tmp->data)
			{
				i = 1;
				tmp = tmp->right;
			}
			else
			{
				tmp->data = ins->data;
				return;
			}
		}
		if (i == 0)	pred->left = ins;
		else pred->right = ins;
		size++;
	}
public:
	BinTree() : size(0), root(0) {};
	int length()
	{
		return size;
	}
	void insert(Key k, Data d)
	{
		if (!root)
		{
			root = new node(cont(k, d));
			size++;
			return;
		}
		node *tmp = new node(cont(k, d));
		insertAfterTmp(root, tmp);
	}
	void erase(Key k)
	{
		Data t(0);
		cont el(k, t);
		node *pred = 0, *tmp = root;
		int i;
		while (tmp)
		{
			if (el < tmp->data)
			{
				i = 0;
				pred = tmp;
				tmp = tmp->left;
			}
			else if (el > tmp->data)
			{
				i = 1;
				pred = tmp;
				tmp = tmp->right;
			}
			else
			{
				size--;
				if (pred) 
				{
					if (i == 0)
						pred->left = 0;
					else
						pred->right = 0;

					if (tmp->left)
						insertAfterTmp(pred, tmp->left);
					if (tmp->right)
						insertAfterTmp(pred, tmp->right);						
					delete tmp;
					return;
				}
				delete root;
				root = 0;
				return;
			}
		}
	}
	Data& operator [](Key k)
	{
		Data t(0);
		Cont<Key, Data> el(k, t);
		NodeTree<Cont<Key, Data>>*pred = 0, *tmp = root;
		int i;
		while (tmp)
		{
			pred = tmp;
			if (el < tmp->data)
			{
				i = 0;
				tmp = tmp->left;
			}
			else if (el > tmp->data)
			{
				i = 1;
				tmp = tmp->right;
			}
			else
			{
				return tmp->data.gd();
			}
		}
		size++;
		tmp = new NodeTree<Cont<Key, Data>>();
		tmp->data = el;
		if (root == 0)
			root = tmp;
		else
		{
			if (i == 0)	pred->left = tmp;
			else pred->right = tmp;
		}
		return tmp->data.gd();
	}
	NodeTree<Cont<Key, Data>>*find(Key k)
	{
		Data t(0);
		Cont<Key, Data> el(k, t);
		NodeTree<Cont<Key, Data>> *tmp = root;
		while (tmp)
		{
			if (el < tmp->data)
				tmp = tmp->left;
			else if (el > tmp->data)
				tmp = tmp->right;
			else
				return tmp;
		}
		return 0;
	}
	void printBFS()
	{
		queue<NodeTree<Cont<Key, Data>>*> q;
		if (root)
		q.push(root);
		while (!q.empty())
		{
			NodeTree<Cont<Key, Data>> *tmp = q.front();
			cout << tmp->data.k<<' '<< tmp->data.d<<'\n';
			if (tmp->left)
				q.push(tmp->left);
			if (tmp->right)
				q.push(tmp->right);
			q.pop();
		}
	}
};