1. 修改程序清单11.15，使之将一系列连续的随机漫步者位置写到文件中。对于每个位置，用步号进行标示。 另外，让该程序将初始条件（目标距离和步长）以结果小结写入到该文件中。该文件的内容与下面类似
1. Modify Listing 11.15 so that it writes the successive locations of the random walker into a file. Label each position with the step number.Also have the program write the initial conditions (target distance and step size) and the summarized results to the file.The file contents might look like this:

```cpp
Target Distance: 100, Step Size: 20 
0: (x,y) = (0, 0)
1: (x,y) = (-11.4715, 16.383)
2: (x,y) = (-8.68807, -3.42232) ...
26: (x,y) = (42.2919, -78.2594)
27: (x,y) = (58.6749, -89.7309)
After 27 steps, the subject has the following location: (x,y) = (58.6749, -89.7309)
or
(m,a) = (107.212, -56.8194)
Average outward distance per step = 3.97081
```

2. 对`vector`类的头文件（程序清单11.13）和实现文件（程序清单11.14）进行修改，使其不再存储矢量的长度和角度，而是在`magval()`和`angval()`被调用时计算他们。应保留公有接口不变（公有方法及其参数不变），但对私有部分（包括一些私有方法）和方法实现进行修改。然后，使用程序清单11.15对修改后的版本进行测试，结果应该与以前相同，因为`vector`类的公有接口与原来相同。
2. Modify the `Vector` class header and implementation files (Listings 11.13 and 11.14) so that the magnitude and angle are no longer stored as data components. Instead, they should be calculated on demand when the `magval()` and `angval()` methods are called.You should leave the public interface unchanged (the same public meth- ods with the same arguments) but alter the private section, including some of the private method and the method implementations.Test the modified version with Listing 11.15, which should be left unchanged because the public interface of the `Vector` class is unchanged.

3. 修改程序清单11.15，使之报告N次测试中的最高、最低和平均步数（其中N是用户输入的整数），而不是报告每次测试的结果。
3. Modify Listing 11.15 so that instead of reporting the results of a single trial for a particular target/step combination, it reports the highest, lowest, and average num- ber of steps for N trials, where N is an integer entered by the user.

4. 重新编写最后的`Time`类示例（程序清单11.10、程序清单11.11和程序清单11.12），使用友元函数来实现所有的重载运算符。
4. Rewrite the final `Time` class example (Listings 11.10, 11.11, and 11.12) so that all the overloaded operators are implemented using friend functions.

5. 重新编写Stonewt类（程序清单11.16和程序清单11.17），使他有一个状态成员，由该成员控制对象转换为英石格式、整数磅格式还是浮点磅格式。重载`<<`运算符，使用它来替换`show_stn()`和`show_lbs()`方法。重载加法、减法和乘法运算符，以便可以对Stonewt值进行加、减、乘运算。编写一个使用所有类方法和友元的小程序，来测试这个类。
5. Rewrite the Stonewt class (Listings 11.16 and 11.17) so that it has a state member that governs whether the object is interpreted in stone form, integer pounds form, or floating-point pounds form. Overload the `<<` operator to replace the `show_stn()` and `show_lbs()` methods. Overload the addition, subtraction, and multiplication operators so that one can add, subtract, and multiply Stonewt values. Test your class with a short program that uses all the class methods and friends.

6. 重新编写`Stonewt`类(程序清单11.16和程序清单11.17)，重载 全部6个关系运算符。运算符对`pounds`成员进行比较，并返回一个`bool` 值。编写一个程序，它声明一个包含6个`Stonewt`对象的数组，并在数组 声明中初始化前3个对象。然后使用循环来读取用于设置剩余3个数组元 素的值。接着报告最小的元素、最大的元素以及大于或等于11英石的元 素的数量(最简单的方法是创建一个`Stonewt`对象，并将其初始化为11 英石，然后将其同其他对象进行比较)。
6. Rewrite the `Stonewt` class (Listings 11.16 and 11.17) so that it overloads all six relational operators.The operators should compare the `pounds` members and return a type `bool` value.Write a program that declares an array of six `Stonewt` objects and initializes the first three objects in the array declaration.Then it should use a loop to read in values used to set the remaining three array elements.Then it should report the smallest element, the largest element, and how many elements are greater or equal to 11 stone. (The simplest approach is to create a `Stonewt` object initial- ized to 11 stone and to compare the other objects with that object.)

7.复数有两个部分组成：实数部分和虚数部分。复数的一种写法方式是：(3.0, 4.0)，其中，3.0是实数部分，4.0是虚数部分。假设a=(A,Bi)，c=(C,Di)，则下面是一些复数运算。
加法：a+c=(A+C,(B+D)i)。
减法：a-c=(A-C,(B-D)i)。
乘法：a*c=(A*C-B*D, (A*D+B*C)i)。
乘法：x*c=(x*C,x*Di)。
共轭：a=(A,-Bi)。
请定义一个复数类，以便下面的程序可以使用它来获得正确的结果。
7. A complex number has two parts: a real part and an imaginary part. One way to write an imaginary number is this: (3.0, 4.0). Here 3.0 is the real part and 4.0 is the imaginary part. Suppose a = (A,Bi) and c = (C,Di). Here are some complex operations:

* Addition:a + c = (A + C,(B + D)i)
* Subtraction:a - c = (A - C,(B - D)i)
* Multiplication: a × c = (A × C - B×D, (A×D + B×C)i)  
* Multiplication: (x a real number): x × c = (x×C,x×Di)  
* Conjugation: ~a = (A, - Bi)
Define a complex class so that the following program can use it with correct results:

```cpp
#include<iostream>
using namespace std;
#include "complex0.h"
int main()
{
    complex a(3.0, 4.0);
    complex c;
    cout << "Enter a complex number (q to quit):\n";
    while(cin >> c)
    {
        cout << "c is " << c <<'\n';
        cout << "complex conjugate is " << ~c <<'\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit):\n"; 
    }
    cout << "Done! \n";
    return 0;
}
```

注意，必须重载运算符`<<`和`>>`。标准c++使用头文件`complex`提供了比这个示例更广泛的复数支持，因此应将自己定义的头文件命名为`complex0.h`，以免发生冲突。应尽可能使用`const`。
下面是该程序的运行情况。
Note that you have to overload the `<<` and `>>` operators. Standard C++ already has `complex` support—rather more extensive than in this example—in a `complex` header file, so use complex0.h to avoid conflicts. Use `const` whenever warranted.
Here is a sample run of the program:

```bash
Enbter a complex number (q to quit):
real:10
imaginary:12
c is (10,12i)
complex conjugate is (10, -12i)
a is (3,4i)
a + c is (13,16i)
a - c is (-7,-8i)
a * c is (-18,76i)
2 + c is (20,24i)
Enbter a complex number (q to quit):
real:q
Done!
```

请注意，经过重载后，`cin>>c` 将提示用户输入实数和虚数部分。
Note that `cin >> c`, through overloading, now prompts for real and imaginary
