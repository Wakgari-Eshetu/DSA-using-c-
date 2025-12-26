// node is individual item of the linked list
// node have two things one is the data and the other is 
// pointer to the next node
//the first node is called head node 
//the last node points to null which mean the end of the list 

#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;

    }
};

int main(){
    
    return 0;
}
