#ifndef __STUDENT_VALARRAY_H__
#define __STUDENT_VALARRAY_H__

#include <string>
#include <valarray>

class Student {
  private:
    std::string Name;
    std::valarray<double> Scores;

  public:
    Student() : Name("Null"), Scores() {}
    explicit Student(const std::string name, int n) : Name(name), Scores(n) {}
    explicit Student(int n) : Name("Null"), Scores(n) {}
    explicit Student(const std::string& name,
                     const std::valarray<double>& scores)
        : Name(name), Scores(scores) {}
    Student(std::string name, const double* pd, int n)
        : Name(name), Scores(pd, n) {}
    Student(const Student& s) {
        Name = s.Name;
        Scores = s.Scores;
    }
    ~Student() {}
    double Average() const;
    const std::string& get_Name() const {
        return Name;
    }
    Student& operator=(const Student& s);
    double& operator[](int n);
    const double operator[](int n) const;
    friend std::istream& operator>>(std::istream& is, Student& s);
    friend std::istream& getline(std::istream& is, Student& s);
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};

#endif  // !__STUDENT_VALARRAY_H__
