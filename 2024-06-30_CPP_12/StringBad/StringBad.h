#ifndef __STRINGBAD_H__
#define __STRINGBAD_H__
#include <ostream>

class StringBad {
  private:
    unsigned int len;
    char *str;

  public:
    static int num_strings;
    StringBad();
    explicit StringBad(const char *s);
    // StringBad(StringBad &&);
    StringBad(const StringBad &s);
    // StringBad &operator=(StringBad &&);
    StringBad &operator=(const StringBad &s);
    StringBad &operator=(const char *s);
    const char &operator[](int i) const;
    ~StringBad();
    int get_num_strings(void) {
        return num_strings;
    }

    friend std::ostream &operator<<(std::ostream &os, StringBad &s);
};

#endif  // !__STRINGBAD_H__
