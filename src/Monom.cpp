#include "Monom.h"

TMonom::TMonom(int N = 0)
{
  if (N == 0)
    A = nullptr;
  K = 0;

  if (N < 0)
    throw "Error N!";
  A = new int[N];
  for (size_t i = 0; i < N; i++)
    A[i] = 0;

}

TMonom::TMonom(double k_, int* A_, int N_)
{
  K = k_;

  if (N < 0)
    throw "Error N!";
  if (N == 0)
    A = nullptr;
  else
    A = new int[N];

  for (size_t i = 0; i < N; i++)
    A[i] = A_[i];

}

TMonom::TMonom(const TMonom& a)
{
  K = a.K;
  N = a.N;
  if (N == 0)
    A = nullptr;
  else
    A = new int[N];

  for (size_t i = 0; i < N; i++)
    A[i] = a.A[i];
}

TMonom::TMonom(TMonom&& a)
{
  K = a.K;
  N = a.N;
  A = a.A;

  a.A = nullptr;
}

TMonom::~TMonom()
{
  if (A != nullptr)
    delete[] A;

  A = nullptr;
}

void TMonom::SetN(int N_)
{
  if (A != nullptr)
    delete[] A;
  if (N == 0)
    A = nullptr;
  else
    A = new int[N];
  for (size_t i = 0; i < N; i++)
    A[i] = 0;
}

void TMonom::SetK(double K_)
{
  K = K_;
}

void TMonom::SetA(int* A_)
{
  for (size_t i = 0; i < N; i++)
    A[i] = A_[i];
}

double TMonom::GetK()
{
  return K;
}

int TMonom::GetN()
{
  return N;
}

int* TMonom::GetA()
{
  return A;
}

int& TMonom::operator[](const int i)
{
  if (i < 0 || i >= N)
    trhow "Error index!";
  return A[i];

}

bool TMonom::operator>(const TMonom& a)
{
  if(N!=a.N)
    throw "Error N!"
    for (size_t i = 0; i < N; i++)
    {
      if (A[i] == a.A[i])
        continue;
      else if (A[i] > a.A[i])
        return true;
      else
        return false;
    }
  return false;

}

bool TMonom::operator<(const TMonom& a)
{
  if (N != a.N)
    throw "Error N!"
    for (size_t i = 0; i < N; i++)
    {
      if (A[i] == a.A[i])
        continue;
      else if (A[i] > a.A[i])
        return false;
      else
        return true;
    }
  return false;

}

bool TMonom::operator==(const TMonom& a)
{
  if (N != a.N)
    throw "Error N!"
    for (size_t i = 0; i < N; i++)
    {
      if (A[i] == a.A[i])
        continue;
      else
        return false;
    }
  return true;

}

TMonom& TMonom::operator=(const TMonom& a)
{
  if (this == &a)
    return *this;


  if (N != a.N)
  {
    if (A != nullptr)
      delete[] A;
    if (N == 0)
      A = nullptr;
    else
      A = new int[N];
  }

  K = a.K;
  N = a.N;

  for (size_t i = 0; i < N; i++)
    A[i] = a.A[i];
  return this*;
}

TMonom& TMonom::operator=(TMonom&& a) noexcept
{
  K = a.K;
  N = a.N;
  A = a.A;

  a.A = nullptr;
  return this*;
}
