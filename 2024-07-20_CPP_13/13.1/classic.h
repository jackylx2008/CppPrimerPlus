#ifndef __CLASSIC_H__
#define __CLASSIC_H__

class Cd {  // represents a CD disk
  private:
    char performers[50];
    char label[20];
    int selections;   // number of selections
    double playtime;  // playing time in minutes

  public:
    Cd();
    Cd(const char* s1, const char* s2, int n, double x);
    Cd(const Cd& d);
    virtual ~Cd();
    virtual void Report() const;  // reports all CD data
    Cd& operator=(const Cd& d);
};

class Classic : public Cd {
  private:
    char primary_works[50];

  public:
    Classic();
    Classic(const char* s1, const char* s2, const char* s3, int n, double x);
    Classic(const Classic& c);
    virtual ~Classic();
    virtual void Report() const;  // reports all Classic data
    Classic& operator=(const Classic& c);
};

#endif  // !__CLASSIC_H__
