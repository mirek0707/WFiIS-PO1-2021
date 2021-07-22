#pragma once
#include<iostream>
#include<string>
using namespace std;
class Object
{
  public:
    Object(const std::string n): _nazwa(n){}
    std::string nazwa() const
    {
      return _nazwa;
    }
    virtual void print (std::ostream &s, int spacje) const=0;
    virtual ~Object(){}
    friend std::ostream& operator<<(std::ostream &s, const Object & o);
  protected:
    std::string _nazwa;
};
std::ostream& operator<<(std::ostream &s, const Object & o)
{
  o.print(s, 0);
  return s;
}