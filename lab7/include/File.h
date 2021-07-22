#pragma once
#include<iostream>
#include<string>
#include "Object.h"
using namespace std;
class File : public Object
{
  public:
    File(const std::string nazwa) : Object(nazwa){}
    void print (std::ostream &s, int spacje) const override
    {
      for (int i=0;i<spacje;i++)
      {
        s<<" ";
      }
      s<<nazwa()<<" (FILE)"<<endl;
    }
    ~File(){}    
    
};