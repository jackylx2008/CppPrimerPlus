#include <cstring>

#ifndef __PLORG_H__
#define __PLORG_H__

class Plorg {
private:
  char name[19];
  int contentment_index;

public:
  explicit Plorg(const char *name = "Plorg", int ci = 50) {
    strcpy(this->name, name);
    contentment_index = ci;
  }
  void show();
  void set_ci(int ci);
};
#endif // !__PLORG_H__
