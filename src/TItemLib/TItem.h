#pragma once
#include "..\src\MapLib\Map.h"
#include<iostream>

using namespace std;

template<class Key, class Data>
class TItem
{
protected:
	Key* key = nullptr;
	Data* data = nullptr;

public:
	TItem();
	TItem(Key _key, Data _data);
	TItem(Key& _key, Data& _data);
	TItem(Key* k, Data* d);

	TItem(const TItem<Key, Data>& _item);

	~TItem();

	Key* getKey();
	void setKey(Key* k);

	Data* getData();
	void setData(Data* d);

	bool operator < (const TItem<Key, Data>& p);
	bool operator > (const TItem < Key, Data >& p);
	bool operator != (const TItem<Key, Data>& p);
	bool operator == (const TItem < Key, Data >& p);
};

template<class Key, class Data>
inline TItem<Key, Data>::TItem()
{
	key = new Key;
	data = new Data;
}

template<class Key, class Data>
inline TItem<Key, Data>::TItem(Key _key, Data _data)
{
	key = new Key;
	data = new Data;
	*key = _key;
	*data = _data;
}

template<class Key, class Data>
inline TItem<Key, Data>::TItem(Key& _key, Data& _data)
{
	key = new Key;
	data = new Data;

	*key = _key;
	*data = _data;
}

template<class Key, class Data>
inline TItem<Key, Data>::TItem(Key* k, Data* d)
{
	key = new Key;
	data = new Data;

	key = k;
	data = d;
}

template<class Key, class Data>
inline TItem<Key, Data>::TItem(const TItem<Key, Data>& _item)
{
	if (_item.data == nullptr || _item.key == nullptr) throw "empty object";
	else
	{
		data = new Data;
		data = _item.data;
		key = new Key;
		key = _item.key;
	}
}

template<class Key, class Data>
inline TItem<Key, Data>::~TItem()
{
	if (data != nullptr)
	{
		delete data;
		data = nullptr;
	}
	if (key != nullptr)
	{
		delete key;
		key = nullptr;
	}
}

template<class Key, class Data>
inline Key* TItem<Key, Data>::getKey()
{
	return key;
}

template<class Key, class Data>
inline void TItem<Key, Data>::setKey(Key* k)
{
	if (k != nullptr)
		key = k;
}

template<class Key, class Data>
inline Data* TItem<Key, Data>::getData()
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
inline bool TItem<Key, Data>::operator<(const TItem<Key, Data>& p)
{
	return *key < *p.key;
}

template<class Key, class Data>
inline bool TItem<Key, Data>::operator>(const TItem<Key, Data>& p)
{
	return *key > *p.key;
}

template<class Key, class Data>
inline bool TItem<Key, Data>::operator !=(const TItem<Key, Data>& p)
{
	return(!(*this) == p);
}

template<class Key, class Data>
inline bool TItem<Key, Data>::operator ==(const TItem<Key, Data>& p)
{
	if (this == &_item) return true;
	else
		if (*key != *(_item.key)) return false;
		else
			return true;
}