#pragma once
#include<iostream>
#include "Value.h"
using namespace std;
/*klasa Ratio - klasa implementujaca wynik dzielenia */
class Ratio : public Value
{
  public: 
    /*Konstruktor*/
    Ratio (Value & p1, Value & p2)
    {
      _a= &p1;
      _b= &p2;
    }
    /*GetValue - funkcja zwracacajaca wynik dzielenia (getter)
    @return wartosc typu double*/
    double GetValue() const
    {
      return _a->GetValue()/_b->GetValue();
    }
    /*Print - funkcja sluzaca do wyswietlania czesci dzialania*/
    void Print() const
    {
      cout<<"(";
      _a->Print();
      cout<<"/";
      _b->Print();
      cout<<")";
    }
    /*PrintWithValue - funkcja sluzaca do wyswietlania wyniku dzialania*/
    void PrintWithValue() const 
    {
      Print();
      cout<<" = "<<GetValue()<<endl;
    }
  private:
    /*@param _a - pierwszy argument dzialania*/
    Value *_a;
    /*@param _b - drugi argument dzialania*/
    Value *_b;
};