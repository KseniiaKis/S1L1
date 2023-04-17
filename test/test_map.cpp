#include "..\src\MapLib\Map.h"
#include <gtest.h>
using namespace std;

typedef TMap<int, int> AllInt;

//TMap(size_t sz, K* key, V* val);
TEST(TMap, can_create_obj_size_key_val)
{
  int key;
  int val;
  size_t sz = 2;
  
  ASSERT_NO_THROW(AllInt map(sz, &key, &val));
}

//TMap(size_t sz = 0);
TEST(TMap, can_create_obj_size)
{
  int sz = 2;
  ASSERT_NO_THROW(AllInt map(sz));
}
//TMap(const TMap<K, V>& map);
TEST(TMap, can_create_copy_of_tmap_obj)
{
  size_t sz = 2;
  int val[2]{ 1,2 };
  int key[2]{ 1,4 };
  TMap<int, int> map1(sz, key, val);
  ASSERT_NO_THROW(AllInt map_2(map1));
}

//TMap(TMap<K, V>&& map) noexcept;

//~TMap();

//size_t Size();
TEST(TMap, size_of_map_is_correct)
{
  int val[2]{ 1,2 };
  int key[2]{ 1,4 };
  size_t sz = 2;
  TMap<int, int> map(sz, key, val);
  EXPECT_EQ(map.Size(), sz);
}

//size_t Count();
TEST(TMap, count_is_correct)
{
  int val[2]{ 1,2 };
  int key[2]{ 1,4 };
  size_t sz = 2;
  TMap<int, int> map(sz, key, val);
  EXPECT_EQ(map.Count(), sz);
}

//K GetKey(size_t ind);
TEST(TMap, correct_key)
{
  int k = 1;
  int v = 2;
  size_t sz = 1;
  TMap<int, int> map(sz, &k, &v);
  EXPECT_EQ(map.GetKey(0), k);
}

//bool IsFull();
TEST(TMap, it_is_full)
{
  int k = 1;
  int v = 2;
  size_t sz = 1;
  TMap<int, int> map(sz, &k, &v);
  EXPECT_EQ(map.IsFull(), 1);
}
//void Insert(K key, V val, bool unique);

//bool IsInsertKey(const K key) const;
//const V& operator[] (K key) const;
//V& operator[] (K key);

//bool operator == (const TMap<K, V>& map);
TEST(TMap, can_compare_)
{
  int k = 1;
  int v = 2;
  size_t sz = 1;
  TMap<int, int> map(sz, &k, &v);
  TMap<int, int> map_1(map);
  EXPECT_TRUE(map == map_1);
}

//bool operator != (const TMap<K, V>& map);
TEST(TMap, can_compare_correctly)
{
  int k = 1;
  int v = 2;
  size_t sz = 1;
  TMap<int, int> map(sz, &k, &v);
  TMap<int, int> map_1(map);
  EXPECT_FALSE(map != map_1);
}
//TMap<K, V> operator = (const TMap<K, V>& map);

//TMap<K, V> operator = (TMap<K, V>&& map);
TEST(TMap, cannot_copy_itself)
{
  int k = 1;
  int v = 2;
  size_t sz = 1;
  TMap<int, int> map(sz, &k, &v);
  ASSERT_ANY_THROW(map = map);
}
