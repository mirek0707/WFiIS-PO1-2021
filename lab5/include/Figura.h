#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "Wierzcholek.h"
using namespace std;
class Figura
{
  public:
    Figura(const char *z)
    {
      _nazwa=z;
      cout<<"Jestem nową figurą "<<_nazwa<<endl;
    }
    Figura& operator+=(const Wierzcholek &w)
    {
      V.push_back(w);
      return *this;
    }
    Figura& dodajW(const Wierzcholek &w)
    {
      V.push_back(w);
      return *this;
    }
    bool operator== (Figura& f)
    {
      if (V.size()!=f.V.size())
      {
        return 0;
      }
      else
      {
        for (int i=0;i<(int)V.size();i++)
        {
          if (V[i]!=f.V[i])
          {
            return 0;
          }
        }
      }
      return 1;
    }
    string nazwa() const
    {
      return _nazwa;
    }
    void wierzcholek(std::ostream &s) const
    {
      for (unsigned i=0;i<V.size();i++)
      {
        s<<V[i];
      }
    }
  protected:
    string _nazwa;
    std::vector<Wierzcholek> V;
};