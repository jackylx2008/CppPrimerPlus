# 2024-07-14_C++ Primer Plus Chapter 13

1. 以下面的类声明为基础：
1. Start with the following class declaration:

```cpp
// base class
class Cd { // represents a CD disk
    private:
    char performers[50];
    char label[20];
    int selections; // number of selections
    double playtime; // playing time in minutes
    public:
    Cd(char * s1, char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    ~Cd();
    void Report() const; // reports all CD data
    Cd & operator=(const Cd & d);
};
```

派生出一个Classic类，并添加一组char成员，用于存储指出CD中主要作品的字符串。修改上述声明，使基类的所有函数都是虚的。如果上述定义声明的某个方法并不需要，则请删除它。使用下面的程序测试您的产品：
Derive a Classic class that adds an array of char members that will hold a string identifying the primary work on the CD. If the base class requires that any functions be virtual, modify the base-class declaration to make it so. If a declared method is not needed, remove it from the definition.Test your product with the following program:

```cpp
#include <iostream>
using namespace std;
#include "classic.h" // which will contain #include cd.h
void Bravo(const Cd & disk);
int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);
    Cd *pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report(); // use Cd method
    c2.Report(); // use Classic method
    cout << "Using type cd * pointer to objects:\n";
    pcd->Report(); // use Cd method for cd object
    pcd = &c2;
    pcd->Report(); // use Classic method for classic object
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}
void Bravo(const Cd & disk)
{
    disk.Report();
}
```

2. 完成练习1，但让两个类使用动态内存分配而不是长度固定的数组来记录字符串。
2. Do Programming Exercise 1 but use dynamic memory allocation instead of fixed- size arrays for the various strings tracked by the two classes.

3. 修改`baseDMA-lacksDMA-hasDMA`类层次，让三个类都从一个ABC派生而来，然后使用与程序清单13.10相似的程序对结果进行测试。也就是说，它应使用ABC指针数组，并让用户决定要创建的对象类型。在类定义中添加virtual `View()`方法以处理数据显示。
3. Revise the `baseDMA-lacksDMA-hasDMA` class hierarchy so that all three classes are derived from an ABC.Test the result with a program similar to the one in Listing 13.10.That is, it should feature an array of pointers to the ABC and allow the user to make runtime decisions as to what types of objects are created.Add virtual `View()` methods to the class definitions to handle displaying the data.
