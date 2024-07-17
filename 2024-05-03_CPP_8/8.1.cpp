#include <iostream>

void PrtStr(const char* s, int n = 0);
int main(int argc, char* argv[]) {
    PrtStr("Hello");
    PrtStr("World");
    PrtStr("liuxin", 9);
    return 0;
}

void PrtStr(const char* s, int n) {
    static int num = 0;
    if (n > 0) {
        for (int i = 0; i < num; i++) {
            std::cout << s << std::endl;
        }
    } else {
        std::cout << s << std::endl;
    }
    num++;
}
