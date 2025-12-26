#include <iostream>
#include <limits>
#include "person.h"
#include "gender_priority.h"

using namespace std;

int main() {
    GenderPriorityQueue pq;
    int choice;
    while (true) {
        cout << "\nMenu:\n1) Insert\n2) Delete (serve next)\n3) Display\n4) Exit\nChoose: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (choice == 1) {
            string name;
            char gender;
            int age;
            cout << "Name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Gender (M/F): ";
            cin >> gender;
            cout << "Age: ";
            cin >> age;
            pq.insert(Person(name, gender, age));
        } else if (choice == 2) {
            Person p;
            if (pq.remove(p)) {
                cout << "Served: " << p.name << " (" << p.gender << ", " << p.age << ")\n";
            } else {
                cout << "Queue is empty.\n";
            }
        } else if (choice == 3) {
            pq.display();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid option.\n";
        }
    }
    return 0;
}

                                  
