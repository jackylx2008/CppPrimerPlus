#include <iostream>

#include "./stonewt.h"

int main() {
    Stonewt wolfe(285.7);  // same as Stonewt wolfe = 285.7;
    wolfe.set_stat(Stonewt::FLOATING_POUNDS);
    std::cout << wolfe + wolfe;
    std::cout << wolfe - Stonewt(200.0);
    std::cout << wolfe * 2;
    std::cout << 3 * wolfe;
    return 0;
}
