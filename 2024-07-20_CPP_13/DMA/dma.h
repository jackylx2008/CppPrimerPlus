#ifndef __DMA_H__
#define __DMA_H__

#include <ostream>

class BaseDma {
  protected:
    char* str = nullptr;
    int num;

  public:
    explicit BaseDma(const char* s = "", int n = 0);
    BaseDma(const BaseDma& ba);
    BaseDma& operator=(const BaseDma& ba);
    virtual ~BaseDma();
    friend std::ostream& operator<<(std::ostream& os, const BaseDma& ba);
};

class Derived_Ba : public BaseDma {
  private:
    int m_m;

  public:
    explicit Derived_Ba(const char* s = "", int n = 0, int m = 0);
    Derived_Ba(const BaseDma& ba, int m);
    Derived_Ba(const Derived_Ba& da);
    virtual ~Derived_Ba() {
    }
    friend std::ostream& operator<<(std::ostream& os, const Derived_Ba& da);
};
class Derived_New : public BaseDma {
  private:
    char* new_str = nullptr;

  public:
    explicit Derived_New(const char* s = "null", int n = 0,
                         const char* ns = "null");
    Derived_New(const BaseDma& ba, const char* ns);
    Derived_New(const Derived_New& dn);
    Derived_New& operator=(const Derived_New& dn);
    virtual ~Derived_New();
    friend std::ostream& operator<<(std::ostream& os, const Derived_New& dn);
};

#endif  // !__DMA_H__
