#include <iostream>
using namespace std;

#define size = 10;
int deque[size];
int front = -1;
int rear = -1 ;

void insertvalue1(int value){
    if((front ==0 && rear= size -1) || front = rear+1){
        cout<<"Sorry Nospace for insertion"<<endl;
        return ;
    }
    if(front == -1){
        front = rear = 0;
    }else if (front == 0){
        front = size - 1;
    }else{
        front--;
    }
    deque[front] = value;

}
void insertvalue2(int value){
    if((front ==0 && rear= size -1) || front = rear+1){
        cout<<"Sorry Nospace for insertion"<<endl;
        return ;
    }else if (rear == -1){
        front = rear = 0;
    }else if (rear == size-1){
        rear = 0;
    }else{
        rear++;
    }
    deque[rear] = value;
    
}

void deletevalue1(){
    if(front == -1){
        cout<<"Nothing to delete"<<endl; return ;    }
    if(front == rear){
        front = rear = -1;
    }else if(front == size-1 ){
        front = 0;
    }else{
        front ++;
    }
}
void deletevalue2(){
    if(rear == -1){
        cout<<"Nothing to delete your deque is empty"<<endl;
        return ;
    }
    if(rear == front){
        rear=front = -1;
    }else if(rear == 0){
        rear = size-1;
    }else{
        rear-- ;
    }
}

void display(){
    if(front == -1){
        cout<<"Deque is empty"<<endl;
        return;
    }
    int i = front ;
    while(true){
        cout<<deque[i]<<" ";
        if(i==rear)break;
        i = (i+1)%size;
    }
    cout<<endl;
}