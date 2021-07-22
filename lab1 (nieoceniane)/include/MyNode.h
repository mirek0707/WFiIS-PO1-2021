#pragma once
#include<iostream>
using namespace std;
class MyNode
{
  public:
  	MyNode(int l);
 	MyNode * getnext() const;
 	void setnext(MyNode* n);
 	int val() const;
  private:
    int liczba;
    MyNode * next;
};
