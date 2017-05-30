#include "AVL_tree.h"
#include "gtest.h"

#include <string>
using std::string;

TEST(AVL_tree, can_create)
{
	AVLTree<string, int> t;
	EXPECT_NO_THROW(t);
}

TEST(AVL_tree, can_search)
{
	AVLTree<string, int> t;
	string s = "aaaa";
	int n = 0;
	AVLNode<string, int>* k;
	EXPECT_NO_THROW(t, k);
}

TEST(AVL_tree, can_find)
{
	const int n = 5;
	AVLTree<string, int> t;
	string s[n] = {"123","d","b","a","e"};
	AVLNode<string, int>* k;
	for (int i = 0; i < n; i++)
	{
		t[s[i]] = 1 + i;
		EXPECT_TRUE(t.find(s[i], k));
	}
	for (int i = 0; i < n; i++)
	{
		EXPECT_TRUE(t.find(s[i], k));
	}
}