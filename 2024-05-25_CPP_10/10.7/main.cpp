#include "./Plorg.h"

int main(int argc, char *argv[]) {
  Plorg p1;
  Plorg p2("liuxin", 100);
  p1.show();
  p2.show();
  p1.set_ci(1000);
  p2.set_ci(2000);
  p1.show();
  p2.show();
  return 0;
}
