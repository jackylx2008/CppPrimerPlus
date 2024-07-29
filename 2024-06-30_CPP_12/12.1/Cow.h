#ifndef __COW_H__
#define __COW_H__

class Cow {
    char name[20];
    char* hobby;
    double weight;

  public:
    Cow();
    Cow(const char* nm, const char* ho, double wt);
    Cow(const Cow& c);
    ~Cow();
    Cow& operator=(const Cow& c);
    void ShowCow() const;  // display all cow data
};

#endif  // !__COW_H__
