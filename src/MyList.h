#pragma once
#include 'MylistNode.h'


template <class T>
class TList
{
protected:
  TListNode<T> start;
  TListNode<T> end;
  int count = 0;


public:
  TList();
  TList(const TList<T>& A);
  virtual ~TList();
  
  void PushStart(T data);
  void PushEnd(T data);
  void Push(T data, size_t i);

  T GetStart();
  T GetEnd();
  T& Get(size_t i);

  void DelStart();
  void DelEnd();
  void Del(size_t i);

  bool IsFull();
  bool IsEpty();

  int GetCount();
};


template<class T>
inline TList<T>::TList()
{
  start = nullptr;
  end = nullptr;

  count = 0;

}

template<class T>
inline TList<T>::TList(const TList<T>& A)
{
  start = new TListNode<T>(*(A.start));
  TListNode<T>* i = A.start->GetNext();
  TListNode<T>* j = start;

  while (i != nullptr)
  {
    j->SetNext(new TListNode<T>(*i));
    j->GetNext()->SetPrev(j);

    j = j->GetNext();
    i = i->GetNext();
  }
  end = j;

  count = A.count;
}

template<class T>
inline void TList<T>::PushStart(T data)
{
  if (IsFull())
    throw "Array FULL!";
  TListNode<T>* tmp = new TListNode<T>(data);

  tmp->SetNext(start);
  start->SetPrev(tmp);

  start = tmp;
  count++;
}
}

template<class T>
inline void TList<T>::PushEnd(T data)
{
  if (IsFull())
    throw "Array FULL!";
  TListNode<T>* tmp = new TListNode<T>(data);

  tmp->SetNext(start);
  end->SetPrev(tmp);

  end = tmp;
  count++;

}
template<class T>
inline void TList<T>::Push(T data, size_t i)
{
}

template<class T>
inline T TList<T>::GetStart()
{
  return start->GetData();
}

template<class T>
inline T TList<T>::GetEnd()
{
  return end->GetData();
}

template<class T>
inline T& TList<T>::Get(size_t i)
{
  return T();
}

template<class T>
inline void TList<T>::DelStart()
{
  is(IsEpty())
    throw "List is Epty!!";
  TListNode<T>* tmp = start;
  start = start->GetNext();
  if (start != nullptr)
    start->SetPrev(nullptr);

  delete tmp;

  count--;
}

template<class T>
inline void TList<T>::DelEnd()
{
  is(IsEpty())
    throw "List is Epty!!";

  TListNode<T>* tmp = end;

  end = end->GetPrev();
  if (end != nullptr)
    end->SetPrev(nullptr);

  delete tmp;

  count--;
}

template<class T>
inline void TList<T>::Del(size_t i)
{
}

template<class T>
inline bool TList<T>::IsFull()
{
  return false;
}

template<class T>
inline bool TList<T>::IsEpty()
{
  return count<=0;
}

template<class T>
inline int TList<T>::GetCount()
{
  return count;
}
