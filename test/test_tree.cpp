#include <gtest.h>
#include <iostream>
#include "..\src\TTreeLib\TTree.h"

typedef TAVLTree<int, double> avltree;

TEST(AVLtree, can_create_tree)
{
  ASSERT_NO_THROW(avltree());
}

TEST(AVLtree, can_get_tree_size)
{
  avltree a;
  EXPECT_TRUE(a.size() == 0);
}

TEST(AVLtree, can_check_empty)
{
  avltree a;
  EXPECT_TRUE(a.empty());
}

TEST(AVLtree, can_find_elem)
{
  avltree a;
  a.insert(1, 3.14);
  EXPECT_TRUE(a.find(1));
}

TEST(AVLtree, can_insert_new_elem)
{
  avltree a;
  ASSERT_NO_THROW(a.insert(1, 3.14));
}

TEST(AVLtree, can_replace_elem)
{
  avltree a;
  a.insert(1, 3.14);
  a.insert(1, 3.1415, true);
  EXPECT_EQ(a.at(1), 3.1415);
}
TEST(AVLtree, can_get_data)
{
  avltree a;
  a.insert(1, 3.14);
 EXPECT_EQ(a.at(1), 3.14);
}

TEST(AVLtree, can_remove_elem)
{
  avltree a;
  a.insert(1, 3.14);
  a.remove(1);
  EXPECT_FALSE(a.find(1));
}