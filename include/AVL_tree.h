#pragma once
#include <queue>
#include "cont.h"

#define myNode AVLNode<Key, Data>

inline int max(int a, int b)
{
	return (a > b ? a : b);
}
inline int abs(int a)
{
	if (a > 0) return a;
	return -a;
}

template <class Key, class Data>
struct AVLNode
{
	Data data;
	Key key;
	AVLNode* left;
	AVLNode* right;
	AVLNode* prev;
	int balance;//balance node = right hight - left hight
	int height;
	AVLNode() : left(0), right(0), prev(0), balance(0), height(0), key(0), data(0) {}
	AVLNode(const Key &k):left(0), right(0), prev(0), balance(0), height(0),key(k), data(0){}
	AVLNode(const AVLNode<Key, Data> &n)
	{
		balance = n.balance;
		height = n.height;
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

	void insertAfterNode(myNode *afterNode, myNode *node)
	{
		node->prev = afterNode;
		if (node->key > afterNode->key)
			afterNode->right = node;
		else afterNode->left = node;
		calculateBalance(afterNode);
	}
	int getHeight(myNode *node)
	{
		if (node)
			return node->height;
		return -1;
	}
	//balance node = right hight - left hight
	void calculateBalance(myNode *node)//balance ok?
	{
		int hr = getHeight(node->right);
		int hl = getHeight(node->left);
		if (hr - hl == 0) return;
		if ((hr - hl == 1) || (hr - h1 == -1))
		{
			node->height = max(hr, hl) + 1;
			node->balance = hr - hl;
			if (node->prev)calculateBalance(node->prev);
			else return;
		}
	}
public:
	AVLTree() : size(0), root(0) {};
	int length()
	{
		return size;
	}
	void insert(Key &k, Data &d)
	{
		//на доработку
	}
	void erase(Key k)
	{
		//на капитальную доработку
	}
	Data& operator [](Key &k)
	{
		if (root == 0)
		{
			root = new myNode(k);
			return root->data;
		}

		myNode *n;
		if (find(k,n))
		{
			return n->data;
		}
		myNode *tmp = new myNode(k);
		insertAfterNode(n, tmp);
		return tmp->data;
	}
	bool find(Key &k, myNode* &tmp)
	{
		tmp = root; 
		myNode* prev = 0;
		while (tmp)
		{
			prev = tmp;
			if (k < tmp->key)
				tmp = tmp->left;
			else if (k > tmp->key)
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
