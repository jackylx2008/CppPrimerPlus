#include "./Queue.h"

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <ostream>

void Customer::set(int32_t when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
std::ostream& operator<<(std::ostream& os, const Customer& customer) {
    os << "when = " << customer.ptime();
    return os;
}
Queue::Queue(int qs) : qsize(qs) {
    items = 0;
    front = rear = nullptr;
}
Queue::~Queue() {
    if (isempty()) {
        return;
    }
    Node* temp;
    for (int i = 0; i < items; i++) {
        temp = front;
        front = front->next;
        delete temp;
    }
}
bool Queue::isempty() const {
    return items == 0;
}
bool Queue::isfull() const {
    return items == qsize;
}
int Queue::queuecount() const {
    return items;
}
bool Queue::enqueue(const Item& item) {
    if (isfull()) {
        return false;
    }
    Node* add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr) {
        front = add;
    } else {
        rear->next = add;
    }
    rear = add;
    return true;
}
bool Queue::dequeue(Item& item) {
    if (isempty()) {
        rear = nullptr;
        return false;
    }
    items--;
    item = front->item;
    Node* temp = front->next;
    delete front;
    front = temp;
    return true;
}
void Queue::show() const {
    Node* pointer = front;
    while (pointer != nullptr) {
        std::cout << pointer->item << std::endl;
        pointer = pointer->next;
    }
}
