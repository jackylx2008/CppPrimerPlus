// queue.h -- interface for a queue #ifndef QUEUE_H_
#ifndef QUEUE_H_
#define QUEUE_H_
#include <cstdint>
#include <ostream>
// This queue will contain Customer items class Customer
class Customer {
  private:
    int32_t arrive;
    int processtime;

  public:
    // arrival time for customer // processing time for customer
    Customer() { arrive = processtime = 0; }
    void set(int32_t when);
    int32_t when() const { return arrive; }
    int ptime() const { return processtime; }
    friend std::ostream &operator<<(std::ostream &os, const Customer &customer);
};

typedef Customer Item;

class Queue {
  private:
    // class scope definitions
    // Node is a nested structure definition local to this class
    struct Node {
        Item item;
        struct Node *next;
    };
    enum { Q_SIZE = 10 };
    // private class members
    Node *front;  // pointer to front of Queue
    Node *rear;
    int items;
    const int qsize;
    // preemptive definitions to prevent public copying
    Queue(const Queue &q) : qsize(0) {}
    Queue &operator=(const Queue &q) { return *this; }

  public:
    explicit Queue(int qs);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item);
    bool dequeue(Item &item);  // remove item from front
    void show() const;
};
#endif
