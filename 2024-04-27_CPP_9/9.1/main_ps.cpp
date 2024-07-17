#include <iostream>

#include "./golf_ps.h"

const int SIZE = 100;

const int BUF = 51200;
char buffer[BUF];

int main(int argc, char* argv[]) {
    // golf g[SIZE];
    // int sum = 0;
    // while (setgolf(&g[sum]) && sum < SIZE) {
    //     sum++;
    // }
    // for (int i = 0; i < sum; i++) {
    //     showgolf(g[i]);
    // }
    golf* g = new (buffer) golf;
    setgolf(g);
    showgolf(*g);
    return 0;
}
