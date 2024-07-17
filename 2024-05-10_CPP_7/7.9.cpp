#include <iostream>

const int SLEN = 30;
struct       student {
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
void display2(const student *ps);
// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
void display3(const student pa[], int n);
int main() {
  std::cout << "Enter class size : ";
  int class_size;
  std::cin >> class_size;
  while (std::cin.get() != '\n')
    continue;
  student *ptr_stu = new student[class_size];
  int entered = getinfo(ptr_stu, class_size);
  for (int i = 0; i < entered; i++) {
    display1(ptr_stu[i]);
    display2(&ptr_stu[i]);
  }
  display3(ptr_stu, entered);
  delete[] ptr_stu;
  std::cout << "Done\n";
  return 0;
}
int getinfo(student pa[], int n) {
  int actual_num = 0;
  for (actual_num = 0; actual_num < n; actual_num++, pa++) {
    std::cout << "Please input a name" << std::endl;
    std::cin.getline(pa->fullname, SLEN);
    if (pa->fullname[0] == '\0' /*|| pa->fullname[0] == '\n'*/) {
      std::cout << "Empty name input.Done!" << std::endl;
      return actual_num;
    } else {
      std::cout << "What hobby" << std::endl;
      std::cin.getline(pa->hobby, SLEN);
      std::cout << "What level" << std::endl;
      std::cin >> pa->ooplevel;
      std::cin.clear(); // clear the input stream
      while (std::cin.get() != '\n')
        continue;
    }
  }
  return actual_num;
}

void display1(student st) {
  std::cout << "Name = " << st.fullname << " Hobby = " << st.hobby
            << " Level = " << st.ooplevel << std::endl;
}
void display2(const student *ps) {
  std::cout << "Name = " << ps->fullname << " Hobby = " << ps->hobby
            << " Level = " << ps->ooplevel << std::endl;
}
void display3(const student pa[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << "Name = " << pa[i].fullname << " Hobby = " << pa[i].hobby
              << " Level = " << pa[i].ooplevel << std::endl;
  }
}
