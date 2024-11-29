#include <iostream>

#include "./Probe_Analyzer.h"

int main(int argc, char* argv[]) {
    Analyzer* a = new Analyzer;
    Probe* p = new Probe;
    sync(*a, *p);
    std::cout << "\n";
    delete a;
    delete p;
    a = new Analyzer;
    p = new Probe;
    sync(*p, *a);

    return 0;
}
