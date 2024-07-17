#!/bin/bash
# g++ -std=c++11 virsual_func.cpp -o a.out
# g++ -std=c++11 2023-05-28_thread.cpp -o b.out
# g++ -std=c++20 2023-05-29_timing.cpp -o b.out
g++ -std=c++11 ./golf_ps.cpp ./main_ps.cpp -o b.out
./b.out
