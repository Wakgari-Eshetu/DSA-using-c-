#include <iostream>
using namespace std;

int arr1[5];
int front1 = -1, rear1 = -1;

void enqueue(int x) {
    if (rear1 == 4) {
        cout << "Single Array Queue Overflow\n";
        return;
    }
    if (front1 == -1){
        front1 = 0;
    } 
    arr1[++rear1] = x;
}

void dequeue() {
    if (front1 == -1 || front1 > rear1) {
        cout << "Single Array Queue Underflow\n";
        return;
    }
    cout << "Dequeued: " << arr1[front1++] << endl;
}

void display() {
    if (front1 == -1 || front1 > rear1) {
        cout << "Single queue empty\n";
        return;
    }
    cout << "Single Queue: ";
    for (int i = front1; i <= rear1; i++)
        cout << arr1[i] << " ";
    cout << endl;
}

int main() {
    display();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    dequeue();
    display();

    enqueue(50);
    display();

    return 0;
}
