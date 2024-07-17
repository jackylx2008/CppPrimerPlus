#include <iostream>

#include "./StringBad.h"

void Reference_Func(StringBad& s);
void Args_Func(StringBad s);

int main(int argc, char* argv[]) {
    std::cout << "------------" << std::endl;
    StringBad line1 = StringBad("hello world");
    StringBad line2 = StringBad("line2");
    line1 = "new line1";
    std::cout << line1;
    std::cout << line1 << std::endl;
    std::cout << line2 << std::endl;
    // std::cout << line3 << std::endl;
    Reference_Func(line1);
    Args_Func(line2);
    // line2 = line1;
    std::cout << line2 << std::endl;
    std::cout << "num_string = " << line2.get_num_strings() << "\n";
    const char c1 = line2[0];
    std::cout << "c1 = " << c1 << "\n";
    std::cout << "------------" << std::endl;

    line1 = "new line1";
    std::cout << line1 << std::endl;
    return 0;
}
void Reference_Func(StringBad& s) {
    std::cout << "Reference_Func : ";
    std::cout << s << std::endl;
}
void Args_Func(StringBad s) {
    std::cout << "Args_Func : ";
    std::cout << s << std::endl;
}
