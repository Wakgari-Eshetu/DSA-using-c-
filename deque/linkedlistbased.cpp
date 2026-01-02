#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Insert at front
void insertFront(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = front;

    if (front != NULL)
        front->prev = newNode;
    else
        rear = newNode;

    front = newNode;
}

// Insert at rear
void insertRear(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear != NULL)
        rear->next = newNode;
    else
        front = newNode;

    rear = newNode;
}

// Delete from front
void deleteFront() {
    if (front == NULL) {
        cout << "Deque is empty\n";
        return;
    }
    Node* temp = front;
    cout << temp->data << " deleted\n";
    front = front->next;

    if (front != NULL)
        front->prev = NULL;
    else
        rear = NULL;

    delete temp;
}

// Delete from rear
void deleteRear() {
    if (rear == NULL) {
        cout << "Deque is empty\n";
        return;
    }
    Node* temp = rear;
    cout << temp->data << " deleted\n";
    rear = rear->prev;

    if (rear != NULL)
        rear->next = NULL;
    else
        front = NULL;

    delete temp;
}

// Display
void display() {
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insertFront(10);
    insertRear(20);
    insertFront(5);
    display();

    deleteFront();
    deleteRear();
    display();

    return 0;
}
