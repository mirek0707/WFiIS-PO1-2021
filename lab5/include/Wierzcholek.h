#pragma once
#include<iostream>
using namespace std;
class Wierzcholek
{
  public:
    Wierzcholek(int x, int y)
    {
      _x=x;
      _y=y;
    }
    int x() const
    {
      return _x;
    }
    int y() const
    {
      return _y;
    }
    friend std::ostream& operator<<(std::ostream& s, const Wierzcholek w);
    bool operator!= (Wierzcholek& f)
    {
      if (_x!=f.x())
        return 1;
      else if (_y!=f.y())
        return 1;
      else
        return 0;
    }
  private:
    int _x;
    int _y;
};
std::ostream& operator<<(std::ostream &s, const Wierzcholek w)
    {
      s<<" ("<<w._x<<", "<<w._y<<")";
      return s;
    }
