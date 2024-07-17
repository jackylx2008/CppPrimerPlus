#include <iostream>

#include "./stonewt.h"

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    Stonewt arr[6] = {Stonewt(30), Stonewt(20), Stonewt(26)};
    for (int i = 3; i < 6; i++) {
        cout << "Stonewt[" << i << "]: ";
        double st;
        cin >> st;
        arr[i] = Stonewt(st);
    }

    Stonewt max = arr[0], min = arr[0];
    int num = 0;
    Stonewt eleven = Stonewt(11, 0.0);
    for (int i = 0; i < 6; ++i) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
        if (arr[i] > eleven) num++;
    }

    cout << "max: " << max << endl;
    cout << "min: " << min << endl;
    cout << num << " elements > 11 stones" << endl;

    return 0;
}
