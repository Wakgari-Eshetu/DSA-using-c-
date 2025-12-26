#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

class AgePriorityQueue {
private:
    Person queue[50];
    int size;

public:
    AgePriorityQueue() {
        size = 0;
    }

    // Insert based on age priority (higher age first)
    void insert(string name, int age) {
        Person p;
        p.name = name;
        p.age = age;

        int i;
        for (i = size - 1; i >= 0; i--) {
            if (queue[i].age < age) {
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
             << " (Age " << queue[0].age << ")\n";

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

        cout << "\nPriority Queue (Age Based):\n";
        for (int i = 0; i < size; i++) {
            cout << queue[i].name
                 << " (Age " << queue[i].age << ")\n";
        }
    }
};

int main() {
    AgePriorityQueue pq;
    int choice, age;
    string name;

    do {
        cout << "\n--- Age Priority Queue Menu ---\n";
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
            cout << "Enter age: ";
            cin >> age;
            pq.insert(name, age);
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
