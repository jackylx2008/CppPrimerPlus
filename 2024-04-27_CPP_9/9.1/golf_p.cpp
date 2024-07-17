#include <cstring>
#include <iostream>
#include <string>

#include "./golf_p.h"

void setgolf(golf *g, const char *name, int hc) {
    // int i = 0;
    // while (name[i]) {
    //     g->fullname[i] = name[i];
    //     i++;
    // }
    strcpy(g->fullname, name);
    g->handicap = hc;
}
int setgolf(golf *g) {
    char name[Len];
    int hc;
    std::cout << "Please input a name" << std::endl;
    std::cin.getline(name, Len);
    if (name[0] == '\0') {
        // if (strcmp(name, "") == 0) {
        std::cout << "Empty input" << std::endl;
        std::cout << name << std::endl;
        strcpy(g->fullname, "");
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
