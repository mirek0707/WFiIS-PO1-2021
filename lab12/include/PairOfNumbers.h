#pragma once
#include<iostream>
using namespace std;
template<typename T1, typename T2>
class PairOfNumbers
{
public:
  T1& first;
  T2& second;
  PairOfNumbers(T1& f, T2& s) : first(f), second(s){}
  PairOfNumbers<T2, T1> Swapped()
  {
    return PairOfNumbers<T2, T1>(second, first);
  }
  void Print() const
  {
    cout<<"Print method: "<<first<<" "<<second<<endl;
  }
  void Add(int n)
  {
    first+=n;
    second+=n;
  }
  void Scale(int n)
  {
    first*=n;
    second*=n;
  }
  void Info()
  {
    cout<<"This is NON-const pair of numbers"<<endl;
  }
  void Info() const
  {
    cout<<"This is const pair of numbers"<<endl;
  }
};
