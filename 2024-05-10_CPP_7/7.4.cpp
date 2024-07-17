// lotto.cpp -- probability of winning
#include <iostream>
// Note: some implementations require double instead of long double
long double probability(unsigned numbers, unsigned picks);
int main() {
    double total1, choice1, total2, choice2;
    std::cout << "Enter the total number of choices on the game card and\n"
                 "the number of picks allowed:\n";
    while ((std::cin >> total1 >> choice1 >> total2 >> choice2) &&
           choice1 <= total1 && choice2 <= total2) {
        std::cout << "You have one chance in ";
        std::cout << probability(total1, choice1) *
                         probability(total2, choice2);  // compute the odds
        std::cout << " of winning.\n";
        std::cout << "Next two numbers (q to quit): ";
    }
    std::cout << "bye\n";
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
