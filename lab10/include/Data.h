#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
#include<functional>
#include<numeric>
#include"Sum.h"
using namespace std;
/*klasa Data - klasa przechowujaca informacje na temat danego dnia*/
class Data
{
public:
  /*konstruktor
  @param n - nazwa dnia
  @param V - tablica liczb*/
  Data(string n, vector<double> V) : _n(n), _V(V) {}
  /*funkcja umozliwiajaca wyswietlanie*/
  void print() const
  {
    cout<<_n<<": ";
    for_each(_V.begin(), _V.end(), [](double n){cout<<setw(6)<<n; });
    cout<<endl;
  }
  /*funkcja zwracajaca dlugosc tablicy
  @return dlugosc tablicy*/
  int dl() const
  {
    return _V.size();
  }
  /*przeciazenie operatora []
  @param i - numer komorki
  @return wartosc komorki w tablicy*/
  double operator[] (int i) const
  {
    return _V[i];
  }
  /*funkcja przyjazna pozwalajaca policzyc sume w tabeli*/
  friend Sum sumData(const Data &d);
private:
  /*@field _n - nazwa dnia*/
  string _n;
  /*@field _V - tablica liczb*/
  vector<double> _V;
};
/*funkcja przyjazna pozwalajaca policzyc sume w tabeli
@param Data - dany dzien
@return suma liczb z danego dnia*/
Sum sumData(const Data &d)
{
  return Sum(accumulate(d._V.begin(), d._V.end(),0.0));
}