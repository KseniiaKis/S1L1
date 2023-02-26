#pragma once
#include "Monom.h"
#include "MyList.h"
class TPolynom : public TList<TMonom>
{
protected:
  int N;
  void Delete();
public:
  TPolynom(int N_;
  TPolynom(const TPolynom& a);
  ~TPolynom(); //достаточно деструктора списка

  int GetN();

  TPolynom operator +(const TPolynom& a);
  TPolynom operator -(const TPolynom& a);
  TPolynom operator *(const TPolynom& a);
  TPolynom& operator =(const TPolynom& a);
  TPolynom& operator +=(const TMonom a);//чтобы могли добавлять моном
  TMonom& operator [] (const size_t i);//оператор индексации
};
