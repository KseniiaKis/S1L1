#pragma once
#include"..\src\MapLib\Map.h"
#include "..\src\TItemLib\TItem.h"
template<class Key, class Data>
class THMap
{
	size_t size;
	size_t count;
	TItem<Key, Data>* A;
	size_t HFun(const Key& _key);
public:
	THMap(size_t _size = 100);
	THMap(const THMap<Key, Data>& _HMap);
	~THMap();
	Data& operator [](const Key& _key);
	void Add(const Key& _key, const Data& _data);
	void Delete(const Key& _key);
};

template<class Key, class Data>
inline size_t THMap<Key, Data>::HFun(const Key& _key)
{
	size_t hash_value = std::hash<Key>()(_key);
	return hash_value;
}

template<class Key, class Data>
inline THMap<Key, Data>::THMap(size_t _size)
{
	size = _size;
	A = new TItem<Key, Data>[size];
	count = 0;
}

template<class Key, class Data>
inline THMap<Key, Data>::THMap(const THMap<Key, Data>& _HMap)
{
}

template<class Key, class Data>
inline THMap<Key, Data>::~THMap()
{
	if (A != nullptr)
	{
		delete[] A;
		A = nullptr;
	}
}

template<class Key, class Data>
inline Data& THMap<Key, Data>::operator[](const Key& _key)
{
	size_t indx = HFun(_key);
	indx = indx % size;
	if (*(A[indx].GetKey()) == _key)
	{
		return A[indx].Get_A();
	}
	else if (*(A[(HFun(_key) + 1) % size].GetKey()) == _key)
	{
		return A[(HFun(_key) + 1) % size].Get_A();
	}
}

template<class Key, class Data>
inline void THMap<Key, Data>::Add(const Key& _key, const Data& _data)
{
	size_t indx = HFun(_key);
	indx = indx % size;
	if (A[indx].GetKey() == nullptr)
	{
		A[indx].SetKey(_key);
		A[indx].SetData(_data);
		return;
	}
	indx = (HFun(_key) + 1) % size;
	A[indx].SetKey(_key);
	A[indx].SetData(_data);
}

template<class Key, class Data>
inline void THMap<Key, Data>::Delete(const Key& _key)
{
	size_t indx = HFun(_key);
	indx = indx % size;
	if (A[indx].GetKey() == _key)
	{
		A[indx].BadDelete();
	}
	else if (A[(HFun(_key) + 1) % size] == _key)
	{
		A[(HFun(_key) + 1) % size].BadDelete();
	}
}
