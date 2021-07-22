#include "GameObj.h"
HP::HP(int h) : _hp(h){}
string HP::print() const
{
  return "["+std::to_string(_hp)+" HP]";
}

GameObj::GameObj(const string id): _ID(id){}
string GameObj::print() const
{
  return _ID;
}
string GameObj::id() const
{
  return _ID;
}
std::ostream &operator <<(std::ostream &s, const GameObj& go)
{
  s<<go.print();
  return s;
}

Character::Character(HP &hp, const string name) : GameObj(""), _health(hp), _name(name){}
string Character::hp() const
{
  return _health.print();
}
string Character::name() const
{
  return _name;
}

Player::Player(HP hp, const string name, const string id) : GameObj(id), Character(hp, name){}
string Player::print() const
{
  return "Player "+name()+", ma: "+Character::hp();
}

Hurting::Hurting(HP &hp) : GameObj(""), _health(hp) {}
string Hurting::hp() const
{
  return _health.print();
}
string Hurting::print() const
{
  return "Jego uderzenie odbiera: "+Hurting::hp();
}

Bomb::Bomb(HP hp, const string id) : GameObj(id), Hurting(hp){}
string Bomb::print() const
{
  return Hurting::print();
}

Boss::Boss(HP hp1, const string name, HP hp2, const string id) : GameObj(id), Character(hp1, name), Hurting(hp2){}
string Boss::print() const
{
  return "Bad guy: "+name()+", ma: "+Character::hp()+"\n"+Hurting::print();
}
