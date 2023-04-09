#pragma once
#include<iostream>
#include "..\src\MapLib\Map.h"
#include "..\src\TItemLib\TItem.h"

using namespace std;

template<class Key, class Data>
class TSmap
{
protected:
  TItem<Key, Data>* items;
  int size;
  int count;

public:
  TSmap(int size = 100);

  void SetFirstObjects(TItem<Key, Data>& _item);

  ~TSmap();

  Data& operator[](const Key& k);

  size_t BinarySearch(const Key& _key);
  Data* Find(const Key& k);
  void Add(Key* k, Data* d);
  //void Delete(const Key& k);
};

template<class Key, class Data>
inline TSmap<Key, Data>::TSmap(int size)
{
  if (size != 0)
  {
    int s = size;
    items = new TItem<Key, Data>[s];
    count = 0;
  }
  else
    items = nullptr;
}

template<class Key, class Data>
inline void TSmap<Key, Data>::SetFirstObjects(TItem<Key, Data>& _item)
{
  if (count < size)
  {
    items[count].setKey(_item.getKey());
    items[count].setData(_item.getData());
    count++;
  }
}


template<class Key, class Data>
inline TSmap<Key, Data>::~TSmap()
{
  if (items != nullptr)
  {
    items = nullptr;
    size = 0;
    count = 0;
  }
  else
    throw"Error items!";
}

template<class Key, class Data>
inline Data& TSmap<Key, Data>::operator[](const Key& k)
{
  if (k >= 0 && k <= size)
    return items[k].getKey();
  else
    throw"Error k!";
}

template<class Key, class Data>
inline size_t TSmap<Key, Data>::BinarySearch(const Key& _key)
{
  size_t start = 0;
  size_t index = count / 2;
  size_t end = count - 1;
  while (start <= end)
  {
    if (*(items[index].getKey()) == _key)
    {
      return index;
    }
    if (_key > *(items[index].getKey()))
    {
      start = index;
      index = (start + end) / 2;
    }
    if (_key < *(items[index].getKey()))
    {
      end = index;
      index = (end - start) / 2;
    }
    if (start == end)
    {
      return -1;
    }
  }
}

template<class Key, class Data>
inline Data* TSmap<Key, Data>::Find(const Key& _key)
{
  if (BinarySearch(_key) >= 0)
    return(items[BinarySearch(_key)].getData());
  else
    throw "Error!";
}

template<class Key, class Data>
inline void TSmap<Key, Data>::Add(Key* k, Data* d)
{
  int start = 0;
  int end = count;
  int index = count / 2;
  while (start < end)
  {
    if (items[index].getKey() > k)
    {
      end = index;
      index = (start + end) / 2;
    }
    else
    {
      start = index;
      index = (start + end) / 2;
    }
  }
  int i = count;
  while (i >= index)
  {
    items[i + 1] = items[index];
    i++;
  }
}
//
//template<class Key, class Data>
//inline void TSmap<Key, Data>::Delete(const Key& k)
//{
//  size_t index = BinarySearch(k);
//  if (index >= 0)
//  {
//    for (size_t i = index; i < count - 1; i++)
//    {
//      items[i].setKey(*(items[i + 1].getKey()));
//      items[i].setData(*(items[i + 1].getData()));
//    }
//    count--;
//  }
//  else
//    throw "Error!";
//}
