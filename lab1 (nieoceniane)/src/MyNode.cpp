#include "MyNode.h"
MyNode::MyNode(int l)
{
	liczba=l;
}
MyNode * MyNode::getnext() const
{
	return next;
}
void MyNode::setnext(MyNode* n)
{
	next=n;
}
int MyNode::val() const
{
	return liczba;
}
