#pragma once

class TMonom
{
protected:
  double K;
  int* A;
  int N;
public:
  TMonom(int N = 0);
  TMonom(double k_, int* A_, int N_);
  TMonom(const TMonom& a);
  TMonom(TMonom&& a);

  ~TMonom();

  void SetN(int N_);
  void SetK(double K_);
  void SetA(int* A_);

  double GetK();
  int GetN();
  int* GetA();

  int& operator[](const int i);

  bool operator > (const TMonom& a);
  bool operator < (const TMonom& a);
  bool operator == (const TMonom& a);

  TMonom& operator = (const TMonom& a);
  TMonom& operator = (TMonom&& a)noexcept;
};