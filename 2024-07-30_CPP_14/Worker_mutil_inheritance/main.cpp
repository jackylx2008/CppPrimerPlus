#include <algorithm>
#include <iostream>

#include "./Worker.h"

const int LIMIT = 3;

void test() {
    Worker* p_worker[LIMIT];
    for (int i = 0; i < LIMIT; i++) {
        char choice;
        std::cout << "w for Waiter, s for Singer, m for SingerWaiter q for Quit"
                  << std::endl;
        std::cin >> choice;
        while (std::cin.get() != '\n') continue;
        while (strchr("wsmq", choice) == NULL) {
            std::cout
                << "w for Waiter, s for Singer, m for SingerWaiter q for Quit"
                << std::endl;
            std::cin >> choice;
            while (std::cin.get() != '\n') continue;
        }
        if (choice == 'q') {
            break;
        }
        switch (choice) {
            case 'w': {
                std::cout << "Waiter info:" << std::endl;
                p_worker[i] = new Waiter();
                break;
            }
            case 's': {
                std::cout << "Singer info:" << std::endl;
                p_worker[i] = new Singer();
                break;
            }
            case 'm': {
                std::cout << "SingerWaiter info:" << std::endl;
                p_worker[i] = new SingerWaiter();
                break;
            }
        }
        p_worker[i]->Set();
    }
    for (int i = 0; i < LIMIT; i++) {
        std::cout << std::endl;
        p_worker[i]->Show();
    }
}

int main(int argc, char* argv[]) {
    test();
    return 0;
}
