#include <iostream>
#include <string>

#include "./golf_ps.h"

void setgolf(golf *g, std::string s, int hc) {
    g->fullname = s;
    g->handicap = hc;
}
int setgolf(golf *g) {
    std::string name;
    int hc;
    std::cout << "Please input a name" << std::endl;
    std::getline(std::cin, name, '\n');
    if (name == "") {
        std::cout << "Empty input" << std::endl;
        std::cout << name << std::endl;
        g->fullname = " ";
        g->handicap = 0;
        return 0;
    }

    std::cout << "Please input handicap" << std::endl;
    if (!(std::cin >> hc)) {
        std::cout << "Invalid input" << std::endl;
        std::cin.clear();
    }
    while (std::cin.get() != '\n') {
        continue;
    }
    // strcpy(g.fullname, name);
    // g.handicap = hc;
    setgolf(g, name, hc);
    return 1;
}

void handicap(golf *g, int hc) {
    g->handicap = hc;
}

void showgolf(const golf &g) {
    std::cout << "Name = " << g.fullname << std::endl;
    std::cout << "Handicp = " << g.handicap << std::endl;
}
