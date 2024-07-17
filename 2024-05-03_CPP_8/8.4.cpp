#include <cstring>  // for strlen(), strcpy()
#include <iostream>

struct stringy {
    char *str;  // points to a string
    int ct;     // length of string (not counting '\0')
};

void set(stringy *s, const char *testing);
void show(const stringy &s, int n = 1);
void show(const char *s, int n = 1);
void show(char *s, int n = 1);
// prototype for set(), show(), and show() got here
int main(int argc, char *argv[]) {
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(&beany, testing);  // first argument is a refenece,
                           // allocates space to hold copy testing
                           // sets str member of beany to point to the
                           // new block, copies tesing to new block,
                           // and sets ct member of beany
    show(beany);           // prints member string once
    show(beany, 2);        // prints member string twice
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);     // prints testing string once
    show(testing, 3);  // prints testing string thrice
    show("Done!");
    delete[] beany.str;
    return 0;
}

void set(stringy *s, const char *testing) {
    s->ct = strlen(testing);
    s->str = new char[s->ct + 1];
    strcpy(s->str, testing);
}
void show(const stringy &s, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << s.str << std::endl;
    }
}
void show(const char *s, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << s << std::endl;
    }
}
void show(char *s, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << s << std::endl;
    }
}
