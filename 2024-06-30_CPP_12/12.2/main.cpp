#include <iostream>
using namespace std;
#include "./My_String2.h"
int main() {
    My_String2 s1(" and I am a C++ student.");
    My_String2 s2 = "Please enter your name: ";
    My_String2 s3;
    cout << s2;               // overloaded << operator
    cin >> s3;                // overloaded >> operator
    s2 = "My name is " + s3;  // overloaded =, + operators
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup();  // converts string to uppercase
    cout << "The string\n"
         << s2 << "\ncontains " << s2.has('A') << " 'A' characters in it.\n";
    s1 = "red";  // My_String2(const char *),
    // then My_String2 & operator=(const My_String2&)
    My_String2 rgb[3] = {My_String2(s1), My_String2("green"),
                         My_String2("blue")};
    cout << "Enter the name of a primary color for mixing light: ";
    My_String2 ans;
    bool success = false;
    while (cin >> ans) {
        ans.stringlow();        // converts string to lowercase
        for (int i = 0; i < 3; i++) {
            if (ans == rgb[i])  // overloaded == operator
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
