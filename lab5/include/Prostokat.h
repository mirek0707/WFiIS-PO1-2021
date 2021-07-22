#pragma once
#include "Figura.h"
#include<cmath>
using namespace std;
class Prostokat : public Figura
{
  public:
    Prostokat(const char * z) : Figura(z)
    {
      cout<<"Tak naprawdę jestem prostokątem."<<endl;
    }
    
    string nazwa() const
    {
      return _nazwa;
    }
    double pole() const
    {
      double a= (V[1]).x()-(V[0]).x();
      double b= (V[2]).y()-(V[1]).y();
      return a*b; 
    }

};

