#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class V
{
  public:
    V()=default;
    V(int r);
    V(const V& other);
    V (V && other);
    double &at(int p) const;
    void print(const char * t) const;
    static double dot (const V& v1, const V& v2);
    operator double() const;
    double norm() const;
    static V sum (const V v1, const int n);
    static V sum (const V v1, const V v2);
   ~V();
  private:
    double *_w=nullptr;
    int _r=0;

};