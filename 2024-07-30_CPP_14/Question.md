# 2024-08-15_C++ Primer Plus Chapter 13

1.`Wine`类有一个`string`类对象成员（参见第4章）和一个`Pair`对象（参见本章）；其中前者用于存储葡萄酒的名称，而后者有2个`valarray<int>`对象（参见本章），这两个`valarray<int>`对象分别保存了葡萄酒的酿造年份和该年生产的瓶数。例如，`Pair`的第1个`valarray<int>`对象可能为1988、1992和1996年，第2个`valarray<int>`对象可能为24、48和144瓶。Wine最好有1个int成员用于存储年数。另外，一些`typedef`可能有助于简化编程工作：
The `Wine` class has a `string` class object member (see Chapter 4) that holds the name of a wine and a `Pair` object (as discussed in this chapter) of `valarray<int>` objects (as discussed in this chapter).The first member of each `Pair` object holds the vintage years, and the second member holds the numbers of bottles owned for the corresponding particular vintage year. For example, the first `valarray` object of the `Pair` object might hold the years 1988, 1992, and 1996, and the second `valarray` object might hold the bottle counts 24, 48, and 144. It may be convenient for `Wine` to have an int member that stores the number of years. Also some `typedef`s might be useful to simplify the coding:

```cpp
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;
```

这样，`PairArray`表示`Pair<std::valarray<int>`,`std::valarray<int>>`。使用包含来实现`Wine`类，并用一个简单的程序对其进行测试。`Wine`类应该有一个默认构造函数以及如下构造函数：

```cpp
// initialize label to l, number of years to y,
// vintage years to yr[], bottles to bot[]
Wine(const char * l, int y, const int yr[], const int bot[]);
// initialize label to l, number of years to y,
// create array objects of length y
Wine(const char * l, int y);
```

`Wine`类应该有一个`GetBottles()`方法，它根据Wine对象能够存储几种年份`（y）`，提示用户输入年份和瓶数。方法`Label()`返回一个指向葡萄酒名称的引用。`sum()`方法返回`Pair`对象中第二个`valarray<int>`对象中的瓶数总和。测试程序应提示用户输入葡萄酒名称、元素个数以及每个元素存储的年份和瓶数等信息。程序将使用这些数据来构造一个Wine对象，然后显示对象中保存的信息。

下面是一个简单的测试程序：

```cpp
// pe14-1.cpp -- using Wine class with containment
#include <iostream>
#include "winec.h"
int main ( void )
{
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;
    Wine holding(lab, yrs); // store label, years, give arrays yrs elements
    holding.GetBottles(); // solicit input for year, bottle count
    holding.Show(); // display object contents
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = { 48, 60, 72};
    // create new object, initialize using data in arrays y and b
    Wine more("Gushing Grape Red",YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label() // use Label() method
        << ": " << more.sum() << endl; // use sum() method
    cout << "Bye\n";
    return 0;
}
```

下面是该程序的运行情况：

```bash
Enter name of wine: Gully Wash
Enter number of years: 4
Enter Gully Wash data for 4 year(s):
Enter year: 1988
Enter bottles for that year: 42
Enter year: 1994
Enter bottles for that year: 58
Enter year: 1998
Enter bottles for that year: 122
Enter year: 2001
Enter bottles for that year: 144
Wine: Gully Wash
Year Bottles
1988 42
1994 58
1998 122
2001 144
Wine: Gushing Grape Red
Year Bottles
1993 48
1995 60
1998 72
Total bottles for Gushing Grape Red: 180
Bye
```
