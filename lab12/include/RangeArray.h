#pragma once
#include<iostream>
#include"PairOfNumbers.h"
using namespace std;
template<typename T2>
class RangeArray
{
public:
  template<typename T1>
  RangeArray(PairOfNumbers<T1,T2> p)
  {
    r=p.second-p.first;
    T=new T2[r];
  }
  RangeArray(const RangeArray<T2>& a)
  {
    r=a.r;
    T=new T2[r];
    for (int i=0;i<r;i++)
    {
      T[i]=a.T[i];
    }
  }
  int Size() const
  {
    return r;
  }
  T2& operator[](int i)
  {
    return T[i+2];
  }
  ~RangeArray()
  {
    delete [] T;
  }
  T2 At(int i)
  {
    return T[i+2];
  }
private:
  T2 * T;
  int r;
};