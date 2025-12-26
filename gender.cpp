#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    string gender;
};

class GenderPriorityQueue {
private:
    Person queue[50];
    int size;

public:
    GenderPriorityQueue() {
        size = 0;
    }

    // Insert based on priority
    void insert(string name, string gender) {
        Person p;
        p.name = name;
        p.gender = gender;

        int i;
        for (i = size - 1; i >= 0; i--) {
            if (gender == "Female" && queue[i].gender == "Male") {
                queue[i + 1] = queue[i];
            } else {
                break;
            }
        }
        queue[i + 1] = p;
        size++;

        cout << "Inserted successfully.\n";
    }

    // Delete highest priority element
    void deleteElement() {
        if (size == 0) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Deleted: " << queue[0].name
             << " (" << queue[0].gender << ")\n";

        for (int i = 0; i < size - 1; i++) {
            queue[i] = queue[i + 1];
        }
        size--;
    }

    // Display queue
    void display() {
        if (size == 0) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "\nPriority Queue:\n";
        for (int i = 0; i < size; i++) {
            cout << queue[i].name
                 << " (" << queue[i].gender << ")\n";
        }
    }
};

int main() {
    GenderPriorityQueue pq;
    int choice;
    string name, gender;

    do {
        cout << "\n--- Gender Priority Queue Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter gender (Male/Female): ";
            cin >> gender;
            pq.insert(name, gender);
            break;

        case 2:
            pq.deleteElement();
            break;

        case 3:
            pq.display();
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
