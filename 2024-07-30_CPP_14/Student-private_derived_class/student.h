#ifndef __STUDENT_VALARRAY_H__
#define __STUDENT_VALARRAY_H__

#include <string>
#include <valarray>

class Student : private std::string, private std::valarray<double> {
  private:
  public:
    Student() : std::string("Null"), std::valarray<double>() {
    }
    explicit Student(const std::string name, int n)
        : std::string(name), std::valarray<double>(n) {
    }
    explicit Student(int n) : std::string("Null"), std::valarray<double>(n) {
    }
    explicit Student(const std::string& name,
                     const std::valarray<double>& scores)
        : std::string(name), std::valarray<double>(scores) {
    }
    Student(std::string name, const double* pd, int n)
        : std::string(name), std::valarray<double>(pd, n) {
    }
    Student(const Student& s)
        : std::string((const std::string&)s),
          std::valarray<double>((const std::valarray<double>&)s) {
    }

    ~Student() {
    }
    double Average() const;
    const std::string& get_Name() const {
        return (const std::string&)(*this);
    }
    std::ostream& show_Scores(std::ostream& os) const;
    // Student& operator=(const Student& s);
    double& operator[](int n);
    const double operator[](int n) const;
    friend std::istream& operator>>(std::istream& is, Student& s);
    friend std::istream& getline(std::istream& is, Student& s);
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};

#endif  // !__STUDENT_VALARRAY_H__
