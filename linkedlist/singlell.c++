#include <iostream>
using namespace std;

// single linked list 
struct linked{
    int data ;
    linked* next;
};
// insertion at the  beggining of the list
void insertval1(linked* head ,int value){
    linked* newnode = new linked();
    newnode ->data= value;
    newnode -> next = head;
    head = newnode;
}
void insertval2(linked*& head,int value){
    linked* nw = new linked();
    nw->data = value;
    nw->next = NULL;

    if(head==NULL){
        head = nw;
        return;
    }
    linked* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = nw;
}
//inserting at any position 
void insertval3(linked*& head , int value ,int pos){
    linked* newNode = new linked();
    newNode->data = value;
    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return ;
    }
    linked * temp = head ;
    int i = 1;
    while(i<pos-1 && temp != NULL){
        temp=temp->next;
        i++;
    }
    if(temp == NULL){
        cout<<"position at the end and the value you want can be inserted at the position you want ";
        delete newNode;
        return ;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void display(linked* head){
    linked* temp = head;
    while (temp != NULL){
        cout<<temp->data<<"->";
        temp = temp ->next;
    }
}
int main(){
    linked* head = new linked();
    head->data =10;
    linked* second = new linked();
    second->data = 12;
    linked* third = new linked();
    third->data= 14;
    
    head->next = second ;
    second->next = third ;
    third ->next= NULL;
    display(head);
    return 0;
}
