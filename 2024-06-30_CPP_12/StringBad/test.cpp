#include <iostream>
#include <ostream>

class Testing {
  private:
    int m_i;
    int m_n;

  public:
    Testing(const int& i = 0, int n = 0) {
        m_i = i;
        m_n = n;
    }
    void show(void);
    void set(int i, int n);
    ~Testing() {
        std::cout << m_i << "  " << m_n << " Testing destoryed\n";
    }
};

void Testing::show(void) {
    std::cout << "i = " << m_i << " n = " << m_n << std::endl;
}

void Testing::set(int i, int n) {
    m_i = i;
    m_n = n;
}

int main(int argc, char* argv[]) {
    Testing* t = new Testing(100, 10);
    t->show();
    t->set(1000, 2000);
    t->show();
    Testing t2(100, 100);
    // delete t;
    return 0;
}
