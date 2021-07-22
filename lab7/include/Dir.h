#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Object.h"
using namespace std;
class Dir : public Object
{
  public:
    Dir(const std::string n):Object(n), rozmiar(0) {}
    void operator+=(Object * o)
    {
      rozmiar++;
      V.push_back(o);
    }
    ~Dir()
    {
      std::cout << "Deletig Dir: " << _nazwa << std::endl;
      for (auto &i : V) 
      {
        if (i) 
        {
          cout<<"About to delete: "<<i->nazwa()<<endl;
          delete i;
          i=nullptr;
        }
      }
    }
    void print (std::ostream &s, int spacje) const override
    {
      for (int i=0;i<spacje;i++)
      {
        s<<" ";
      }
      s<<nazwa()<<" (DIR)"<<endl;
      for (int i=0;i<rozmiar;i++)
      {
        (V[i])->print(s, spacje+2);
      }
    }
    Dir * findDir(const std::string n)
    {
      for(auto* i:V)
      {
        if (i->nazwa()==n)
        {
          return dynamic_cast<Dir*>(i);
        }
        Dir* wynik = dynamic_cast<Dir*>(i)->findDir(n);
        if (wynik != nullptr) 
        {
         return wynik;
        }
      }
      return nullptr;
    }
    Object * get(const std::string n) const
    {
      for(auto* i:V)
      {
        if (i->nazwa()==n)
        {
          return i;
        }
        Dir* temp;
        if ((temp = dynamic_cast<Dir*>(i))) 
        {
          Object *wynik = temp->get(n);
          if (wynik != nullptr)
            return wynik;
        }
      }
      return nullptr;
    }
    void add(Dir *d)
    {
      rozmiar++;
      V.push_back((Object*)d);
    }
    friend std::ostream& operator<<(std::ostream &s, const Dir & d);
  private:
    std::vector<Object *> V;
    int rozmiar;
};
std::ostream& operator<<(std::ostream &s, const Dir & d)
{
  d.print(s, 0);
  return s;
}