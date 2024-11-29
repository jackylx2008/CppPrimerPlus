#include <cstring>
#include <iostream>

#include "./Person.h"

// void test_Person() {
//     Person p1;
//     p1.Show();
//     Person p2("liu", "xin");
//     p2.Show();
//     p1 = p2;
//     p1.Show();
//     Person p3(Person("y", "x"));
//     p3.Show();
// }
// void test_gunslinger() {
//     Person pp2("liu", "xin");
//
//     Gunslinger g1;
//     g1.Show();
//     Gunslinger g2("ha", "hh", 10, 1);
//     g2.Show();
//     Gunslinger g3(pp2);
//     g3.Show();
//     Gunslinger g4(g2);
//     g4.Show();
// }
//
// void test_PokerPlayer() {
//     Person pp2("liu", "xin");
//
//     PokerPlayer p1;
//     p1.Show();
//     PokerPlayer p2("ha", "haha");
//     p2.Show();
//     PokerPlayer p3(pp2);
//     p3.Show();
//     PokerPlayer p4(p2);
//     p4.Show();
//     p4 = p3;
//     p4.Show();
// }

const int LIMIT = 3;
int main(int argc, char* argv[]) {
    Person* p_person[LIMIT];
    for (int i = 0; i < LIMIT; i++) {
        char choice;
        std::cout
            << "g for Gunslinger, p for PokerPlayer, b for BadDude q for Quit"
            << std::endl;
        std::cin >> choice;
        while (std::cin.get() != '\n') continue;
        while (strchr("gpbq", choice) == NULL) {
            std::cout << "g for Gunslinger, p for PokerPlayer, b for BadDude q "
                         "for Quit"
                      << std::endl;
            std::cin >> choice;
            while (std::cin.get() != '\n') continue;
        }
        if (choice == 'q') {
            break;
        }
        switch (choice) {
            case 'g': {
                std::cout << "Gunslinger info:" << std::endl;
                p_person[i] = new Gunslinger();
                break;
            }
            case 'p': {
                std::cout << "PokerPlayer info:" << std::endl;
                p_person[i] = new PokerPlayer();
                break;
            }
            case 'b': {
                std::cout << "BadDude info:" << std::endl;
                p_person[i] = new BadDude();
                break;
            }
        }
        p_person[i]->Set();
    }
    for (int i = 0; i < LIMIT; i++) {
        std::cout << std::endl;
        p_person[i]->Show();
    }
    return 0;
}
