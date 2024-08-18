# 2024-08-15_C++ Primer Plus Chapter 14

1.`Wine`类有一个`string`类对象成员（参见第4章）和一个`Pair`对象（参见本章）；其中前者用于存储葡萄酒的名称，而后者有2个`valarray<int>`对象（参见本章），这两个`valarray<int>`对象分别保存了葡萄酒的酿造年份和该年生产的瓶数。例如，`Pair`的第1个`valarray<int>`对象可能为1988、1992和1996年，第2个`valarray<int>`对象可能为24、48和144瓶。Wine最好有1个int成员用于存储年数。另外，一些`typedef`可能有助于简化编程工作：
The `Wine` class has a `string` class object member (see Chapter 4) that holds the name of a wine and a `Pair` object (as discussed in this chapter) of `valarray<int>` objects (as discussed in this chapter).The first member of each `Pair` object holds the vintage years, and the second member holds the numbers of bottles owned for the corresponding particular vintage year. For example, the first `valarray` object of the `Pair` object might hold the years 1988, 1992, and 1996, and the second `valarray` object might hold the bottle counts 24, 48, and 144. It may be convenient for `Wine` to have an int member that stores the number of years. Also some `typedef`s might be useful to simplify the coding:

```cpp
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;
```

这样，`PairArray`表示`Pair<std::valarray<int>`,`std::valarray<int>>`。使用包含来实现`Wine`类，并用一个简单的程序对其进行测试。`Wine`类应该有一个默认构造函数以及如下构造函数：
Thus, the `PairArray` type represents type `Pair<std::valarray<int>, std::valarray<int> >`. Implement the `Wine` class by using containment.The class should have a default constructor and at least the following constructors:

```cpp
// initialize label to l, number of years to y,
// vintage years to yr[], bottles to bot[]
Wine(const char * l, int y, const int yr[], const int bot[]);
// initialize label to l, number of years to y,
// create array objects of length y
Wine(const char * l, int y);
```

`Wine`类应该有一个`GetBottles()`方法，它根据`Wine`对象能够存储几种年份`y`，提示用户输入年份和瓶数。方法`Label()`返回一个指向葡萄酒名称的引用。`sum()`方法返回`Pair`对象中第二个`valarray<int>`对象中的瓶数总和。
测试程序应提示用户输入葡萄酒名称、元素个数以及每个元素存储的年份和瓶数等信息。程序将使用这些数据来构造一个`Wine`对象，然后显示对象中保存的信息。
下面是一个简单的测试程序：
The `Wine` class should have a method `GetBottles()` that, given a `Wine` object with `y` years, prompts the user to enter the corresponding number of vintage years and bottle counts. A method `Label()` should return a reference to the wine name. A method `sum()` should return the total number of bottles in the second `valarray<int>` object in the `Pair` object.
The program should prompt the user to enter a wine name, the number of elements of the array, and the year and bottle count information for each array element.The program should use this data to construct a Wine object and then display the information stored in the object. For guidance, here’s a sample test program:

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
And here’s some sample output:

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

2. 采用私有继承而不是包含来完成编程练习1。同样，一些typedef可能会有所帮助，另外，您可能还需要考虑诸如下面这样的语句的含义：
2. This exercise is the same as Programming Exercise1,except that you should use private inheritance instead of containment.Again,a few `typedef`s might prove handy. Also you might contemplate the meaning of statements such as the following:

```cpp
PairArray::operator=(PairArray(ArrayInt(),ArrayInt()));
cout << (const string &)(*this);
```

您设计的类应该可以使用编程练习1中的测试程序进行测试。
The class should work with the same test program as shown in Programming Exercise 1

3. 定义一个`QueueTp`模板。然后在一个类似于程序清单14.12的程序中创建一个指向`Worker`的指针队列（参见程序清单14.10中的定义），并使用该队列来测试它。
3. Define a `QueueTp` template.Test it by creating a queue of pointers-to-`Worker`(as defined in Listing 14.10) and using the queue in a program similar to that in Listing 14.12.

4. `Person`类保存人的名和姓。除构造函数外，它还有`Show()`方法，用于显示名和姓。`Gunslinger`类以`Person`类为虚基类派生而来，它包含一个`Draw()`成员，该方法返回一个`double`值，表示枪手的拔枪时间。这个类还包含一个`int`成员，表示枪手枪上的刻痕数。最后，这个类还包含一个`Show()`函数，用于显示所有这些信息。`PokerPlayer`类以`Person`类为虚基类派生而来。它包含一个`Draw()`成员，该函数返回一个1～52的随机数，用于表示扑克牌的值（也可以定义一个`Card`类，其中包含花色和面值成员，然后让`Draw()`返回一个`Card`对象）。
`PokerPlayer`类使用`Person`类的`show()`函数。`BadDude()`类从`Gunslinger`和`PokerPlayer`类公有派生而来。它包含`Gdraw()`成员（返回坏蛋拔枪的时间）和`Cdraw()`成员（返回下一张扑克牌），另外还有一个合适的`Show()`函数。请定义这些类和方法以及其他必要的方法（如用于设置对象值的方法），并使用一个类似于程序清单14.12的简单程序对它们进行测试。
4. A `Person` class holds the first name and the last name of a person. In addition to its constructors, it has a `Show()` method that displays both names.A `Gunslinger` class derives virtually from the Person class. It has a `Draw()` member that returns a type `double` value representing a gunslinger’s draw time.The class also has an int member representing the number of notches on a gunslinger’s gun. Finally, it has a `Show()` function that displays all this information.
A `PokerPlayer` class derives virtually from the `Person` class. It has a `Draw()` member that returns a random number in the range 1 through 52, representing a card value. (Optionally, you could define a Card class with suit and face value members and use a Card return value for `Draw()`.) The `PokerPlayer` class uses the Person `show()` function.The `BadDude` class derives publicly from the `Gunslinger` and `PokerPlayer` classes. It has a `Gdraw()` member that returns a bad dude’s draw time and a `Cdraw()` member that returns the next card drawn. It has an appropriate `Show()` function. Define all these classes and methods, along with any other necessary methods (such as methods for setting object values) and test them in a simple program similar to that in Listing 14.12.
