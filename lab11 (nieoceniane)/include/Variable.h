#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class VariableBase
{
public:
  virtual void Print() const=0;
  virtual ~VariableBase() {}
protected:
  string _nazwa;
};

template <typename T>
class Variable : public VariableBase 
{
public:
  Variable<T>(string n, T l) : _liczba(l){_nazwa=n;}
  void wyswietl() const
  {
    cout<<_nazwa<<": "<<_liczba;
  }
  virtual void Print() const override
  {
    wyswietl();
    cout<<endl;
  }
  void SetValue(const T l)
  {
    _liczba=l;
  }
protected:
  T _liczba;
};
typedef Variable<double> VariableDouble;
typedef Variable<float> VariableFloat;
typedef Variable<int> VariableInt;
typedef Variable<char> VariableChar;
typedef Variable<bool> VariableBool;

class ArrayOfVariables
{
public:
  ArrayOfVariables(const unsigned int n) : r(n){}
  template <typename T>
  Variable<T> *CreateAndAdd(string n, const T l)
  {
    Variable<T> *nV= new Variable<T>(n,l);
    V.push_back(nV);
    return nV;
  }
  void Print() const
  {
    for(unsigned i=0;i<V.size();i++)
    {
      V[i]->Print();
    }
  }
  ~ArrayOfVariables()
  {
    for(unsigned i=0;i<V.size();i++)
    {
      delete V[i];
    }
  }
private:
  const int r;
  vector<VariableBase *> V;
};

template <typename T>
class VariableWithUnits : public Variable<T>
{
public:
  VariableWithUnits<T>(string n, T l, string jed) :Variable<T>(n,l), _jed(jed) {}
  virtual void Print() const override
  {
    Variable<T>::wyswietl();
    cout<<" ["<<_jed<<"]"<<endl;
  }
private:
  string _jed;
};