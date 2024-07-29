#include "./dma.h"

int main(int argc, char *argv[]) {
    baseDMA bd1;
    baseDMA bd2("liu", 1);
    baseDMA bd3(bd2);
    bd1.View();
    bd2.View();
    bd1 = bd2;
    bd1.View();
    bd3.View();

    return 0;
}
