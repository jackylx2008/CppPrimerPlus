#include "./Golf_cls.h"

int main(int argc, char *argv[]) {
    Golf one;
    one.showgolf();
    Golf two("liu", 100);
    two.showgolf();
    two.handicap(200);
    two.showgolf();
    return 0;
}
