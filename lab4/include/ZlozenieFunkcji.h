#pragma once
#include<iostream>
#include<cmath>
#include<vector>

#include"Funkcje.h"
using namespace std;
/*klasa ZlozenieFunkcji - klasa zawierajaca metody pozwalajace tworzyc zlozenia funkcji*/
class ZlozenieFunkcji 
{
  public:
    /*ZlozenieFunkcji() - konstruktor domyslny bezparametrowy*/
    ZlozenieFunkcji()=default;
    /*funkcja insert - umieszcza funkcje w std::vector
    @param x - vector */
    void insert(std::function<double(double)> x);
    /*funkcja wynik - funkcja zwracajaca wynik zlozenia funkcji
    @param x - liczba, dla ktorej chcemy obliczyc wynik zlozenia funkcji
    @return wynik zlozenia funkcji*/
    double wynik(double x);
    /*double operator[] - przeciazenie operatora []
    @param x - liczba, z ktorej chcemy policzyc wartosc posredniego zlozenia funkcji
    @return wartosc posredniego zlozenia funkcji*/
    double operator[](double x);
    /*destruktor*/
    ~ZlozenieFunkcji();
  private:
    /*field V - wektor przechowujacy funkcje*/
    std::vector<std::function<double(double)> > V;
    /*field wyniki - wektor przechowujacy wyniki zlozen funkcji*/
    std::vector<double> wyniki;
};