#ifndef __GLOAM_FRABJOUS_H__
#define __GLOAM_FRABJOUS_H__
#include <cstring>
#include <iostream>
class Frabjous {
  private:
    char fab[20];

  public:
    explicit Frabjous(const char* s = "C++") {
        strncpy(fab, s, 19);
        fab[19] = '\0';
    }
    virtual void tell() {
        std::cout << fab << std::endl;
    }
};
class Gloam : private Frabjous {
  private:
    int glip;

  public:
    explicit Gloam(int g = 0, const char* s = "C++") : glip(g), Frabjous(s) {
    }
    Gloam(int g, const Frabjous& f) : glip(g), Frabjous(f) {
    }
    void tell() {
        Frabjous::tell();
        std::cout << glip << std::endl;
    }
};

#endif  // !__GLOAM_FRABJOUS_H__

int main(int argc, char* argv[]) {
    Gloam g1;
    g1.tell();
    Frabjous f1("Python");
    Gloam g2(2, f1);
    g2.tell();
    return 0;
}
