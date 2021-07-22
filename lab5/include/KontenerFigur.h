#pragma once
#include "Figura.h"
class KontenerFigur
{
  public:
    KontenerFigur()=default;
    KontenerFigur operator+=(Figura* w)
    {
      K.push_back(w);
      return *this;
    }
    friend std::ostream& operator<<(std::ostream &s, KontenerFigur k);
  private:
    vector<Figura*> K;
};
std::ostream& operator<<(std::ostream &s, KontenerFigur k)
{
  for (unsigned i=0;i<k.K.size();i++) 
  {
    s << "Figura " << (k.K[i])->nazwa()<<":"<<endl;
    (k.K[i])->wierzcholek(s);
    s<<endl;
  }
  return s;
}