#include <iostream>

#include "./My_Queue.h"

My_Queue::My_Queue(int q_size) : m_qsize(q_size) {
    m_items = 0;
    front = rear = nullptr;
}
My_Queue::~My_Queue() {
    if (!is_empty()) {
        Node* move_p = front;
        Node* temp;
        for (int i = 0; i < m_items; i++) {
            temp = move_p;
            move_p = temp->next;
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
    if (is_empty()) {
        front = new Node;
        front->item = item;
        front->next = rear = new Node;
        m_items++;
    } else {
        Node* temp = rear;
        temp->item = item;
        temp->next = new Node;
        rear = temp->next;
        m_items++;
    }
    return true;
}
bool My_Queue::pop(Item& item) {
    if (is_empty()) {
        front = nullptr;
        return false;
    }
    Node* temp = front;
    front = temp->next;
    item = temp->item;
    std::cout << temp << " delete :";
    std::cout << temp->item << std::endl;
    delete temp;
    m_items--;
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
