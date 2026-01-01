#include <iostream>
using namespace std;

struct leli{
    int data;
    leli* next;

};

void insertvalue1(leli* & head , int value){
    leli* newnode = new leli();
    newnode->data = value;
    newnode->next = head;
    head = newnode ;
}
void insertvalue2(leli*& head ,int value ){
    leli* newnode = new leli();
    newnode->data = value;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        return;
    }
    leli* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    
    temp->next = newnode;
}

void insertvalue3(leli* & head , int value , int pos){
    leli* newnode = new leli();
    newnode->data = value ;
    leli* temp = head ;
    for(int i=1 ;i<pos-1 && temp->next != NULL;i++){
        temp = temp->next;
    }
    newnode-> next = temp->next;
    temp->next  = newnode;

}

void deletevalue1(leli* & head ){
    if(head== NULL){
        cout<<"linked list is empty";
        return ;

    }
    leli* temp = head;
    head = head->next;

    delete temp ;
}
void deletevalue2(leli* & head ){
    if(head== NULL){
        cout<<"linked list is empty";
        return ;

    }
    if(head->next == NULL){
        delete head;
        head =NULL;
        return ;
    }
    leli* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}
void deletevalue3(leli* & head , int pos){
    if(head== NULL){
        cout<<"linked list is empty";
        return ;

    }

    if(pos==1){
        leli* temp = head;
        head = head->next;
        delete temp;
        return ;
    }

    leli* temp = head;
    for(int i = 1;i<pos-1 && temp->next != NULL ;i++ ){
        temp = temp->next;
    }
    if(temp->next == NULL){
        cout<<"Invalid position ";
        return;
    }

    leli* del = temp->next;
    temp->next= del->next;
    delete del;


}
void display(leli* & head){
    if(head == NULL){
        cout<<"Empty list";
        return ;
    }
    leli* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
//searching value in the singly linked list 
bool searchvalue(leli*& head,int value){
    if(head==NULL){
        cout<<"list is empty";
        return false;
    }
    leli* temp = head;
    while(temp->next!= NULL){
        if(temp->data == value){
            return true;
        }
        temp = temp->next;
    }
    return false;

}
//sorting value in linked list 
void sortingvalue(leli* & head){
    if(head ==NULL){
        cout<<"your list is empty i can't help you!!";
        return ;
    }
    leli* i ;
    leli* j;
    int temp;
    for(i = head;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data > j->data){
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


int main(){
    leli* head = NULL;
    insertvalue1(head,2);
    display(head);
    return 0;
}