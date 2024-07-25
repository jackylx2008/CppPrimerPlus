#include <iostream>

#include "./dma.h"

int main(int argc, char *argv[]) {
    BaseDma ba("liu", 5);
    BaseDma null_ba;
    BaseDma construct_ba = ba;
    std::cout << ba << std::endl;
    std::cout << null_ba << std::endl;
    std::cout << construct_ba << std::endl;
    null_ba = ba;
    std::cout << null_ba << std::endl;

    Derived_Ba da("xin", 6, 7);
    Derived_Ba null_da;
    Derived_Ba construct_da = da;
    std::cout << da << std::endl;
    std::cout << null_da << std::endl;
    std::cout << construct_da << std::endl;
    null_da = da;
    std::cout << null_da << std::endl;

    Derived_New dn("luo", 6, "ya");
    Derived_New null_dn;
    Derived_New basedma(ba, "basedma");
    Derived_New construct_dn = dn;
    std::cout << dn << std::endl;
    std::cout << null_da << std::endl;
    std::cout << construct_da << std::endl;
    std::cout << basedma << std::endl;
    null_dn = dn;
    std::cout << null_dn << std::endl;

    return 0;
}
