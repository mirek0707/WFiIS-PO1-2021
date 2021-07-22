#include "ZlozenieFunkcji.h"
void ZlozenieFunkcji::insert(std::function<double(double)> x)
{
  V.push_back(x);
}
double ZlozenieFunkcji::wynik(double x)
{
  int i;
  wyniki.clear();
  wyniki.reserve(V.size());
  wyniki[0]=V[0](x);
  for (i=1;i<V.size();i++)
  {
    wyniki[i]=V[i](wyniki[i-1]);
  }
  return wyniki[i-1];
}
double ZlozenieFunkcji::operator[](double x)
{
  return wyniki[x];
}
ZlozenieFunkcji::~ZlozenieFunkcji()
{
  V.clear();
  wyniki.clear();
}