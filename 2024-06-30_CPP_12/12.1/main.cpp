#include "Cow.h"
int main(int argc, char *argv[]) {
    Cow c1;
    c1.ShowCow();
    Cow c2("liuxin", "hockey", 75.0);
    c2.ShowCow();
    Cow c3(c2);
    c3.ShowCow();
    c1 = c3;
    c1.ShowCow();
    return 0;
}
