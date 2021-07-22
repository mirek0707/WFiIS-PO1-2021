#pragma once
/*klasa Sum - klasa przechowujaca sumy liczb z dni*/
class Sum
{
public:
  /*konstruktor
  @param s - liczba*/
  Sum(double s): _suma(s){}
  /*przeciazenie operatora (), pozwala na zwiekszenie sumy o dana wartosc
  @param i - wartosc*/
  void operator() (double i)
  {
    _suma+=i;
  }
  /*funkcja zwracajaca wartosc sumy
  @return wartosc sumy*/
  double value() const
  {
    return _suma;
  }
private:
  /*@field _suma - wartosc sumy*/
 double _suma;
};