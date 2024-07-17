#include <iostream>

#include "./golf_p.h"

const int SIZE = 100;

int main(int argc, char *argv[]) {
    // golf g1;
    // g1 = {"XIN", 1};
    // showgolf(g1);
    // setgolf(g1, "Liu", 100);
    // showgolf(g1);
    // handicap(g1, 200);
    // showgolf(g1);
    // int r1 = setgolf(g1);
    // std::cout << "r1 = " << r1 << std::endl;

    // golf g2;
    // int r2 = setgolf(g2);
    // showgolf(g2);
    // std::cout << "r2 = " << r2 << std::endl;

    golf g[SIZE];
    int sum = 0;
    // for (int i = 0; i < NUM; i++) {
    //     if (!setgolf(&g[i])) {
    //         sum = i;
    //         break;
    //     }
    // }
    while (setgolf(&g[sum]) && sum < SIZE) {
        sum++;
    }
    for (int i = 0; i < sum; i++) {
        showgolf(g[i]);
    }
}
