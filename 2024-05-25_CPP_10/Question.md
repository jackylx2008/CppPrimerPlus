1. 为复习题5描述的类提供方法定义，并编写一个小程序来演示所有的特性。
1. Provide method definitions for the class described in Chapter Review Question 5 and write a short program that illustrates all the features.

```cpp BankAccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>

using namespace std;

class BankAccount
{
private:
    std::string name_str;
    std::string accountNum_str;
    double balance;

public:
    BankAccount(const string &name, const string &accountNum, double bal = 0.0);
    void show();
    void deposit(double cash);
    void withdraw(double cash);
};
#endif
```

2. 下面是一个非常简单的类定义
2. Here is a rather simple class definition:

```cpp
class Person
{
private:
    static const int LIMIT = 25;
    string lname;      // Person’s last name
    char fname[LIMIT]; // Person’s first name
public:
    Person()
    {
        lname = "";
        fname[0] = '\0';
    }                                                    // #1
    Person(const string &ln, const char *fn = "Heyyou"); // #2
    // the following methods display lname and fname
    void Show() const;       // firstname lastname format
    void FormalShow() const; // lastname, firstname format
};
```

它使用了一个string对象和一个字符数组，让您能够比较它们的用法。请提供未定义的方法的代码，以完成这个类的实现。再编写一个使用这个类的程序，它使用了三种可能的构造函数的调用（没有参数、一个参数和两个参数）以及两种显示方法。下面是一个使用这些构造函数和方法的例子：
(It uses both a `string` object and a character array so that you can compare how the two forms are used.) Write a program that completes the implementation by providing code for the undefined methods.The program in which you use the class should also use the three possible constructor calls (no arguments, one argument, and two arguments) and the two display methods. Here’s an example that uses the constructors and methods:

```cpp
Person one;                      // use default constructor
Person two("Smythecraft");       // use #2 with one default argument
Person three("Dimwiddy", "Sam"); // use #2, no defaults one.Show();
cout << endl;
one.FormalShow();
// etc. for two and three
```

3. 完成第9章的编程练习1，但要用正确的golf类声明替换那里的代码。用带合适参数的构造函数替换`setgolf(golf &, const char *, int)`，以提供初始值。保留setgolf()的交互版本，但要用构造函数来实现它（例如，setgolf()的代码应该获得数据，将数据传递给构造函数来创建一个临时对象，并将其赋给调用对象，即`*this`）。
3. Do Programming Exercise1 from Chapter 9 but replace the code shown there with an appropriate `golf` class declaration. Replace `setgolf(golf &, const char*,int)` with a constructor with the appropriate argument for providing initial values. Retain the interactive version of setgolf() but implement it by using the con- structor. (For example, for the code for setgolf(), obtain the data, pass the data to the constructor to create a temporary object, and assign the temporary object to the invoking object, which is `*this`.)

4. 完成第9章的编程练习4，但将Sales结构及相关的函数转换为一个类及其方法。用构造函数替换setSales(sales &,  double [], int)函数。用构造函数实现setSales(Slaes &)方法的交互版本。将类保留在名称空间SALES 中。

4. Do Programming Exercise 4 from Chapter 9 but convert the Sales structure and its associated functions to a class and its methods. Replace the `setSales(Sales &, double [], int)` function with a constructor. Implement the interactive `setSales(Sales &)` method by using the constructor. Keep the class within the namespace SALES.

5. 考虑下面的结构声明：
5. Consider the following structure declaration:

```cpp
struct customer {
char fullname[35];
double payment;
};
```

编写一个程序，它从栈中添加和删除`customer`结构（栈用Stack类声明表示）。每次`customer`结构被删除时，其payment的值都被加入到总数中，并报告总数。注意：应该可以直接使用`Stack`类而不作修改；只需修改`typedef`声明，使`Item`的类型为`customer`，而不是`unsigned long`即可.
Write a program that adds and removes customer structures from a stack, represented by a Stack class declaration. Each time a customer is removed, his or her payment should be added to a running total, and the running total should be reported. Note: You should be able to use the Stack class unaltered; just change the typedef declaration so that Item is type customer instead of unsigned long.

6.下面是一个类声明:
6. Here’s a class declaration:

```cpp

class Move { 
  private:
    double x;
    double y; public:
    Move(double a = 0, double b = 0); 
    showmove() const;
    Move add(const Move & m) const;
    // sets x, y to a, b
    // shows current x, y values
    // this function adds x of m to x of invoking object to get new x, 
    // adds y of m to y of invoking object to get new y, creates a new 
    // move object initialized to new x, y values and returns it
    reset(double a = 0, double b = 0); // resets x,y to a, b };
```

请提供成员函数的定义和测试这个类的程序。
Create member function definitions and a program that exercises the class.

7.Betelgeusean plorg有这些特征。
  数据:
  plorg的名称不超过19个字符; plorg有满意指数(CI)，这是一个整数。
  操作:
  新的plorg将有名称，其CI值为50; plorg的CI可以修改; plorg可以报告其名称和CI; plorg的默认名称为“Plorga”。
  请编写一个Plorg类声明(包括数据成员和成员函数原型)来表示 plorg，并编写成员函数的函数定义。然后编写一个小程序，以演示 Plorg类的所有特性。
7. A Betelgeusean plorg has these properties:
  Data
  A plorg has a name with no more than 19 letters.
  A plorg has a contentment index (CI), which is an integer. Operations
  A new plorg starts out with a name and a CI of 50.
  A plorg’s CI can change.
  A plorg can report its name and CI.
  The default plorg has the name "'Plorga'".
  Write a 'Plorg' class declaration (including data members and member function pro- totypes) that represents a plorg.Write the function definitions for the member func- tions.Write a short program that demonstrates all the features of the 'Plorg' class.

8. 可以将简单列表描述成下面这样：
  可存储0或多个类型的列表；
  可创建空列表
  可在列表中添加数据项；
  可确定列表是否为空；
  可确定列表是否已满；
  可访问列表中每一个数据项，并对它执行某种操作。
  可以看到，这个列表确实很简单，例如它不允许插入或删除数据项。
  请设计一个List类来表示这中数据类型。您应提供头文件list.h和实现文件list.cpp.前者包含定义，后者包含实现这个类的方法。您还应创建一个简短的程序来实现这个类。
  该表的规范很简单，这主要旨在简化这个编程练习，可以选择使用数组或链表来实现这个列表，但公有结构不应依赖与说做的选择。也就是说，公有接口不应有数组索引，节点指针等。应使用通用概念来表达创建列表、在列表中添加数据项等操作。对于访问数据项以及执行操作，通常应使用将函数指针做为参数的函数来处理：
  `void visit(void (*pf) (Item&));`
  其中，`pf`指向一个将`Item`引用作为参数的函数（不是成员函数），`Item`是列表中数据项的类型，`visit()`函数将该函数用于列表中的每个数据项。
