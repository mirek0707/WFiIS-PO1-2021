#include "Point2D.h"
double Point2D::x() const
{
  return _x;
}
double Point2D::y() const
{
  return _y;
}
double Point2D::d() const
{
  return _d;
}
void Point2D::PrintPoint(const Point2D point)
{
  cout<<"Point coordinates ("<<point.x()<<", "<<point.y()<<") distance from origin: "<<point.d()<<endl;
}
void Point2D::FunctionPrintY(const Point2D& point)
{
  cout<<"Function print y="<<point.y()<<endl;
}
bool Point2D::operator < (const Point2D &p) const
{
  if (_d<p._d)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void Point2D::Print() const
{
  cout<<"Point coordinates ("<<_x<<", "<<_y<<") distance from origin: "<<_d<<endl;
}
void Point2D::FunctionPrintX(const Point2D& point)
{
  cout<<"Function print x="<<point.x()<<endl;
}

bool MaxDistanceAsc(const Point2D &p1, const Point2D &p2) 
{
  if (pmax(p1.x(),p1.y()) < pmax(p2.x(),p2.y()))
    return true;
  else
    return false;
}
double pmax(double x, double y)
{
  if(x>y)
    return x;
  else
    return y;
}
void FunctionPrintX(const Point2D &p)
{
  cout<<"Function print x="<<p.x()<<endl;
}