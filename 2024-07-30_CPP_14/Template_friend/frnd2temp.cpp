#include <iostream>

#include "./frnd2temp.h"

template <typename T>
int HasFriend<T>::count = 0;

void GetCount_Notemp() {
    std::cout << "int = " << HasFriend<int>::count << std::endl;
    std::cout << "double = " << HasFriend<double>::count << std::endl;
}
void GetItem_Notemp(HasFriend<int> const& i) {
    std::cout << "HasFriend<int> has " << i.item << std::endl;
}
void GetItem_Notemp(HasFriend<double> const& d) {
    std::cout << "HasFriend<double> has " << d.item << std::endl;
}

template <typename T>
void GetCount_temp() {
    std::cout << HasFriend<T>::count << std::endl;
}

template <typename T>
void GetItem_temp(const T& c) {
    std::cout << c.item << std::endl;
}

template <typename T>
int HasFriendInClass<T>::count = 0;

template <typename T1, typename T2>
void show(const T1& t1, const T2& t2) {
    std::cout << t1.item << ", " << t2.item << std::endl;
}

int main(int argc, char* argv[]) {
    HasFriend<int> hfi1(10);
    HasFriend<int> hfi2(20);
    HasFriend<double> hfd1(1.1);
    std::cout << "--------No template func---------" << std::endl;
    GetCount_Notemp();
    GetItem_Notemp(hfi2);
    GetItem_Notemp(hfd1);
    std::cout << "--------template func---------" << std::endl;
    GetCount_temp<int>();
    GetItem_temp(hfi2);
    std::cout << "--------template func in class---------" << std::endl;
    HasFriendInClass<int> hfici1(100);
    HasFriendInClass<double> hficd1(1.1);
    show(hfici1, hficd1);

    return 0;
}
