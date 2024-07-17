#ifndef __STACK_H__
#define __STACK_H__

struct customer {
    char fullname[35];
    double payment;
};
typedef customer Item;
static const int SIZE = 10;
class Stack {
  private:
    Item item_arr[SIZE];
    int top;

  public:
    Stack();
    bool is_empty() const;
    bool is_full() const;
    bool push(const Item& item);
    bool pop(Item* item);
    void show() const;
};

#endif  // !__STACK_H__
