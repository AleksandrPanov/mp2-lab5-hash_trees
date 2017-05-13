#pragma once
#include <queue>
#include "cont.h"

#define myNnode AVLNode<Key, Data>

template <class Key, class Data>
struct AVLNode
{
	Data data;
	Key key;
	AVLNode* left;
	AVLNode* right;
	AVLNode* prev;
	int balance;
	AVLNode() : left(0), right(0), prev(0), balance(0) {}
	AVLNode(const AVLNode<Key, Data> &n)
	{
		balance = n.balance;
		key = n.key;
		data = n.data;
		left = n.left;
		prev = n.prev;
		right = n.right;
	}

};

template <class Key, class Data>
class AVLTree
{
private:
	int size;
	AVLNode<Key, Data> *root;
public:
	AVLTree() : size(0), root(0) {};
	int length()
	{
		return size;
	}
	void insert(Key k, Data d)
	{
		myNnode *tmp;
		if (find(k, tmp))
			tmp->data = d;
		else
		{
			tmp = new myNnode(k, d);
			if (root == 0)
				root = tmp;
			else
			{
				int deltaBalance;
				if (prev->data > el)
				{
					prev->left = el;
					deltaBalance = -1;
				}
				else
				{
					prev->right = el;
					deltaBalance = 1;
				}
			}
		}
	}
	void erase(Key k)
	{
		Data t(0);
		Cont<Key, Data> el(k, t);
		AVLNode<Cont<Key, Data>>*pred = 0, *tmp = root;
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
					if (i == 0)	pred->left = tmp->left;
					else pred->right = tmp->right;
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
		AVLNode<Cont<Key, Data>>*pred = 0, *tmp = root;
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
		tmp = new AVLNode<Cont<Key, Data>>();
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
	bool find(Key k, myNnode* &tmp)
	{
		tmp = root; 
		myNnode* prev;
		while (tmp)
		{
			prev = tmp;
			if (el < tmp->data)
				tmp = tmp->left;
			else if (el > tmp->data)
				tmp = tmp->right;
			else
				return true;
		}
		tmp = prev;
		return false;
	}
/*	void printBFS()
	{
		queue<AVLNode<Cont<Key, Data>>*> q;
		if (root)
			q.push(root);
		while (!q.empty())
		{
			AVLNode<Cont<Key, Data>> *tmp = q.front();
			cout << tmp->data.k << ' ' << tmp->data.d << '\n';
			if (tmp->left)
				q.push(tmp->left);
			if (tmp->right)
				q.push(tmp->right);
			q.pop();
		}
	}*/
};
