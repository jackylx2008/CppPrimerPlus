#include <cstring>
#include <iostream>

#include "./queue_tp.h"
#include "./worker.h"

const int SIZE = 5;

void test_QueueTp(void) {
    QueueTp<Worker*> queue_worker(SIZE);
    Worker* temp = nullptr;
    int ct;

    for (ct = 0; ct < SIZE; ct++) {
        char choice;
        std::cout << "Enter the employee category:\n"
                  << "w: waiter s: singer " << "t: singing waiter q: quit\n";
        std::cin >> choice;
        while (std::strchr("wstq", choice) == NULL) {
            std::cout << "Please enter a w, s, t, or q: ";
            std::cin >> choice;
        }
        if (choice == 'q') break;
        switch (choice) {
            case 'w': {
                temp = new Waiter;
                std::cin.get();
                temp->Set();
                queue_worker.enqueue(temp);
                break;
            }
            case 's': {
                temp = new Singer;
                std::cin.get();
                temp->Set();
                queue_worker.enqueue(temp);
                break;
            }
            case 't': {
                temp = new SingingWaiter;
                std::cin.get();
                temp->Set();
                queue_worker.enqueue(temp);
                break;
            }
        }
    }
    std::cout << "\nHere is your staff:\n";

    // for (int i = 0; i < ct; i++) {
    //     Worker* temp_w = nullptr;
    //     queue_worker.dequeue(temp_w);
    //     temp_w->Show();
    //     delete temp_w;
    // }

    for (int i = 0; i < ct; i++) {
        Worker** temp_w = new Worker*;
        queue_worker.dequeue(temp_w);
        (*temp_w)->Show();
        delete temp_w;
    }

    std::cout << "Bye.\n";
}

void test_Worker(void) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;
    Worker* lolas[SIZE];
    int ct;
    for (ct = 0; ct < SIZE; ct++) {
        char choice;
        cout << "Enter the employee category:\n"
             << "w: waiter s: singer " << "t: singing waiter q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL) {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q') break;
        switch (choice) {
            case 'w': {
                lolas[ct] = new Waiter;
                break;
            }
            case 's': {
                lolas[ct] = new Singer;
                break;
            }
            case 't': {
                lolas[ct] = new SingingWaiter;
                break;
            }
        }
        cin.get();
        lolas[ct]->Set();
    }
    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++) {
        cout << endl;
        lolas[i]->Show();
    }
    for (i = 0; i < ct; i++) delete lolas[i];
    cout << "Bye.\n";
}

int main() {
    test_QueueTp();

    return 0;
}
