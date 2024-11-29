#ifndef __PROBE_ANALYZER_H
#define __PROBE_ANALYZER_H

#include <iostream>
#include <string>

class Analyzer;
class Probe;

class Probe {
  private:
    std::string str_Probe = "aaaProbe";

  public:
    friend void sync(Analyzer& a, Probe& p);
    friend void sync(Probe& a, Analyzer& p);
};
class Analyzer {
  private:
    std::string str_analyzer = "aaaAnalyzer";

  public:
    friend void sync(Analyzer& a, Probe& p);
    friend void sync(Probe& a, Analyzer& p);
};

void sync(Analyzer& a, Probe& p);
void sync(Probe& p, Analyzer& a);
#endif  // !__PROBE_ANALYZER_H
