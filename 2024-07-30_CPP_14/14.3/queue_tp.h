#ifndef __QUEUE_TP_H__
#define __QUEUE_TP_H__

#include <iostream>
template <typename T>
class QueueTp {
  private:
    struct Node {
        T item;
        struct Node* next;
    };
    enum {
        Q_SIZE = 10
    };
    Node* front;
    Node* rear;
    int items;
    const int qsize;
    // preemptive definitions to prevent public copying
    QueueTp<T>(const QueueTp<T>& q) : qsize(0) {}
    QueueTp<T>& operator=(const QueueTp<T>& q) {
        return *this;
    }

  public:
    explicit QueueTp<T>(int qs);
    ~QueueTp<T>();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const T& item);
    bool dequeue(T& item);  // remove item from front
    bool dequeue(T* item);  // remove item from front
    void show() const;
};

template <typename T>
QueueTp<T>::QueueTp(int qs) : qsize(qs) {
    items = 0;
    front = rear = nullptr;
}
template <typename T>
QueueTp<T>::~QueueTp() {
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
template <typename T>
bool QueueTp<T>::isempty() const {
    return items == 0;
}
template <typename T>
bool QueueTp<T>::isfull() const {
    return items == qsize;
}
template <typename T>
int QueueTp<T>::queuecount() const {
    return items;
}
template <typename T>
bool QueueTp<T>::enqueue(const T& item) {
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
template <typename T>
bool QueueTp<T>::dequeue(T& item) {
    if (isempty()) {
        std::cout << "isempty" << std::endl;
        rear = nullptr;
        return false;
    }
    // std::cout << "dequeue" << std::endl;
    items--;
    item = front->item;
    Node* temp = front->next;
    delete front;
    front = temp;
    return true;
}
template <typename T>
bool QueueTp<T>::dequeue(T* item) {
    if (isempty()) {
        std::cout << "isempty" << std::endl;
        rear = nullptr;
        return false;
    }
    // std::cout << "dequeue" << std::endl;
    items--;
    item = front->item;
    Node* temp = front->next;
    delete front;
    front = temp;
    return true;
}
template <typename T>
void QueueTp<T>::show() const {
    Node* pointer = front;
    while (pointer != nullptr) {
        std::cout << pointer->item << std::endl;
        pointer = pointer->next;
    }
}
#endif  // !__QUEUE_TP_H__
