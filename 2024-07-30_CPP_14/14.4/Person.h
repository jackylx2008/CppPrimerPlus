#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

class Person {
  private:
    char* fname;
    char* lname;

  public:
    Person();
    Person(const char* fn, const char* ln);
    Person(const Person& p);
    Person& operator=(const Person& p);
    virtual ~Person();
    virtual void Show() const;
    virtual void Set();
    virtual void Get() = 0;
};

class Gunslinger : virtual public Person {
  private:
    int notche;
    double draw_time;

  public:
    Gunslinger();
    Gunslinger(const char* fn, const char* ln, double dt = 0.0, int n = 0);
    explicit Gunslinger(const Person& p);
    Gunslinger(const Gunslinger& gunslinger);
    Gunslinger& operator=(const Gunslinger& gunslinger);
    virtual ~Gunslinger() {}
    virtual void Show() const;
    virtual void Set();
    virtual void Get();
    double Gdraw() const {
        return draw_time;
    }
};

class PokerPlayer : virtual public Person {
  private:
    unsigned int card;

  public:
    PokerPlayer();
    PokerPlayer(const char* fn, const char* ln);
    explicit PokerPlayer(const Person& p);
    PokerPlayer(const PokerPlayer& poker_player);
    PokerPlayer& operator=(const PokerPlayer& poker_player);
    virtual ~PokerPlayer() {}
    virtual void Show() const;
    virtual void Set();
    virtual void Get();
    int Cdraw() const {
        return card;
    }
};

class BadDude : virtual public Gunslinger, virtual public PokerPlayer {
  private:
  public:
    BadDude();
    BadDude(const char* fn, const char* ln, double dt = 0.0, int n = 0);
    // explicit BadDude(const Person& p);
    // BadDude(const BadDude& bd);
    // BadDude& operator=(const BadDude& bd);
    virtual ~BadDude() {}
    virtual void Show() const;
    virtual void Set();
    virtual void Get() {}
    double Gdraw() const {
        return Gunslinger::Gdraw();
    }
    int Cdraw() const {
        return PokerPlayer::Cdraw();
    }
};

#endif  // !__PERSON_H__
