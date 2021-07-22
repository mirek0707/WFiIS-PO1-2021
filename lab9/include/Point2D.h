#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class Point2D
{
public:
  Point2D()=default;
  Point2D(double x, double y) : _x(x), _y(y), _d(sqrt(pow(x,2)+pow(y,2))){}
  static void PrintPoint(const Point2D point);
  static void FunctionPrintY(const Point2D& point);
  double x() const;
  double y() const;
  double d() const;
  bool operator < (const Point2D& p) const;
  void Print() const;
  void FunctionPrintX(const Point2D& point);
private:
  double _x;
  double _y;
  double _d;
};
class OrderAscX
{
public:
  bool operator ()(const Point2D& p1, const Point2D& p2) const
  {
    return p1.x() < p2.x();
  }
};
class OrderDescY
{
public:
    bool operator ()(const Point2D& p1, const Point2D& p2) const
    {
      return p1.y() > p2.y();
    }
};
double pmax(double x, double y);
bool MaxDistanceAsc(const Point2D& p1, const Point2D& p2);
void FunctionPrintX(const Point2D &p);