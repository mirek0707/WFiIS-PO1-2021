#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*klasa QuantityBase - klasa, po ktorej dziedziczy klasa Quantity, przechowuje nazwe*/
class QuantityBase
{
public:
  /*Funcja wirtualna umozliwiajaca wyswietlanie*/
  virtual void Print() const= 0;
  /*Wirtualny destruktor*/
  virtual ~QuantityBase() {}
protected:
  /*@field _nazwa - nazwa danej zmiennej*/
  string _nazwa;
};
/*klasa Quantity - klasa przechowujaca liczbe dowolnego typu*/
template<typename T>
class Quantity : public QuantityBase
{
public:
  /*konstruktor*/
  Quantity<T>(const string n, const T l):_liczba(l) {_nazwa=n;}
  /*Funkcja pomagajaca w wyswietlaniu*/
  void PrintA() const
  {
    cout<<_nazwa<<": "<<_liczba;
  }
  /*Funkcja umozliwiajaca wyswietlanie*/
  virtual void Print() const override
  {
    PrintA();
    cout<<endl;
  }
  /*Funkcja Zmieniajaca wartosc przechowywanej liczby
  @param l - nowa wartosc liczby*/
  void SetValue(const T l)
  {
    _liczba=l;
  }
private:
  /*@field _liczba - wartosc liczby*/
  T _liczba;
};

typedef Quantity<double> QuantityDouble;
typedef Quantity<float> QuantityFloat;
typedef Quantity<int> QuantityInt;
typedef Quantity<char> QuantityChar;
typedef Quantity<bool> QuantityBool;

/*klasa ArrayOfQuantities - klasa przechowujaca tablice typu Quantity*/
class ArrayOfQuantities
{
public:
  /*konstruktor*/
  ArrayOfQuantities(const int r): _r(r){}
  /*Funkcja dodajaca nowy element do tablicy(vector)
  @param n - nazwa elementu
  @param l - wartosc elementu
  @return q - nowy element*/
  template<typename T>
  Quantity<T> * CreateAndAdd(const string n, const T l)
  {
    Quantity<T> * q= new Quantity<T>(n,l);
    if(_r>=_V.size())
      _V.push_back(q);
    return q;
  }
  /*Funkcja umozliwiajaca wyswietlanie*/
  void Print() const
  {
    for (unsigned i=0; i<_V.size(); i++)
    {
      (_V[i])->Print();
    }
  }
  /*destruktor*/
  ~ArrayOfQuantities()
  {
    for (unsigned i=0; i<_V.size(); i++)
    {
      delete (_V[i]);
    }
    _V.clear();
  }
private:
  /*@field _r- wielkosc tablicy*/
  int _r;
  /*@field _V - vector przechowujacy QuantityBase*/
  vector<QuantityBase *> _V;

};

/*klasa QuantityWithUnits - klasa przechowujaca nazwe jednostki, dziedziczy po Quantity*/
template<typename T>
class QuantityWithUnits : public Quantity<T>
{
public:
  /*konstruktor*/
  QuantityWithUnits<T>(const string n, const T l, const string jed) : Quantity<T>(n,l), _jed(jed){}
  /*Funkcja umozliwiajaca wyswietlanie*/
  virtual void Print() const override
  {
    Quantity<T>::PrintA();
    cout<<" ["<<_jed<<"]"<<endl;
  } 
private:
  /*@field _jed- nazwa jednostki*/
  string _jed;
};