#include <iostream>

#include "./Stack.h"

Stack::Stack(int n) {
    size = n;
    top = -1;
    pitems = new Item[size];
}
Stack::Stack(const Stack &st) {
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top + 1; i++) {
        pitems[i] = st.pitems[i];
    }
}
Stack::~Stack() {
    if (!pitems) {
        delete[] pitems;
    }
}
bool Stack::isempty() const {
    return top < 0;
}
bool Stack::isfull() const {
    return top + 1 == size;
}
bool Stack::push(const Item &item) {
    if (isfull()) {
        return false;
    }
    top++;
    pitems[top] = item;
    return true;
}
bool Stack::pop(Item &item) {
    if (isempty()) {
        pitems = nullptr;
        return false;
    }
    item = pitems[top];
    top--;
    return true;
}
Stack &Stack::operator=(const Stack &st) {
    delete[] pitems;
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top + 1; i++) {
        pitems[i] = st.pitems[i];
    }
    return *this;
}
