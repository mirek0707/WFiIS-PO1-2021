#pragma once
#include<iostream>
#include<cstring>
using namespace std;
class FancyText
{
  public:
    FancyText()=default;
    FancyText(const char * t);
    FancyText(FancyText&& other);
    ~FancyText();
    void operator +=(const char * t);
    void operator +=(FancyText* other); 
    void operator +=(FancyText&& other);
    void operator = (FancyText&& other); 
    int size() const;
    int fragments() const;
    const FancyText& fragment(int i) const;
    const char* str() const;
    friend std::ostream &operator<< (std::ostream &s, const FancyText& T);
    

  private:
    char * _text=nullptr;
    FancyText * _next=nullptr;
    int _rozmiar=0;

};
std::ostream &operator<< (std::ostream &s, const FancyText& T);