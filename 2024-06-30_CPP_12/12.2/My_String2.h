#include <istream>
#include <ostream>

class My_String2 {
  private:
    char *str;
    int len;

  public:
    static const int CINLIM = 100;
    My_String2();
    My_String2(const My_String2 &s);
    My_String2(const char *s);
    ~My_String2();
    My_String2 &operator=(const My_String2 &s);
    My_String2 &operator=(const char *s);
    My_String2 &operator+(const My_String2 &s);
    My_String2 &operator+(const char *s);
    const char &operator[](int i) const;
    bool operator==(const My_String2 &s);
    void stringup();
    void stringlow();
    int has(const char c);
    friend std::ostream &operator<<(std::ostream &os, const My_String2 &my_s);
    friend std::istream &operator>>(std::istream &is, My_String2 &my_s);
    friend My_String2 operator+(const char *s, const My_String2 &my_s);
};
