#ifndef __WINE_PRIVATE_H__
#define __WINE_PRIVATE_H__

#include <string>
#include <valarray>

typedef std::valarray<int> ArrayInt;

template <typename T1, typename T2>
class PairArray {
  private:
    T1 year;
    T2 bottles;
    int yrs;

  public:
    PairArray<ArrayInt, ArrayInt>(int y, const int yr[], const int bot[]) {
        yrs = y;
        year = ArrayInt(yr, yrs);
        bottles = ArrayInt(bot, yrs);
    }
    void Show(int i) const;
    int Bottles(int i) const;
    void SetBottles(int y, const int yr[], const int bot[]);
};
class Wine : private std::string, private PairArray<ArrayInt, ArrayInt> {
  private:
    int years;
    int* year;
    int* bottles;

  public:
    Wine(const char* str, int y);
    Wine(const char* str, int y, const int yr[], const int bot[]);
    // Wine(const Wine&);
    // Wine& operator=(const Wine&);
    ~Wine() {
        delete[] year;
        delete[] bottles;
    }
    void Show() const;
    const std::string& Label() const;
    int sum() const;
    void GetBottles();
};

#endif  // !__WINE_PRIVATE_H__
