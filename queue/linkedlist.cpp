#include <iostream>
using namespace std;

struct leli {
    int data;
    leli* next;
}
leli* front = NULL;
leli* rear = NULL;

void enqueue(int value){
    leli* newnode = new leli();
    newnode->data = value;
    newnode->next = NULL;
    if(rear == NULL){
        front = rear = newnode;
    }else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    if(front == NULL){
        cout <<"empty queue"<<endl;
        return ;
    }
    leli* temp = front;
    front = front->next;
    if(front == NULL){
        rear = NULL;
    }
    delete temp ;
}

void display(){
    if(front == NULL){
        cout<<"nothing to display"<<endl;
        return ;
    }
    leli * temp = front;
    while(!temp == NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}
