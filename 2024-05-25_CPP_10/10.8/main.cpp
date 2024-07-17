#include <cstring>
#include <iostream>

#include "./MyChainList.h"

int main(int argc, char *argv[]) {
    ChainList chain;
    Item p1;
    p1.age = 10;
    strcpy(p1.name, "liu");
    chain.push(p1);

    Item *p2 = new Item;
    p2->age = 20;
    strcpy(p2->name, "xin");
    chain.push(*p2);

    // chain.visit(visit_p, *p2);
    chain.visit(visit_p);

    // while (!chain.is_Empty()) {
    //     Item temp;
    //     temp = chain.pop();
    //     // std::cout << temp.age << std::endl;
    // }

    return 0;
}
