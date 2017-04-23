#include "gtest.h"
#include "hash.h"
#include "word.h"

TEST(hash_table, can_insert)
{
	HashTableL<string, int, Word> h(7);
	EXPECT_NO_THROW(h.insert("ab", 0));
	EXPECT_NO_THROW(h.insert("ab", 1));
}

TEST(hash_table, can_compare_container_by_key)
{
	Cont <int, int>tmp1(1, 2, true);
	Cont <int, int>tmp2(1, 3, true);
	EXPECT_TRUE(tmp1 == tmp2);
}

TEST(hash_table, can_get)
{
	HashTableL<string, int, Word> h(7);
	EXPECT_NO_THROW(h.insert("ab", 10));
	EXPECT_EQ(h["ab"], 10);
}

TEST(hash_table, can_set)
{
	HashTableL<string, int, Word> h(7);
	h["ab"] = 10;
	EXPECT_EQ(h["ab"], 10);
}

TEST(hash_table, can_change)
{
	HashTableL<string, int, Word> h(7);
	h["ab"] = 10;
	EXPECT_EQ(h["ab"], 10);
	h["ab"] = 2;
	EXPECT_EQ(h["ab"], 2);
}

TEST(hash_table, can_erase)
{
	HashTableL<string, int, Word> h(7);
	h["aa"] = 1;
	h.erase("aa");
	EXPECT_EQ(h["aa"], 0);
}