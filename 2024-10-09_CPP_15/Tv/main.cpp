#include <iostream>

#include "./Tv.h"

int main(int argc, char* argv[]) {
    // Tv panda(Tv::On, 25);
    // panda.settings();
    // std::cout << "\n";
    // Remote control;
    // control.volup(panda);
    // panda.settings();
    using std::cout;
    Tv s42;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.settings();
    Remote grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "\n42\" settings after using remote:\n";
    s42.settings();
    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n58\" settings:\n";
    s58.settings();

    return 0;
}
