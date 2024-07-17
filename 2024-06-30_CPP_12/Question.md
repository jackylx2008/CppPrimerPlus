# 2024-07-14_C++ Primer Plus Chapter 12

1. 对于下面的类声明：

```cpp
class Cow {
    char name[20];
    char *hobby;
    double weight;
  public:
    Cow();
    Cow(const char* nm, const char * ho, double wt);
    Cow(const Cow& c);
    ~Cow();
    Cow & operator=(const Cow & c);
    void ShowCow() const; // display all cow data
};
```

给这个类提供实现，并编写一个使用所有成员函数的小程序。

1. Consider the following class declaration:

```cpp

class Cow {
char name[20];
char *hobby;
double weight; public:
Cow();
Cow(const char* nm, const char * ho, double wt); Cow(const Cow c&);
                                        ~Cow();
Cow & operator=(const Cow & c);
void ShowCow() const; // display all cow data
};
```

Provide the implementation for this class and write a short program that uses all the member functions.

2. 通过下面的工作来改进String类声明（即将String1.h升级为String2.h）。
a. 对+运算符进行重载，使之可将两个字符串合并成一个。
b. 提供一个Stringlow()成员函数，将字符串中所有的字母字符转换为小写（别忘了cctype系列字符函数）。
c. 提供String()成员函数，将字符串中所有字母字符转换成大写。
d. 提供一个这样的成员函数，它接受一个char参数，返回该字符在字符串中出现的次数。
使用下面的程序来测试您的工作：
2. Enhance the String class declaration (that is, upgrade string1.h to string2.h) by doing the following:
a. Overload the + operator to allow you to join two strings into one.
b. Provide a stringlow() member function that converts all alphabetic charac- ters in a string to lowercase. (Don’t forget the cctype family of character functions.)
c. Provide a stringup() member function that converts all alphabetic characters in a string to uppercase.
d. Provide a member function that takes a char argument and returns the number of times the character appears in the string.
Test your work in the following program:

```cpp
// pe12_2.cpp
#include <iostream>
using namespace std;
#include "string2.h"
int main()
{
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    cout << s2; // overloaded << operator
    cin >> s3; // overloaded >> operator
    s2 = "My name is " + s3; // overloaded =, + operators
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup(); // converts string to uppercase
    cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
        << " 'A' characters in it.\n";
    s1 = "red"; // String(const char *),
    // then String & operator=(const String&)
    String rgb[3] = { String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringlow(); // converts string to lowercase
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i]) // overloaded == operator
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "Bye\n";
    return 0;
}
```

输出应与下面相似：
Your output should look like this sample run:

```
Please enter your name: Fretta Farbo
My name is Fretta Farbo.
The string
MY NAME IS FRETTA FARBO AND I AM A C++ STUDENT.
contains 6 'A' characters in it.
Enter the name of a primary color for mixing light: yellow
Try again!
BLUE
That's right!
Bye
```

3. 新编写程序清单10.7和程序清单10.8描述的Stock类，使之使用动态分配的内存，而不是string类对象来存储股票名称。另外，使用重载的`operator<<()`定义代替`show()`成员函数。再使用程序清单10.9测试新的定义程序。
3. Rewrite the Stock class, as described in Listings 10.7 and 10.8 in Chapter 10 so that it uses dynamically allocated memory directly instead of using string class objects to hold the stock names. Also replace the `show()` member function with an overloaded `operator<<()` definition.Test the new definition program in Listing 10.9.

4. 请看下面程序清单10.10定义的Stack类的变量：
4. Consider the following variation of the Stack class defined in Listing 10.10:

```cpp
// stack.h -- class declaration for the stack ADT
typedef unsigned long Item;
class Stack
{
    private:
    enum {MAX = 10}; // constant specific to class
    Item * pitems; // holds stack items
    int size; // number of elements in stack
    int top; // index for top stack item
    public:
    Stack(int n = MAX); // creates stack with n elements
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item); // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item & item); // pop top into item
    Stack & operator=(const Stack & st);
};
```

正如私有成员表明的，这个类使用动态分配的数组来保存栈项。请重新编写方法，以适应这种新的表示法，并编写一个程序来演示所有的方法，包括复制构造函数和赋值运算符。
As the private members suggest, this class uses a dynamically allocated array to hold the stack items. Rewrite the methods to fit this new representation and write a program that demonstrates all the methods, including the copy constructor and assignment operator.

5. Heather银行进行的研究表明，ATM客户不希望排队时间超过1分钟。使用程序清单12.10中的模拟，找出要使平均等候时间为1分钟，每小时到达的客户数应为多少（试验时间不短于100小时）？
5. The Bank of Heather has performed a study showing that ATM customers won’t wait more than one minute in line. Using the simulation from Listing 12.10, find a value for number of customers per hour that leads to an average wait time of one minute. (Use at least a 100-hour trial period.)
