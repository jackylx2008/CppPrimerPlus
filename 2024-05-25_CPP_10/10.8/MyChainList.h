#ifndef __CHAIN_LIST_H__
#define __CHAIN_LIST_H__
struct People {
    int age;
    char name[40];
};

typedef People Item;
const int LENGTH = 100;
void visit_p(const Item& item);

class ChainList {
  private:
    int size;
    int ptr;
    // int length;
    Item* addr[LENGTH];

  public:
    ChainList();
    bool is_Empty();
    bool is_Full();
    int get_size();
    Item& pop();
    void push(const Item& i);
    void visit(void (*pf)(const Item& item), const Item& item);
    void visit(void (*pf)(const Item& item));
};

#endif  // !__CHAIN_LIST_H__
