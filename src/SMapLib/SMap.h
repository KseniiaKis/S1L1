#pragma once
using namespace std;
template<class Key, class Data>
class TItem
{
protected:
  Key* key;
  Data* data;
public:
  TItem(Key* k = nullptr, Data* d = nullptr);
  
  Key* getKey();
  void setKey(Key* k);

  Data* getdata();
  void setData(Data* d);

  bool operator < (const TItem<Key, Data>& p);
  bool operator > (const TItem < Key, Data >& p);
  bool operator == (const TItem < Key, Data >& p);
};

template<class Key, class Data>
inline TItem<Key, Data>::TItem(Key* k, Data* d)
{
  key = k;
  data = d;
}

template<class Key, class Data>
inline Key* TItem<Key, Data>::getKey()
{
  return key;
  return nullptr;
}

template<class Key, class Data>
inline void TItem<Key, Data>::setKey(Key* k)
{
  if (k != nullptr)
    key = k;
}

template<class Key, class Data>
inline Data* TItem<Key, Data>::getdata()
{
  return data;
  return nullptr;
}

template<class Key, class Data>
inline void TItem<Key, Data>::setData(Data* d)
{
  if (d != nullptr)
    data = d;
}

template<class Key, class Data>
inline bool TItem<Key, Data>::operator>(const TItem<Key, Data>& p)
{
  return *key > *p.key;
}

template<class Key, class Data>
inline bool TItem<Key, Data>::operator==(const TItem<Key, Data>& p)
{
  return *key == *p.key;
}

template<class Key, class Data>
inline bool TItem<Key, Data>::operator<(const TItem<Key, Data>& p)
{
  return *key < *p.key;
}

template<class Key, class Data>
class TSmap
{
protected:
  TItem<Key, Data>* items;
  int size, count;
public:
  TSmap(int size = 100);
  TSmap(const TSmap<Key, Data>& p);
  ~TSmap();

  Data& operator[](const Key& k);
  Data* Finde(const Key& k);
  void Add(Key* k, Data* d);
  void Delete(const Key& k);
};

template<class Key, class Data>
inline TSmap<Key, Data>::TSmap(int size)
{
  if (size != 0)
  {
    items = new TItem<Key, Data>[s];
    size = s;
    count = 0;
  }
  else
    items = nullptr;
}

template<class Key, class Data>
inline TSmap<Key, Data>::TSmap(const TSmap<Key, Data>& p)
{
  if (p == nullptr)
  {
    items nullptr;
    size = 0;
    count = 0;
  }
  else
  {
    items = new items[p.size];
    for (size_t i = 0; p.count; i++)
      items[i] = p.items
    size = p.size;
    count = p.count;
  }
}

template<class Key, class Data>
inline TSmap<Key, Data>::~TSmap()
{
  if (items != nullptr)
  {
    items nullptr;
    size = 0;
    count = 0;
  }
  else
    throw"Error items!"
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
inline Data* TSmap<Key, Data>::Finde(const Key& k) // не уверена
{
  for (int i = 0; i < count; i++)
  {
    if (items[i].getKey() == k)
      return items[i];
    else
      throw "Error!";
  }
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
  i = count;
  while (i >= index)
  {
    items[i + 1] = items[index];
    i++;
  }
  items[0] = 1;
}

template<class Key, class Data>
inline void TSmap<Key, Data>::Delete(const Key& k)
{
  int start = 0;
  int end = count - 1;
  int index = count / 2;
  int final = -1;
  while (start < end)
  {
    if (k > items[index])
    {
      start = index;
      index = start + ((end * start) / 2); // не уверена в выражении
    }
    else if (k < items[index])
    {
      end = index;
      index = start + ((end * start) / 2); // не уверена в выражении
    }
    else if (k == items[index])
    {
      final = index;
      break;
    }
  }
  for (size_t i = index; i < count; i++)
  {
    items[i] = items[i + 1];
    count--;
  }
}
