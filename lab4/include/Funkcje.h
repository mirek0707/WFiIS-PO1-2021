#pragma once
#include<iostream>
#include<cmath>
#include<functional>
using namespace std;
/*klasa Sinus - klasa zawierajaca metody dla sinusa*/
class Sinus
{
  public:
    /*Sinus() - konstruktor domyslny bezparametrowy*/
    Sinus()=default;
    /*konstruktor dla dwoch parametrow
    @param a - parametr okreslajacy wspolczynnik a sinusa
    @param b - parametr okreslajacy wspolczynnik b sinusa*/
    Sinus(double a, double b);
    /*double operator() - przeciazenie operatora ()
    @param x - liczba, z ktorej chcemy policzyc wartosc funkcji
    @return wartosc funkcji*/
    double operator() (double x) const;
  private:
    /*field _a - parametr okreslajacy wspolczynnik a sinusa*/
    double _a=0.0;
    /*field _b - parametr okreslajacy wspolczynnik b sinusa*/
    double _b=0.0;

};
/*klasa PierwiastekKwadratowy - klasa zawierajaca metody dla pierwiastka*/
class PierwiastekKwadratowy
{
  public:
    /*PierwiastekKwadratowy() - konstruktor domyslny bezparametrowy*/
    PierwiastekKwadratowy()=default;
    /*double operator() - przeciazenie operatora ()
    @param x - liczba, z ktorej chcemy policzyc wartosc funkcji
    @return wartosc funkcji*/
    double operator() (double x) const;
};
/*klasa Sinus - klasa zawierajaca metody dla funkcji liniowej*/
class Liniowa
{
  public:
    /*Liniowa() - konstruktor domyslny bezparametrowy*/
    Liniowa()=default;
    /*konstruktor dla dwoch parametrow
    @param a - parametr okreslajacy wspolczynnik a funkcji liniowej
    @param b - parametr okreslajacy wspolczynnik b funkcji liniowej*/
    Liniowa(double a, double b);
    /*double operator() - przeciazenie operatora ()
    @param x - liczba, z ktorej chcemy policzyc wartosc funkcji
    @return wartosc funkcji*/
    double operator() (double x) const;
  private:
   /*field _a - parametr okreslajacy wspolczynnik a funkcji liniowej*/
   double _a=0.0;
   /*field _a - parametr okreslajacy wspolczynnik a funkcji liniowej*/
    double _b=0.0;
};