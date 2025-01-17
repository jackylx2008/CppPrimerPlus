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

4. Benevolent Order of Programmers用来维护瓶装葡萄酒箱。为描述它，BOP Portmaster设置了一个`Port`类，其声明如下
4. The Benevolent Order of Programmers maintains a collection of bottled port.To describe it, the BOP Portmaster has devised a `Port` class, as declared here:

```cpp
#include <iostream>
using namespace std;
class Port
{
    private:
    char * brand;
    char style[20]; // i.e., tawny, ruby, vintage
    int bottles;
    public:
    Port(const char * br = "none", const char * st = "none", int b = 0);
    Port(const Port & p); // copy constructor
    virtual ~Port() { delete [] brand; }
    Port & operator=(const Port & p);
    Port & operator+=(int b); // adds b to bottles
    Port & operator-=(int b); // subtracts b from bottles, if available
    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend ostream & operator<<(ostream & os, const Port & p);
   };
```

`Show()`方法按下面的格式显示信息：
The `Show()` method presents information in the following format:

```sh

Brand: Gallo
Kind: tawny
Bottles: 20
```

`operator<<()`函数按下面的格式显示信息（末尾没有换行符）：
The `operator<<()` function presents information in the following format (with no newline character at the end):

```sh
Gallo, tawny, 20
```

PortMaster完成了`Port`类的方法定义后派生了`VintagePort`类，然后被解职——因为不小心将一瓶45度Cockburn泼到了正在准备烤肉调料的人身上，VintagePort类如下所示：
The Portmaster completed the method definitions for the `Port` class and then derived the `VintagePort` class as follows before being relieved of his position for accidentally routing a bottle of ’45 Cockburn to someone preparing an experimental barbecue sauce:

```cpp
class VintagePort : public Port // style necessarily = "vintage"
{
    private:
    char *nickname; // i.e., "The Noble" or "Old Velvet", etc.
    int year; // vintage year
    public:
    VintagePort();
    VintagePort(const char* br, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() { delete [] nickname; }
    VintagePort & operator=(const VintagePort & vp);
    void Show() const;
    friend ostream & operator<<(ostream & os, const VintagePort & vp);
};
```

您被指定负责完成`VintagePort`。
a. 第一个任务是重新创建`Port`方法定义，因为前任被开除时销毁了方法定义。
b. 第二个任务是解释为什么有的方法重新定义了，而有些没有重新定义。
c. 第三个任务是解释为何没有将`operator=()`和`operator<<()`声明为虚的。
d. 第四个任务是提供`VintagePort`中各个方法的定义。
You get the job of completing the `VintagePort` work.
a. Your first task is to re-create the `Port` method definitions because the former
Portmaster immolated his upon being relieved.
b. Yoursecondtaskistoexplainwhycertainmethodsareredefinedandothers are not.
c. Your third task is to explain why `operator=()` and `operator<<()` are not virtual.
d. Your fourth task is to provide definitions for the `VintagePort` methods.
