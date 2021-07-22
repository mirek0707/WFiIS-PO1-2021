#pragma once
#include<iostream>
#include "Value.h"
using namespace std;
/*klasa Primitive - klasa zawierajaca liczbe */
class Primitive : public Value
{
  public:
  /*Konstruktor domyslny*/
    Primitive()=default;
    /*Konstruktor*/
    Primitive(const double l)
    {
      _liczba=l;
    }
    /*GetValue - funkcja zwracacajaca liczbe (getter)
    @return wartosc typu double*/
    double GetValue() const
    {
      return _liczba;
    }
    /*Print - funkcja sluzaca do wyswietlania liczby*/
    void Print() const
    {
      cout<<_liczba;
    }
    /*Set - funkcja sluzaca do zmienienia wartosci liczby*/
    void Set (const double l)
    {
       _liczba=l;
    }
    /*PrintWithValue - funkcja sluzaca do wyswietlania wyniku dzialania*/
    void PrintWithValue() const {};
  private:
    /*@param _liczba - liczba przechowywana w klasie*/
    double _liczba;
};