#include <time.h>

#include <cstdlib>
#include <cstring>
#include <iostream>

#include "./Person.h"

Person::Person() {
    fname = nullptr;
    lname = nullptr;
}
Person::Person(const char* fn, const char* ln) {
    fname = new char(strlen(fn));
    lname = new char(strlen(ln));
    strcpy(fname, fn);
    strcpy(lname, ln);
}
Person::Person(const Person& p) {
    fname = new char(strlen(p.lname));
    lname = new char(strlen(p.lname));
    strcpy(fname, p.fname);
    strcpy(lname, p.lname);
}
Person& Person::operator=(const Person& p) {
    if (this == &p) {
        return *this;
    }
    if (fname != nullptr && lname != nullptr) {
        delete[] fname;
        delete[] lname;
    }
    fname = new char(strlen(p.lname));
    lname = new char(strlen(p.lname));
    strcpy(fname, p.fname);
    strcpy(lname, p.lname);
    return *this;
}
Person::~Person() {
    delete[] fname;
    delete[] lname;
}
void Person::Show() const {
    if (fname == nullptr && lname == nullptr) {
        std::cout << "Null" << std::endl;
        return;
    }
    std::cout << fname << " " << lname << std::endl;
}
void Person::Set() {
    char temp[100];
    std::cout << "First name: ";
    std::cin >> temp;
    fname = new char(strlen(temp));
    strcpy(fname, temp);
    std::cout << "Last name: ";
    std::cin >> temp;
    lname = new char(strlen(temp));
    strcpy(lname, temp);
}
Gunslinger::Gunslinger() : Person() {
    notche = 0;
    draw_time = 0;
}
Gunslinger::Gunslinger(const char* fn, const char* ln, double dt, int n)
    : Person(fn, ln), draw_time(dt), notche(n) {}
Gunslinger::Gunslinger(const Person& p)
    : Person(p), draw_time(0.0), notche(0) {}
Gunslinger::Gunslinger(const Gunslinger& gunslinger)
    : Person((Person&)gunslinger) {
    notche = gunslinger.notche;
    draw_time = gunslinger.draw_time;
}
Gunslinger& Gunslinger::operator=(const Gunslinger& gunslinger) {
    if (this == &gunslinger) {
        return *this;
    }
    Person::operator=((Person&)gunslinger);
    notche = gunslinger.notche;
    draw_time = gunslinger.draw_time;
    return *this;
}
void Gunslinger::Show() const {
    Person::Show();
    std::cout << "Draw_time: " << draw_time << " Notche: " << notche
              << std::endl;
}
void Gunslinger::Set() {
    Person::Set();
    Gunslinger::Get();
}
void Gunslinger::Get() {
    double temp1;
    int temp2;
    std::cout << "Draw_time: ";
    std::cin >> temp1;
    std::cout << "Notche: ";
    std::cin >> temp2;
    draw_time = temp1;
    notche = temp2;
}
PokerPlayer::PokerPlayer() : Person() {}
PokerPlayer::PokerPlayer(const char* fn, const char* ln) : Person(fn, ln) {
    srand((unsigned int)time(NULL) + (unsigned int)rand());
    card = rand() % 52;
}
PokerPlayer::PokerPlayer(const Person& p) : Person(p) {
    srand((unsigned int)time(NULL) + (unsigned int)rand());
    card = rand() % 52;
}
PokerPlayer::PokerPlayer(const PokerPlayer& poker_player)
    : Person((Person&)poker_player), card(poker_player.card) {}
PokerPlayer& PokerPlayer::operator=(const PokerPlayer& poker_player) {
    if (this == &poker_player) {
        return *this;
    }
    Person::operator=((Person&)poker_player);
    card = poker_player.card;
    return *this;
}
void PokerPlayer::Show() const {
    Person::Show();
    std::cout << "Card: " << card << std::endl;
}
void PokerPlayer::Set() {
    Person::Set();
    PokerPlayer::Get();
}
void PokerPlayer::Get() {
    srand((unsigned int)time(NULL) + (unsigned int)rand());
    card = rand() % 52;
}
BadDude::BadDude() : Gunslinger(), PokerPlayer() {}
BadDude::BadDude(const char* fn, const char* ln, double dt, int n)
    : Gunslinger(fn, ln, dt, n), PokerPlayer(fn, ln) {}
void BadDude::Show() const {
    Person::Show();
    std::cout << "BadDude Draw_time: " << Gdraw() << std::endl;
    std::cout << "BadDude Card: " << Cdraw() << std::endl;
}
void BadDude::Set() {
    Person::Set();
    Gunslinger::Get();
    PokerPlayer::Get();
}
