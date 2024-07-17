#include <cstring>
#include <iostream>

struct People {
    int age;
    char name[40];
    // std::string name;
};

People operator+(const People& p1, const People& p2) {
    People sum;
    sum.age = p1.age + p2.age;
    return sum;
}

class Time {
  private:
    int miniuts;
    int hour;

  public:
    Time();
    Time(int h, int m);
    Time operator*(double multi) const;
    friend Time operator*(double multi, const Time& t);
    void Show(void) const;
};

Time::Time(int h, int m) {
    miniuts = m;
    hour = h;
}

Time::Time() {
    miniuts = 0;
    hour = 0;
}

Time Time::operator*(double multi) const {
    Time result;
    result.miniuts = multi * hour * 60 + multi * miniuts;
    result.hour = result.miniuts / 60;
    result.miniuts = result.miniuts % 60;
    return result;
}

void Time::Show(void) const {
    std::cout << "hours = " << hour << "mins = " << miniuts << std::endl;
}

Time operator*(double multi, const Time& t) {
    Time result;
    result = t * multi;
    return result;
}

int main(int argc, char* argv[]) {
    People p1 = {10, "liu"};
    People p2 = {20, "xin"};
    People p3;
    p3.age = 50;
    p3 = p1 + p2;
    strcpy(p3.name, "luo");
    std::cout << p3.age << std::endl;
    std::cout << p3.name << std::endl;

    Time t(2, 40);
    Time result;
    result = t * 1.5;
    result.Show();
    result = 1.5 * t;
    result.Show();

    return 0;
}
