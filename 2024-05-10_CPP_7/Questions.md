# C++ Primer Plus（第六版）编程练习答案 第7章 函数——C++的编程模块

1. 编写一个程序，不断要求用户输入两个数，直到其中的一个为0。对于每两个数，程序将使用一个函数来计算它们的调和平均数，并将结果返回给main()，而后者将报告结果。调和平均数指的是倒数平均值的倒数，计算公式如下：

```latex
调和平均数=2.0*x*y/(x+y)
```

2. 编写一个程序，要求用户输入最多10个高尔夫成绩，并将其存储在一个数组中。程序允许用户提早结束输入，并在一行上显示所有成绩，然后报告平均成绩。请使用3个数组处理函数来分别进行输入、显示和计算平均成绩。

3. 下面是一个结构声明：

```cpp

struct box
{
    char marker[40];
    float height;
    float width;
    float length;
    float volume;
};
```

a.编写一个函数，按值传递box结构，并显示每个成员的的值。
b.编写一个函数，传递box结构的地址，并将volume成员设置为其他三维长度的乘积。
c.编写一个使用这两个函数的简单程序。

4. 许多州的彩票发行机构都使用如程序清单7.4所示的简单彩票玩法的变体。在这些玩法中，玩家从一组被称为域号码（field number）的号码中选择几个。例如，可以从域号码1~47中选择5个号码；还可以从第二个区间（如1~27）选择一个号码（成为特选号码）。要赢得头奖，必须正确猜中所有的号码。中头奖的几率是选中所有域号码的几率与选中特选号几率的乘积。例如，在这个例子中，中头奖的几率从47个号码中正确选取5个号码的几率与从27个号码中正确选择1个号码的几率的乘积。请修改程序清单7.4，以计算中得这中彩票头奖的几率。

Listing 7.4 lotto.cpp

```cpp
// lotto.cpp -- probability of winning
#include <iostream>
// Note: some implementations require double instead of long double
long double probability(unsigned numbers, unsigned picks);
int main() {
    using namespace std;
    double total, choices;
    cout << "Enter the total number of choices on the game card and\n"
            "the number of picks allowed:\n";
    while ((cin >> total >> choices) && choices <= total) {
        cout << "You have one chance in ";
        cout << probability(total, choices);  // compute the odds
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << "bye\n";
    return 0;
}
// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double probability(unsigned numbers, unsigned picks) {
    long double result = 1.0;  // here come some local variables
    long double n;
    unsigned p;
    for (n = numbers, p = picks; p > 0; n--, p--) result = result * n / p;
    return result;
}

```

5. 定义一个递归函数，接受一个整数参数，并返回该参数的阶乘。前面讲过，3的阶乘写作3！，等于3*2！，以此类推；而0！的阶乘被定义为1。被定义为1.通用的计算公式是，如果n大于零 ， 则n! = n * (n - 1)!。在程序中对该函数进行测试，程序使用循环让用户 输入不同的值，程序将报告这些值的阶乘。
   Define a recursive function that takes an integer argument and returns the factorial of that argument. Recall that 3 factorial, written 3!, equals 3 × 2!,and so on, with 0! defined as 1. In general, if n is greater than zero, n! = n \* (n - 1)!.Test your function in a program that uses a loop to allow the user to enter various values for which the program reports the factorial.

6. 编写一个程序，它使用下列函数：
   `Fill_array()`将一个double数组的名称和长度作为参数。它提示用户输入double值，并将这些值存储到数组中。当数组被填满或 用户输入了非数字时，输入将停止，并返回实际输入了多少个数字。
   `Show_array()`将一个double数组的名称和长度作为参数，并显示该数组的内容。
   `Reverse-array()`将一个double数组的名称和长度作为参数，并将存储在数组中的值的顺序反转。
   程序将使用这些函数来填充数组，然后显示数组；反转数组，然后显示数组；反转数组中除第一个和最后一个元素之外的所有元素， 然后显示数组。
   Write a program that uses the following functions:
   `Fill_array()` takes as arguments the name of an array of `double` values and an array size. It prompts the user to enter `double` values to be entered in the array. It ceases taking input when the array is full or when the user enters non-numeric input,and it returns the actual number of entries.
   `Show_array()` takes as arguments the name of an array of `double` values and an array size and displays the contents of the array.
   `Reverse_array()` takes as arguments the name of an array of `double` values and an array size and reverses the order of the values stored in the array.
   The program should use these functions to fill an array, show the array, reverse the array, show the array, reverse all but the first and last elements of the array,and then show the array.

7. 修改程序清单7.7中的3个数组处理函数，使之使用两个指针参数来表示区间。file_array()函数不返回实际读取了多少个数字，而是返回一个指针，该指针指向最后被填充的位置。其他的函数可以将该指针作为第二个参数，以标识数据结尾。
   Redo Listing 7.7, modifying the three array-handling functions to each use two pointer parameters to represent a range.The fill_array() function, instead of returning the actual number of items read, should return a pointer to the location after the last location filled; the other functions can use this pointer as the second argument to identify the end of the data.

Listing 7.7 arrfun3.cpp

