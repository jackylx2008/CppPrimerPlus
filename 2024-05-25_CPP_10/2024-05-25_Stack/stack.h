#ifndef __STACK_H__
#define __STACK_H__
typedef long double Item;
class Stack {
  private:
    static const int SIZE = 5;
    Item item_arr[SIZE];
    int top;
    bool is_empty() const;
    bool is_full() const;

  public:
    Stack();
    bool push(const Item& item);
    Item pop(Item* item);
    void show() const;
};

#endif  // !__STACK_H__
