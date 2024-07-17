# C++ Primer Plus（第六版）编程练习答案 第9章 内存模型和名称空间

1. 下面是一个头文件：

```cpp
//golf.h--forpr9-1.cpp
const int Len = 40;
struct golf {
    char fullname[Len];
    int handicap;
};

//non-interacti veversion:
//function sets golf structure to provided name, handicap
//using values passed asarguement to the function
void setgolf(golf &g, const char *name, int hc);

//interacti veversion：
//function solicits name and handicap from user
//and sets the members of g to the values entered
//return 1 if name is entered,0 if name is empty string
int setgolf(golf &g);

//function resets handicap to new value
void handicap(golf &g, int hc);

//function displays contents of golf structure
void showgolf(const golf &g);
```

注意到setgolf()被重载，可以这样使用其第一个版本：

```cpp
golf ann;
setgolf(ann, "Ann Birdfree", 24);
```

上述函数将提示用户输入姓名和等级，并将它们存储在`andy`结构中。这个函数可以（但是不一定必须）在内部使用第一个版本。
  根据这个头文件，创建一个多文件程序。其中的一个文件名为`golf.cpp`，它提供了与头文件中的原型匹配的函数定义；另一个文件应包含main()，并演示原型化函数的所有特性。例如，包含一个让用户输入的循环，并使用输入的数据来填充一个由golf结构组成的数组，数组被填满或用户将高尔夫选手的姓名设置为空字符串时，循环将结束。main()函数只使用头文件中原型化的函数来访问golf结构。
