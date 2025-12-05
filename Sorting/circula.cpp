#include <iostream>
using namespace std;

#define SIZE 5
int arr2[SIZE];
int front2 = -1, rear2 = -1;


void enqueue_circular(int x) {
    if ((front2 == 0 && rear2 == SIZE - 1) || (rear2 + 1) % SIZE == front2) {
        cout << "Circular Queue Overflow\n";
        return;
    }

    if (front2 == -1) {
        front2 = rear2 = 0;
    } else {
        rear2 = (rear2 + 1) % SIZE;
    }
    arr2[rear2] = x;
}


void dequeue_circular() {
    if (front2 == -1) {
        cout << "Circular Queue Underflow\n";
        return;
    }

    cout << "Dequeued (circular): " << arr2[front2] << endl;

    if (front2 == rear2) {
        front2 = rear2 = -1;
    } else {
        front2 = (front2 + 1) % SIZE;
    }
}


void display_circular() {
    if (front2 == -1) {
        cout << "Circular queue empty\n";
        return;
    }

    cout << "Circular Queue: ";
    int i = front2;
    while (true) {
        cout << arr2[i] << " ";
        if (i == rear2) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}


int main() {

    enqueue_circular(10);
    enqueue_circular(20);
    enqueue_circular(30);
    enqueue_circular(40);
    enqueue_circular(50);
    display_circular();

    dequeue_circular();
    display_circular();

    enqueue_circular(99); 
    display_circular();

    return 0;
}
