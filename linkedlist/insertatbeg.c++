#include <iostream>

using namespace std;

struct linked{
    int data;
    linked* next;

};

void insertval1(linked*& head ,int value){
    linked* newnode = new linked();
    newnode ->data= value;
    newnode -> next = head;
    head = newnode;
}
void insertval2(linked*& head ,int value){
    linked* newnode = new linked();
    newnode->data = value;
    newnode->next = head;
    if(head==NULL){
        head=newnode;
        return ;
    }
}
void display(linked* head){
    linked* temp = head;
    while (temp != NULL){
        cout<<temp->data<<"->";
        temp = temp ->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    linked* head = NULL;
    insertval1(head,20);
    insertval1(head,40);
    insertval1(head,60);
    insertval1(head,80);
    insertval1(head,10);
    display(head);
}