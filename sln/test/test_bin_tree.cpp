#include "gtest.h"
#include "binTree.h"
#include <string>
using std::string;

TEST(bin_tree, can_create)
{
	BinTree<string, int> t;
	EXPECT_NO_THROW(t);
}
TEST(bin_tree, can_insert)
{
	BinTree<string, int> t;
	EXPECT_NO_THROW(t.insert("da",1));
	EXPECT_EQ(t["da"], 1);
}

TEST(bin_tree, can_insert_2_el)
{
	BinTree<int, int> t;
	t.insert(1,1);
	t.insert(2, 1);
	EXPECT_EQ(t[1], 1);
	EXPECT_EQ(t[2], 1);
}
TEST(bin_tree, can_insert_eq_el1)
{
	BinTree<int, int> t;
	t.insert(1, 1);
	t.insert(1, 2);
	EXPECT_EQ(t[1], 2);
}
TEST(bin_tree, can_insert_eq_el2)
{
	BinTree<int, int> t;
	t.insert(1, 1);
	t.insert(2, 1);
	t.insert(2, 2);
	EXPECT_EQ(t[1], 1);
	EXPECT_EQ(t[2], 2);
}

TEST(bin_tree, can_insert_er)
{
	BinTree<int, int> t;
	t.insert(1, 1);
	t.insert(2, 1);
	t.erase(2);
	EXPECT_EQ(t[2], 0);
	t.erase(2);
	t.erase(1);
	EXPECT_EQ(t.length(), 0);
	EXPECT_EQ(t[1], 0);
	t.erase(1);
	EXPECT_TRUE(t.find(1)== 0);
}