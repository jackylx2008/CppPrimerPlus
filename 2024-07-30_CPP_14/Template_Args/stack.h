#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

static const int SIZE = 10;
template <typename T>
class Stack {
  private:
    T item_arr[SIZE];
    int top;
    bool is_empty() const;
    bool is_full() const;

  public:
    Stack();
    bool push(const T& item);
    bool pop(T* item);
    bool pop(T& item);
    void show() const;
};

template <typename T>
Stack<T>::Stack() {
    top = 0;
}

template <typename T>
bool Stack<T>::push(const T& item) {
    if (!is_full()) {
        item_arr[top] = item;
        top++;
        // std::cout << item << "push successed" << std::endl;
        return true;
    } else {
        // std::cout << "is_full push failed" << std::endl;
        return false;
    }
}

template <typename T>
bool Stack<T>::pop(T* item) {
    if (!is_empty()) {
        std::cout << "Pointer" << std::endl;
        // std::cout << "pop= " << item_arr[top];
        *item = item_arr[top - 1];
        // this->item_arr[top - 1] = -1.0;
        top--;
        // std::cout << "pop successed" << std::endl;
        return true;
    } else {
        // *item = nullptr;
        // std::cout << "is_empty, pop failed" << std::endl;
        return false;
    }
}

template <typename T>
bool Stack<T>::pop(T& item) {
    if (!is_empty()) {
        // std::cout << "pop= " << item_arr[top];
        item = item_arr[top - 1];
        // this->item_arr[top - 1] = -1.0;
        top--;
        // std::cout << "pop successed" << std::endl;
        return true;
    } else {
        // *item = nullptr;
        // std::cout << "is_empty, pop failed" << std::endl;
        return false;
    }
}

template <typename T>
bool Stack<T>::is_empty() const {
    if (top == 0) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool Stack<T>::is_full() const {
    if (top == SIZE) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
void Stack<T>::show() const {
    if (!is_empty()) {
        for (int i = 0; i < top; i++) {
            std::cout << item_arr[i] << std::endl;
        }
    } else {
        std::cout << "arr is_empty, nothing to show" << std::endl;
    }
}
#endif  // !__STACK_H__
