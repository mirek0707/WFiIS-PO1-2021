#include "FancyText.h"
FancyText::FancyText(const char * t)
{
   _rozmiar=strlen(t);
  _text=new char [_rozmiar];
  strcpy(_text, t);
  _next=nullptr;
}
FancyText::FancyText(FancyText&& other)
{
  _next = std::__exchange(other._next, nullptr);
  _text = std::__exchange(other._text, nullptr);
  _rozmiar = std::__exchange(other._rozmiar, 0);
}
FancyText::~FancyText()
{
  if (_text != nullptr) 
  {
    delete[] _text;
    delete _next;
  }
}
void FancyText::operator +=(const char * t)
{
  FancyText *p=this;
  while (p->_next)
  {
    p=p->_next;
  }
  p->_next=new FancyText(t);
}
void FancyText::operator+=(FancyText* other) 
{
  if(_next == nullptr) 
    _next = other;
  else 
    *_next += other;
}

void FancyText::operator+=(FancyText&& other)
{
  FancyText* t=new FancyText(std::move(other));
  *this += t;
}

void FancyText::operator= (FancyText&& other) 
{
    _next = std::__exchange(other._next, nullptr);
    _text = std::__exchange(other._text, nullptr);
    _rozmiar = std::__exchange(other._rozmiar, 0);
}
int FancyText::size() const
{
  int suma=0;
  suma+=_rozmiar;
  FancyText *p=_next;
  while (p)
  {
    suma+=p->_rozmiar;
    p=p->_next;
  }
  return suma;
}
int FancyText::fragments() const
{
  int suma=1;
  FancyText *p=_next;
  while (p)
  {
    suma+=1;
    p=p->_next;
  }
  return suma;
}
const FancyText& FancyText::fragment(int i) const 
{
    const FancyText* current=this;
    while (i>0)
    {
      current = current->_next;
      i--;
    }
    return *current;
}

const char* FancyText::FancyText::str() const 
{
    return _text;
}
std::ostream& operator<< (std::ostream &s, const FancyText& T)
{
  if (T._text != nullptr) 
  {
    s<<T._text;
  }
  FancyText *p=T._next;
  while (p)
  {
    s<<p->_text;
    p=p->_next;
  }
  return s;
}