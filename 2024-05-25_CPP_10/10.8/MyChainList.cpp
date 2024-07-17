#include <iostream>

#include "./MyChainList.h"

ChainList::ChainList() {
    size = -1;
}

bool ChainList::is_Full() {
    if (size == LENGTH - 1) {
        return true;
    } else {
        return false;
    }
}
bool ChainList::is_Empty() {
    if (size < 0) {
        return true;
    } else {
        return false;
    }
}

void ChainList::push(const Item& i) {
    size++;
    addr[size] = new Item;
    *addr[size] = i;
    std::cout << addr[size]->age << std::endl;
    // std::cout << "push size = " << size << std::endl;
}
Item& ChainList::pop() {
    Item* temp = new Item;
    std::cout << "size = " << size << std::endl;
    std::cout << addr[size]->age << std::endl;
    temp = addr[size];
    size--;
    return *temp;
}
int ChainList::get_size() {
    return size;
}

void visit_p(const Item& item) {
    std::cout << "Name = " << item.name << std::endl;
    std::cout << "Age = " << item.age << std::endl;
}

void ChainList::visit(void (*pf)(const Item& item), const Item& item) {
    (*pf)(item);
}

void ChainList::visit(void (*pf)(const Item& item)) {
    std::cout << "Iterrate each item" << std::endl;
    for (int i = 0; i <= size; i++) {
        pf(*addr[i]);
    }
}
