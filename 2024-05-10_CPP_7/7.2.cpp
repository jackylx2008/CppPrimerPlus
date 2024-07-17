// 2024-05-11 15:05:50
#include <iostream>

void GetScore(int score[], int n);
double GetAvg(const int score[], int n);
void ShowScore(const int score[], int n);

int main(int argc, char *argv[]) {
    int score[10];
    GetScore(score, 10);
    ShowScore(score, 10);
    std::cout << "Average = " << GetAvg(score, 10) << std::endl;
    return 0;
}

void GetScore(int score[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Input No." << i + 1 << " score" << std::endl;
        std::cin >> score[i];
        // check if the input is not an integer
        if (std::cin.fail() || score[i] < 0) {
            std::cout << "Error: Invalid input! Please enter an integer."
                      << std::endl;
            std::cin.clear();  // clear the input stream
            while (std::cin.get() != '\n') {
            }
            i--;  // decrement i to retry the same index
        }
        if (score[i] == 0) {
            for (int j = i; j < n; j++) {
                score[j] = 0;
            }
            break;
        }
    }
}

double GetAvg(const int score[], int n) {
    double avg, sum;
    int count = 0;
    sum = 0.0;
    for (int i = 0; i < n; i++) {
        if (score[i] > 0) {
            sum += score[i];
            count++;
        }
    }
    if (score[0] == 0) {
        std::cout << "No score" << std::endl;
        return 0.0;
    }
    avg = (double)sum / (double)count;
    return avg;
}

void ShowScore(const int score[], int n) {
    std::cout << "All score" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << score[i] << " ";
    }
    std::cout << std::endl;
}
