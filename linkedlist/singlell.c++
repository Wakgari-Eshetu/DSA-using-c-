#include <iostream>
using namespace std;

// single linked list 
struct linked{
    int data ;
    linked* next;
};
// insertion at the  beggining of the list
void insertval1(linked*& head ,int value){
    linked* newnode = new linked();
    newnode ->data= value;
    newnode -> next = head;
    head = newnode;
}
//insert at the end of the linkedlist
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
// used to display our linkedlist
void display(linked* head){
    linked* temp = head;
    while (temp != NULL){
        cout<<temp->data<<"->";
        temp = temp ->next;
    }
    cout<<"NULL"<<endl;
}
//deleting value at the beggining
void deletion1(linked*& head){
    if(head==NULL){
        cout<<"your list has no value in it"<<endl;
        return ;
    }
    linked* temp = head;
    head = head->next;
    delete temp ;
}
// deleting from the end 
void deletion2(linked*& head){
    if(head==NULL){
        cout<<"your list has no value in it"<<endl;
        return ;
    }
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    linked* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}
// deleting from any node in linkedlist

void deletion3(linked*& head, int pos) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (pos == 1) {
        linked* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    linked* temp = head;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    linked* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}


int main(){
    linked* head = NULL;
    insertval1(head,5);
    insertval2(head,34);
    insertval3(head,12,2);
    display(head);
    deletion1(head);
    display(head);
    deletion2(head);
    display(head);
    deletion3(head,1);
    display(head);
    return 0;
}
