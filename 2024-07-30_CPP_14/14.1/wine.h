#ifndef __WINE_H__
#define __WINE_H__

#include <string>
#include <valarray>

typedef std::valarray<int> ArrayInt;

template <typename T1, typename T2>
class Pair {
  private:
    T1 year;
    T2 bottles;

  public:
    // Pair<T1, T2>(T1 y, T2 b) {
    //     year = y, bottles = b;
    // }
    Pair<ArrayInt, ArrayInt>(int y, const int yr[], const int bot[]) {
        year = ArrayInt(yr, y);
        bottles = ArrayInt(bot, y);
    }
    void Show(int i) const;
    int Bottles(int i) const;
};
class Wine {
  private:
    Pair<ArrayInt, ArrayInt> years_bottles;
    std::string name;
    int years;
    int* year;
    int* bottles;

  public:
    Wine(const std::string str, int y);
    Wine(const std::string str, int y, const int yr[], const int bot[]);
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

#endif  // !__WINE_H__
