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

TEST(bin_tree, can_insert_erase)
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
TEST(bin_tree, can_insert_and_erase)
{
	BinTree<int, int> t;

	t.insert(7, 1);
	t.insert(5, 1);
	t.insert(6, 1);

	t.insert(3, 1);
	t.insert(2, 1);
	t.insert(4, 1);

	t.insert(8, 1);

	t.erase(3);//было 7 вершин. Должно стать 6.

	int count = 0;
	for (int i = 2; i <= 8; i++)
	{
		if (t[i] == 1)
			count++;
	}
	EXPECT_EQ(count, 6);
}