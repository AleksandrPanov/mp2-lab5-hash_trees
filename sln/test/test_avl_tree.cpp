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