#pragma once
#include <iostream>



///klasa będąca atrybutem i reprezentująca liczbe punktow zdrowia
class HP{

public:

///konstruktor 
  HP(int hp = 0): _hp(hp){}

//getter do hp
  int gethp() const{ return _hp; }

private:

///punkty zdrowia
  int _hp;

};

//klasa bazowa dla wszystkich elementow gry
class GameObj{

public:

///konstruktor
  GameObj() = default;

///destruktor wirtualny
  virtual ~GameObj() = default;

///konstruktor przyjmujący id elementu w postaci stringa
  GameObj(const std::string &id): _id(id){}

///wirtualna (abstrakcyjna) metoda drukujaca
  virtual void print() const = 0;

///metoda zwracajaca id elementu gry
  const std::string id()const { return _id; }

private:

/// id elementu gry
  const std::string _id;
};

///przeciazony operator << dla klasy GameObj
inline std::ostream& operator<<(std::ostream& strm, const GameObj &g){

  g.print();
  return strm;
}


//klasa Character reprezentujaca "postać" w grze player lub boss, dziedziczy wirtualne po klase GameObj ponieważ jest elementem gry i dziedziczy po niej boss, który dziedziczy również po klasie Hurting
class Character : public virtual GameObj{

public:

///konstruktor przyjmujacy punkty zdrowia, nazwe postaci oraz jej id
  Character(HP hp,const std::string &name,const std::string &id): GameObj(id)  ,_hp(hp), _name(name){}

///getter - zwraca nazwe postaci
  const std::string getName() const { return _name; }

///getter - zwraca liczbe punktow zdroiwa postaci przekonwertowana na stringa z dodanymi nawiasami
  const std::string hp()const { return "[" + std::to_string(_hp.gethp()) + " HP]";  }

private:

///reprezentuje punkty zdrowia postaci
  HP _hp;

///reprezentuje nazwe postaci
  const std::string _name;

};


///reprezentuje gracza, dziedziczy po klasie  character ponieważ jest równiez elementem gry jak i postacią, a ponadto posiada jej cechy 
class Player : public Character{

public:

///konstruktor przyjmuje punkty zdrowia, nazwe gracza, oraz id
  Player(HP hp,const std::string &name,const std::string &id): GameObj(id), Character(hp, name, id){}

///metoda wypisujaca
  void print() const override;

};



//klasa hurting dziedziczy po GameObj ponieważ reprezentuje element gry, który może zadawać obrażenia, jest osobną klasą ponieważ dziedziczą po niej klasa bomb i boss, dziedziczy wirtualnie ponieważ dziedziczy po niej klasa boss
class Hurting : public virtual GameObj{

public:

///konstruktor przyjmujacy liczbe punktow oraz id elementu gry
  Hurting(HP hp,const std::string &id): GameObj(id), _hp(hp){}

///getter zwracajacy przekonwertowana na stringa liczbe punktow zdrowia odbieranych przez element,
  const std::string hp()const { return "[" + std::to_string(_hp.gethp()) + " HP]";  }

private:
///obrazenia 
  HP _hp;

};


//klasa przedstawiajacy bombe, dziedziy po Hurting ponieważ odbiera punkty zdrowia zadając obrażenia bedąc cały czas elementem gry 
class Bomb : public Hurting{

public:
///konstruktor przyjmujacy punkty zdroiwa oraz id elementu gry
  Bomb(HP hp,const std::string &id): GameObj(id), Hurting(hp, id){}

///metoda wypisujaca
  void print() const override;

};


// dziedziczy po character oraz hurting poniewaz jest elementem szczegolnym tzn za rowno postacią, jak i moze zadawac obrazenia
class Boss : public Character, public Hurting{

public:
///konstruktor przyjmujacy liczbe punktow zdrowia, nazwe bossa, liczbe zadawanaych obrazen oraz id elementu
  Boss(HP hp,const std::string &name, HP hp2,const std::string &id): GameObj(id),  Character(hp, name, id), Hurting(hp2, id){}

///metoda wypisujaca
  void print() const override;

};

