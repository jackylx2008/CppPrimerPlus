#ifndef __GOLF_H__
#define __GOLF_H__
class Golf {
  private:
    static const int LEN = 40;
    char fullname[LEN];
    int hc;

  public:
    Golf() {
        fullname[0] = '\0';
        hc = 0;
    }
    Golf(const char *fullname, int hc);
    void handicap(int hc);
    void showgolf() const;
};

#endif  // !__GOLF_H__
