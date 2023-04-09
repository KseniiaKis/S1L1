#include <gtest.h>
#include <iostream>
#include "..\src\SMapLib\SMap.h"
 
typedef TSmap<int, int> Typ;

TEST(TSMap, can_create_tsmap_obj_default)
{
  ASSERT_NO_THROW(Typ map());
}

TEST(TSmap, can_create_copy_of_tsmap_obj)
{
  Typ map_1(2);
  ASSERT_NO_THROW(Typ map(map_1));
}

TEST(TSmap, can_set_first_item)
{
  TSmap<int, int> smap(1);
  TItem<int, int> item(3, 14);
  ASSERT_NO_THROW(smap.SetFirstObjects(item));
}

TEST(TSmap, can_add_new_element)
{
  TSmap<int, int> smap(1);
  TItem<int, int> item(3, 14);
  smap.SetFirstObjects(item);
  int k = 2, d = 7;
  ASSERT_NO_THROW(smap.Add(&k, &d));
}

TEST(TSmap, is_actually_sorted)
{
  TSmap<int, int> smap(1);
  TItem<int, int> item(3, 14);
  smap.SetFirstObjects(item);
  int k = 2, d = 7;
  smap.Add(&k, &d);
  EXPECT_EQ(smap.BinarySearch(2), 0);
}