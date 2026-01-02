#include  <iostream>
using namespace std;

// size = |rear- front +1| is number elements currently in the queue 
#define size = 10;
int queue[size];
int front = -1 ;
int rear = -1 ;
void insertvalue(int value ){
    if(rear == size -1){
        cout<<"queue overflow ";
        return ;
    }
    if(front == -1){
        front = 0;

    }
    queue[++rear] = value;
    cout<<value <<" inserted "<<endl;
}

void deletevalue(){
    if(front == -1 || front >rear){
        cout<<"nothing to delete"<<endl;
        return ;
    }
    queue[front++];
}

void display(){
    if(front == -1 || front >rear){
        cout<<"nothing to display mean your queue has no element "<<endl;
        return ;
    }
    else {
        for(int i = front ;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
    }
    cout<<endl;
}