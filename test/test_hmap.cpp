#include <gtest.h>
#include <iostream>
#include "..\src\HMapLib\HMap.h"

typedef TMap<int, double> hsmap;

TEST(HSMap, can_create_default)
{
  ASSERT_NO_THROW(hsmap m());
}

TEST(HSMap, can_insert_elem)
{
  hsmap hs;
  ASSERT_NO_THROW(hs.Add(1, 3.14));
}