#pragma once
#include<iostream>
using namespace std;
/*klasa Value - klasa po ktorej dziedzicza pozostale klasy*/
class Value
{
  public:
    /*PrintWithValue - funkcja wirtualna sluzaca do wyswietlania wyniku dzialania*/
    virtual void PrintWithValue() const=0;
    /*Print - funkcja wirtualna sluzaca do wyswietlania czesci dzialania*/
    virtual void Print() const=0;
    /*GetValue - funkcja wirtualna majaca zwracac wartosc (getter)
    @return wartosc typu double*/
    virtual double GetValue() const =0;
};