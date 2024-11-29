#include "./Probe_Analyzer.h"

void sync(Analyzer& a, Probe& p) {
    std::cout << "Sync a to p, p.str = a.str" << std::endl;
    std::cout << "a.str = " << a.str_analyzer << std::endl;
    std::cout << "p.str = " << p.str_Probe << std::endl;
    p.str_Probe = a.str_analyzer;
    std::cout << "a.str = " << a.str_analyzer << std::endl;
    std::cout << "p.str = " << p.str_Probe << std::endl;
}

void sync(Probe& p, Analyzer& a) {
    std::cout << "Sync p to a, a.str = p.str" << std::endl;
    std::cout << "a.str = " << a.str_analyzer << std::endl;
    std::cout << "p.str = " << p.str_Probe << std::endl;
    a.str_analyzer = p.str_Probe;
    std::cout << "a.str = " << a.str_analyzer << std::endl;
    std::cout << "p.str = " << p.str_Probe << std::endl;
}