```cpp
// arrfun3.cpp -- array functions and const
#include <iostream>
const int Max = 5;
// function prototypes
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);  // don't change data
void revalue(double r, double ar[], int n);
int main() {
    using namespace std;
    double properties[Max];
    int size = fill_array(properties, Max);
    show_array(properties, size);
    if (size > 0) {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor)) {  // bad input
            cin.clear();
            while (cin.get() != '\n') continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
    cout << "Done.\n";
    cin.get();
    cin.get();
    return 0;
}
int fill_array(double ar[], int limit) {
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++) {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin) {  // bad input
            cin.clear();
            while (cin.get() != '\n') continue;
            cout << "Bad input; input process terminated.\n";
            break;
        } else if (temp < 0) {  // signal to terminate
            break;
        }
        ar[i] = temp;
    }
    return i;
}
// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double ar[], int n) {
    using namespace std;
    for (int i = 0; i < n; i++) {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}
// multiplies each element of ar[] by r
void revalue(double r, double ar[], int n) {
    for (int i = 0; i < n; i++) ar[i] *= r;
}
```

8. 在不使用array类的情况下完成程序清单7.15所做的工作。编写两个这样的版本：
   a.使用const char *数组存储表示季度名称的字符串，并使用double数组存储开支。
   b.使用const char *数组存储表示季度名称的字符串，并使用一个结构，该结构只有一个成员——一个用于存储开支的double数组。这种设计与使用array类基本设计类似。.
   Redo Listing 7.15 without using the array class. Do two versions:
   a. Use an ordinary array of `const char *` for the strings representing the sea-son names, and use an ordinary array of double for the expenses.
   b. Use an ordinary array of `const char *` for the strings representing the sea-son names, and use a structure whose sole member is an ordinary array of `double` for the expenses. (This design is similar to the basic design of the array class.)

```cpp
//arrobj.cpp -- functions with array objects
#include <iostream>
#include <array>
#include <string>
const int Seasons = 4;
const std::array<std::string, Seasons> Snames =
    {"Spring", "Summer", "Fall", "Winter"};

void fill(std::array<double, Seasons> * pa);
void show(std::array<double, Seasons> da);
int main()
{
    std::array<double, 4> expenses;
    fill(&expenses);
    show(expenses);
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill(std::array<double, Seasons> * pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> (*pa)[i];
    }
}

void show(std::array<double, Seasons> da)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << da[i] << '\n';
        total += da[i];
    }
    std::cout << "Total: $" << total << '\n';
}

/********************************************************************/
```

9. 这个练习让您编写处理数组和结构的函数。下面是程序的框架，请提供其中描述的函数，以完成该程序。
   This exercise provides practice in writing functions dealing with arrays and structures.The following is a program skeleton. Complete it by providing the described functions:

```cpp
#include <iostream>
using namespace std;

const int SLEN = 30;
struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
int getinfo(student pa[], int n);
// display1() takes a student structure as an argument
// and displays its contents
void display1(student st);
// display2() takes the address of student structure as an
// argument and displays the structure’s contents
void display2(const student* ps);
// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
void display3(const student pa[], int n);
int main()
{
    cout << "Enter class size : ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;
    student* ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete[] ptr_stu;
    cout << "Done\n";
    return 0;
}
```

10. 设计一个名为`calculate()`的函数，它接受两个double值和一个指向函数的指针，而被指向的函数接受两个double参数，并返回一个double值。`calculate()`函数的类型也是double，并返回被指向的函数使用`calculate()`的两个double参数计算得到的值。例如，假设`add()`函数的定义如下：
    Design a function `calculate()` that takes two type double values and a pointer to a function that takes two double arguments and returns a double.The `calculate()` function should also be type double, and it should return the value that the pointed-to function calculates, using the double arguments to `calculate()`. For example, suppose you have this definition for the `add()` function:

    ```cpp
        double add (double x, double y)
        {
        return x + y;
        }
    ```

    则下述代码中的函数调用将导致`calculate()`把2.5和10.4传递给`add()`函数，并返回`add()`的返回值（12.9）：
    Then, the function call in the following would cause `calculate()` to pass the values 2.5 and 10.4 to the `add()` function and then return the `add()` return value (12.9):

    ```cpp
        double q = calculate (2.5, 10.4, add);
    ```

    请编写一个程序，它调用上述两个函数和至少另一个与`add()`类似的函数。该程序使用循环来让用户成对地输入数字。对于每对数字，程序都使用`calculate()`来调用`add()`和至少一个其他的函数。如果读者爱冒险，可以尝试创建一个指针数组，其中的指针指向`add()`样式的函数，并编写一个循环，使用这些指针连续让`calculate()`调用这些函数。提示：下面是声明这种指针数组的方式，其中包含三个指针：
    Use these functions and at least one additional function in the `add()` mold in a program.The program should use a loop that allows the user to enter pairs of numbers. For each pair, use `calculate()` to invoke `add()` and at least one other function. If you are feeling adventurous, try creating an array of pointers to `add()` style functions and use a loop to successively apply `calculate()` to a series of functions by using these pointers. Hint: Here’s how to declare such an array of three pointers:

    ```cpp
        double (*pf[3]) (double, double);
    ```

    可以采用数组初始化语法，并将函数名作为地址来初始化这样的数组。
    You can initialize such an array by using the usual array initialization syntax and function names as addresses.
