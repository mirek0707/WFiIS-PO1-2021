#include "MyList.h"
MyList::MyList()
{
  rozmiar=0;
  head=NULL;
  tail=NULL;
  cout<<"KONST: Domyslny\n";
}
MyList::MyList(int l): MyList()
{
  cout<<"KONST: Jednoargumentowy"<<endl; 
  for (int i=0;i<l;i++)
  {
    add(i);
  } 
}
MyList::MyList(initializer_list<int> list)
{
  cout<<"KONST: std::initializer_list"<<endl;

  initializer_list<int>::iterator next = list.begin();
  while(next != list.end())
  {
    add(*next);
    next++;
  }
}
MyList::MyList(const MyList& other): MyList()
{
  cout<<"KONST: kopiujacy"<<endl;
  MyNode* h=other.head;
  while(h!=NULL)
  {
    add(h->val());
    h=h->getnext();
  }
}
MyList::MyList(MyList&& other)
: rozmiar(std::__exchange(other.rozmiar, 0))
, head(std::__exchange(other.head, nullptr))
, tail(std::__exchange(other.tail, nullptr))

{
  std::cout<<"KONST: przenoszacy"<<std::endl;
}

MyList::MyList(int (*f)(MyNode*), int s)
{
  cout<<"KONST: funkcja generujaca"<<endl;
  for (int i=0;i<s;i++)
  {
    add(f(tail));
  }
}
void MyList::clear()
{
  MyNode *n=head;
  while(n!=NULL)
  {
    MyNode* temp=n->getnext();
    delete n;
    n=temp;
  }
  head=NULL;
  tail=NULL;
  rozmiar=0;
}
void MyList::add(int l)
{
  if (tail==NULL)
  {
    head=new MyNode(l);
    tail=head;
  }
  else
  {
    tail->setnext(new MyNode(l));
    tail=tail->getnext();
  }
  rozmiar++;
}
bool MyList::empty() const
{
  if (rozmiar==0)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}
int MyList::size() const
{
  return rozmiar;
}
void MyList::print() const
{
  if (rozmiar!=0)
  {
    cout<<"["<<head->val();
    MyNode* next = head->getnext();
    while(next != nullptr)
    {
     cout<<", "<<next->val();
     next = next->getnext();
    }
  cout<<"]"<<endl;
  }
  else
  {
    cout<<"[]"<<endl;
  }
}
MyList::~MyList()
{
  cout<<"DESTRUKTOR (rozmiar = "<<rozmiar<<")\n";
  clear();
}