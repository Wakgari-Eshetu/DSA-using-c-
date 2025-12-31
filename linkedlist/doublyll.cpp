#include <iostream>
using namespace std;

// Creating the  doubly linked list 
struct leli{
    int data ;
    leli* next;
    leli* prev;
};

// Inserting value at the begining 

void insertvalue1(leli* & head , int value ){
    leli* newnode = new leli();
    newnode->data = value ;
    newnode->prev = NULL; 
    if(head == NULL){
       head->next = NULL; 
       head = newnode;
       return ; 
    }
    newnode->next = head;
    head->prev = newnode;

    head = newnode;

}
// Inserting at the end of the linked list 

void insertvalue2(leli* & head , int value){
    leli* newnode = new leli();
    newnode->data = value ;
    newnode->next = NULL;
    if(head == NULL){
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    leli* temp = head ;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}
// Inserting at any point 

void insertvalue3(leli* & head , int value,int pos){
    leli* newnode = new leli();
    newnode->data = value;

    if(head==NULL){
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    if(pos==1){
        newnode->prev = NULL;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    int count = 1;
    leli* temp = head;
    while(temp != NULL && count<pos ){
        temp = temp->next;
        count++;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if(temp->next!=NULL){
        temp->next->prev = newnode;
    }
    temp->next =newnode;

}