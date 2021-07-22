#pragma once
#include<iostream>
#include<string>
using namespace std;
/*hierarchia klas:
            GameObj
            /     \
      Character    Hurting
      /        \  /       \
  Player       Boss       Bomb
Korzystam z takiej hierarchii, poniewaz Boss musi jednoczesnie dziedziczyc po Charater i Hurting - jest jednoczesnie postacia, ale zadaje rowniez obrazenia. Dla wygody i ulatwienia w implementacji dodalem klase GameObj, ktora znajduje sie w hierarchii ponad wszystkimi*/
/*klasa HP - klasa przechowujaca informacje o zdrowiu*/
class HP
{
  public:
    /*konstruktor domyslny*/
    HP()=default;
    /*konstruktor 
    @param h - wartosc zdrowia*/
    HP(int h);
    /*funkcja ulatwiajaca wyswietlanie
    @return ciag znakow do wypisania na ekran*/
    string print() const;
    /*destruktor*/
    ~HP(){}
  private:
    /*field _hp - informacja o zdrowiu*/
    int _hp;
};

class GameObj
{
  public:
    /*konstruktor domyslny*/
    GameObj()=default;
    /*konstruktor 
    @param id - ciag znakow okreslajacy id*/
    GameObj(const string id);
    /*funkcja ulatwiajaca wyswietlanie
    @return ciag znakow do wypisania na ekran*/
    virtual string print() const;
    /*funkcja zwracajaca id, getter
    @return id*/
    string id() const;
    /*destruktor*/
    virtual ~GameObj(){}
    /*przeciazenie operatora wyswietlania*/
    friend std::ostream &operator <<(std::ostream &s, const GameObj& go);
  private:
    /*field ID - id obiektu*/
    string _ID;
};
std::ostream &operator <<(std::ostream &s, const GameObj& go);

class Character : virtual public GameObj
{
  public:
    /*konstruktor 
    @param hp - zdrowie obiektu
    @param name - nazwa obiektu*/
    Character(HP &hp, const string name);
    /*funkcja zwracajaca zdrowie w postaci gotowej do wyswietlenia
    @return health*/
    string hp() const;
    /*funkcja zwracajaca nazwe, getter
    @return name*/
    string name() const;
  private:
    /*field _health- zdrowie obiektu*/
    HP _health;
    /*field name - nazwa obiektu*/
    string _name;
};

class Hurting : virtual public GameObj
{
  public:
    /*konstruktor 
    @param hp - zadawane obrazenia*/
    Hurting(HP &hp);
    /*funkcja zwracajaca zdrowie w postaci gotowej do wyswietlenia
    @return health*/
    string hp() const;
    /*funkcja ulatwiajaca wyswietlanie
    @return ciag znakow do wypisania na ekran*/
    string print() const;
  private:
    /*field health - obrazenia zadawane przez obiekt*/
    HP _health;
};

class Player : public Character
{
  public:
    /*konstruktor domyslny*/
    Player()=default;
    /*konstruktor 
    @param hp - zdrowie obiektu
    @param name - nazwa obiektu
    @param id - numer id obiektu*/
    Player(HP hp, const string name, const string id);
    /*funkcja ulatwiajaca wyswietlanie
    @return ciag znakow do wypisania na ekran*/
    string print() const override;
};

class Bomb : public Hurting
{
  public:
    /*konstruktor domyslny*/
    Bomb()=default;
    /*konstruktor 
    @param hp - obrazenia zadawane przez obiekt
    @param id - numer id obiektu*/
    Bomb(HP hp, const string id);
    /*funkcja ulatwiajaca wyswietlanie
    @return ciag znakow do wypisania na ekran*/
    string print() const override;
};

class Boss : public Character, public Hurting
{
  public:
    /*konstruktor domyslny*/
    Boss()=default;
    /*konstruktor 
    @param hp1 - zdrowie obiektu
    @param name - nazwa obiektu
    @param hp2 - obrazenia zadawane przez obiekt
    @param id - numer id obiektu*/
    Boss(HP hp1, const string name, HP hp2, const string id);
    /*funkcja ulatwiajaca wyswietlanie
    @return ciag znakow do wypisania na ekran*/
    string print() const override;
};
