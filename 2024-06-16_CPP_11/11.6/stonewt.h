#ifndef STONEWT_H_
#define STONEWT_H_

#include <ostream>
class Stonewt {
  private:
    static const int Lbs_per_stn = 14;
    int stone;
    double pds_left;
    double pounds;

  public:
    enum Mode {
        STONE,
        INTEGER_POUNDS,
        FLOATING_POUNDS,
    };
    Mode form;
    explicit Stonewt(double lbs);
    Stonewt(int stn, double lbs, Mode form = STONE);
    Stonewt();
    ~Stonewt();
    Mode get_stat() const;
    void set_stat(Mode form = STONE);
    double get_stone() const;
    double get_pounds() const;
    double get_pds_left() const;
    Stonewt operator+(const Stonewt& s) const;
    Stonewt operator-(const Stonewt& s) const;
    Stonewt operator*(const double multi) const;
    bool operator<(const Stonewt& s) const;
    bool operator<=(const Stonewt& s) const;
    bool operator>(const Stonewt& s) const;
    bool operator>=(const Stonewt& s) const;
    bool operator==(const Stonewt& s) const;
    bool operator!=(const Stonewt& s) const;
    friend std::ostream& operator<<(std::ostream& os, const Stonewt st);
    friend Stonewt operator*(const double multi, const Stonewt& s);
};
#endif
