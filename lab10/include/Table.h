#pragma once
#include "Data.h"
using namespace std;
/*klasa Table - klasa przechowujaca tablice dni*/
class Table
{
public:
  /*przeciazenie operatora +=, pozwala na dodanie dnia do tablicy, oblicza takze wartosc minimalna dla dlugosci tablic, ktore sa przechowywane w Data
  @param d - dany dzien*/
  void operator+= (const Data& d)
  {
    _D.push_back(d);
    if (d.dl()<minRow)
    {
      minRow=d.dl();
    }
  }
  /*liczba przechowujaca minimalna dlugosc tablic w Data, poczatkowo wartosc wynosi 10*/
  int minRow=10;
  /*funkcja umozliwiajaca wyswietlanie*/
  void print() const
  {
    for_each(_D.begin(), _D.end(), [](Data n){n.print(); });
  }
  /*funkcja sortujaca po danej kolumnie
  @param k - numer kolumny
  @return *this - tablica po posortowaniu*/
  Table sort(int k)
  {
    if (k>(int)_D.size()-1)
    {
      cout<<"Indeks "<<k<<" nieprawidlowy!"<<endl;
      return *this;
    }
    std::sort(_D.begin(), _D.end(), [k](Data d1,Data d2) {return d1[k]<d2[k];});
    return *this;
  }
  /*funkcja sortujaca w sposob okreslony przez przekazywana funkcje
  @param s - funkcja okreslajaca rodzaj sortowania
  @return *this - tablica po posortowaniu*/
  Table& sortBy(std::function<bool(const Data& d1, const Data& d2)>s)
  {
    std::sort(_D.begin(), _D.end(),s);
    return *this;
  }
private:
  /*@field _D - tablica dni*/
  vector<Data> _D;
};