#include "V.h"
using namespace std;
V::V(int r)
{
  _w=new double[r];
  _r=r;
  for (int i=0;i<r;i++)
  {
    _w[i]=0;
  }
}
double &V::at(int p) const
{
  return (_w[p]);
}
V::V(const V& other) 
{
  _r=other._r;
  _w=new double[_r];
  for (int i=0;i<_r;i++)
  {
    _w[i]=other._w[i];
  }
}
void V::print(const char * t) const
{
  cout<<t<<"(";
  int i;
  for (i=0;i<_r-1;i++)
  {
    cout<<_w[i]<<", ";
  }
  cout<<_w[i]<<")"<<endl;
}
double V::dot (const V& v1, const V& v2)
{
  if (v1._r==v2._r)
  {
    double suma=0.0;
    for (int i=0;i<v1._r;i++)
    {
      suma+=(v1._w[i])*(v2._w[i]);
    }
    return suma;
  }
  cout<<"Error, vectors of different dimensions!"<<endl;
  return 0.0;
}
V::operator double() const
{
  double suma=0.0;
  for (int i=0;i<_r;i++)
    {
      suma+=(_w[i])*(_w[i]);
    }
  suma=sqrt(suma);
  return suma;
}
double V::norm() const
{
  double suma=0.0;
  for (int i=0;i<_r;i++)
    {
      suma+=(_w[i])*(_w[i]);
    }
  suma=sqrt(suma);
  return suma;
}
V V::sum (const V v1, const V v2)
{
  V v;
  v._r=v1._r;
  v._w=new double[v._r];
  for (int i=0;i<v._r;i++)
  {
    v._w[i]=(v1._w[i])+(v2._w[i]);
  }
  return v;
}
V::V (V && other)
{
  _r=std::__exchange (other._r, 0.0);
  _w=std::__exchange (other._w, nullptr);
}
V V::sum (const V v1, const int n)
{
  V v;
  v._r=v1._r;
  v._w=new double[v._r];
  for (int i=0;i<v._r;i++)
  {
    v._w[i]=(v1._w[i])+n;
  }
  return v;
}
V::~V()
{
  delete [] _w;
  _r=0;
}