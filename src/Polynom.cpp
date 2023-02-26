#include "Polynom.h"
#include"Polynom.h"

TPolynom::TPolynom(int N_
  {
    if (N < 0)
      throw "Error N!!"
      N = N_;
}

void TPolynom::Delete()
{
}

TPolynom::TPolynom(const TPolynom& a)
{
  N = a.N;
}

TPolynom::~TPolynom()
{
  return 
}

int TPolynom::GetN()
{
  return 0;
}

TPolynom TPolynom::operator+(const TPolynom& a)
{
  TPolynom res(N); 
  TListNode<TMonom>* i = start;
  TListNode<TMonom>* j = a.start;
  while (i != nullptr || j != nullptr)
  {
    if (i->GetData() == j->GetData())
    {
      TMonom tmp(i->GetData().GetK() + j->GetData().GetK(), i->GetData().GetA(), N)
        res.PushEnd(tmp);
      i = i->GetNext();
      j = j->GetNext();
    }
    else if (i->GetData() > j-> GetData())
    {
      res.PushEnd(i->GetData()); //должен вызваться конструктор копирования
      i = i->GetNext();
    }
    else
    {
      res.PushEnd(j->GetData());
      j = j->GetNext();
    }
  }
  if (i == nullptr)
  {
    while (j != nullptr)
    {
      res.PushEnd(j->GetData());
      j = j->GetNext();
    }
  }
  if (j == nullptr)
  {
    while (i != nullptr)
    {
      res.PushEnd(j->GetData());
      i = i->GetNext();
    }
  }

  return res;
}

TPolynom TPolynom::operator-(const TPolynom& a)
{
  TPolynom res(N);
  TListNode<TMonom>* i = start;
  TListNode<TMonom>* j = a.start;
  while (i != nullptr || j != nullptr)
  {
    double newK = i->GetData().GetK() - j->GetData().GetK();
    if (newK != 0)
    {
      if (i->GetData() == j->GetData())
      {
        TMonom tmp(i->GetData().GetK() - j->GetData().GetK(), i->GetData().GetA(), N)
          res.PushEnd(tmp);
        i = i->GetNext();
        j = j->GetNext();
      }
      else if (i->GetData() > j->GetData())
      {
        res.PushEnd(i->GetData()); //должен вызваться конструктор копирования
        i = i->GetNext();
      }
      else
      {
        res.PushEnd(j->GetData());
        j = j->GetNext();
      }
    }
    if (i == nullptr)
    {
      while (j != nullptr)
      {
        res.PushEnd(j->GetData());
        j = j->GetNext();
      }
    }
    if (j == nullptr)
    {
      while (i != nullptr)
      {
        res.PushEnd(j->GetData());
        i = i->GetNext();
      }
    }

    return res;
  }
}

TPolynom TPolynom::operator*(const TPolynom& a)
{
  TPolynom res(N);
  TListNode<TMonom>* i = start;
  TListNode<TMonom>* j = a.start;
  while (i != nullptr) 
  {
    while (j != nullptr)
    {
      int* newA = new int[N]; //складываем степени
      for (size_t k = 0; k < N; k++)
      {
        newA[k] = j->GetData()[k] + i->GetData()[k];
      }
      TMonom tmp(i->GetData().GetK() * j->GetData().GetK(), newA, N);
      delete[] newA;
      res += tmp;
    }
  }
  return res;
}

TPolynom& TPolynom::operator=(const TPolynom& a)
{
  if (this == &a)
    return *this;

  Delete();
  TList::TList(a);
}

TPolynom& TPolynom::operator+=(const TMonom a)
{
  TListNode<TMonom>* i = this->start;
  if (IsEpty())//проверка
    this->PushStart(a);
  
  TListNode<TMonom>* tmp = new TListNode<TMonom>(a);
  while (i != nullptr)
  {
    if (i->GetData() < a)
    {
      TListNode<TMonom>* p = i->GetPrev();
      if (p == nullptr)
        this->PushStart(a);
      tmp->SetNext(i);              //вставили новый элемент
      tmp->SetPrev(p);
      i->SetPrev(tmp);
      p->SetNext(tmp);
      return *this;
    }
      i = i->GetNext();
   }
  this->PushEnd(a); //вставка не произошла, необходимо вставить в конец, это добавление одиночного монома 

}

TMonom& TPolynom::operator[](const size_t i)
{
  return this->Get(i);
}
