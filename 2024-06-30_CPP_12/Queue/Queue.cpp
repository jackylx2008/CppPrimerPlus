#include <iostream>

#include "./My_Queue.h"

My_Queue::My_Queue(int q_size) : m_qsize(q_size) {
    m_items = 0;
    front = rear = nullptr;
}
My_Queue::~My_Queue() {
    if (!is_empty()) {
        Node* temp;
        for (int i = 0; i < m_items; i++) {
            temp = front;
            front = temp->next;
            std::cout << temp << " delete :";
            std::cout << temp->item << std::endl;
            delete temp;
        }
    }
}
bool My_Queue::is_full() const {
    return m_items == m_qsize;
}
bool My_Queue::is_empty() const {
    return m_items == 0;
}
int My_Queue::queue_count() const {
    return m_items;
}
bool My_Queue::push(const Item& item) {
    if (is_full()) {
        return false;
    }
    Node* add = new Node;
    m_items++;
    add->item = item;
    add->next = nullptr;
    if (front == nullptr) {  // is_empty
        front = rear = add;
    } else {
        rear->next = add;
        rear = add;
    }
    // add->item = item;
    // add->next = NULL;
    // m_items++;
    // if (front == NULL)
    //     front = add;
    // else
    //     rear->next = add;
    // rear = add;
    return true;
}
bool My_Queue::pop(Item& item) {
    if (front == nullptr) {
        return false;
    }
    Node* temp = front;
    front = temp->next;
    item = temp->item;
    std::cout << temp << " delete :";
    std::cout << temp->item << std::endl;
    delete temp;
    m_items--;
    if (m_items == 0) {
        rear = nullptr;
    }
    return true;
}
void My_Queue::show_queue() const {
    if (!is_empty()) {
        Node* move_p = front;
        for (int i = 0; i < m_items; i++) {
            std::cout << move_p << " :";
            std::cout << move_p->item << std::endl;
            move_p = move_p->next;
        }
    }
}
