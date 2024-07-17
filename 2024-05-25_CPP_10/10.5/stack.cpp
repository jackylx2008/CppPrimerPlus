#include <iostream>

#include "./stack.h"

Stack::Stack() {
    top = 0;
}

bool Stack::push(const Item& item) {
    if (!is_full()) {
        this->item_arr[top] = item;
        top++;
        // std::cout << "push successed" << std::endl;
        return false;
    } else {
        std::cout << "is_full push failed" << std::endl;
        return true;
    }
}

bool Stack::pop(Item* item) {
    if (!is_empty()) {
        *item = this->item_arr[top - 1];
        top--;
        // std::cout << "pop successed" << std::endl;
        return true;
    } else {
        std::cout << "is_empty, pop failed" << std::endl;
        return false;
    }
}

bool Stack::is_empty() const {
    if (top == 0) {
        return true;
    } else {
        return false;
    }
}

bool Stack::is_full() const {
    if (top == SIZE) {
        return true;
    } else {
        return false;
    }
}

void Stack::show() const {
    if (!is_empty()) {
        for (int i = 0; i < top; i++) {
            std::cout << this->item_arr[i].fullname << ": "
                      << this->item_arr[i].payment << std::endl;
        }
    } else {
        std::cout << "arr is_empty, nothing to show" << std::endl;
    }
}
