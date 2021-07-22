#pragma once
#include<iostream>
#include <initializer_list>
#include "MyNode.h"
using namespace std;
class MyList
{
  public:
    MyList();
    MyList(int l);
    MyList(initializer_list<int> list);
    MyList(const MyList& other);
    MyList(MyList&& other);
    MyList(int (*f)(MyNode*), int s);
    ~MyList();

    bool empty() const;
    int size() const;
    void print() const;
    void add (int l);
    void clear();
  private:
    int rozmiar=0;
    MyNode * head=NULL;
    MyNode * tail=NULL;

};