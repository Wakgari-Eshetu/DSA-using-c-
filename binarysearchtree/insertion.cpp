#include <iostream>
using namespace std;

struct leli{
    int data;
    leli* left ;
    leli* right;
};

leli* createnode(int value){
    leli* newnode = new leli();
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
// insertion of the value in the BST
leli* insertvalue(leli* & root , int value ){
    if(root == NULL){
        return createnode(value );
    }
    if(value < root->data){
        root->left = insertvalue(root->left,value);
    }else if (value > root->data){
        root->right = insertvalue(root->right, value);
    }
    return root ;
}

void inorder(leli* & root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool seraching(leli* & root , int value){
    if(root == NULL){
        return false  ;
    }
    if(root->data == value){
        return true;
    }
    if(value>root->data){
        return seraching(root->right,value);
    }else{
        return seraching(root->left,value);
    }
   
}
// Deletion of the value from the BSTree 
// 1. case one if the node is leaf node 
// 2. with one child 
// 3. with two child 

leli* delbycopying(leli* & root , int value){
    if(root==NULL){
        return ;
    }
    if(value<root->data){
        root->left = delbycopying(root->left, value);
    }else if(value> root->data){
        root->right = delbycopying(root->right, value);
    }else{
        
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left == NULL){
            leli* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == NULL){
            leli* temp = root->left;
            delete root;
            return temp;
        }
        leli* temp = root->left;
        while(temp->right != NULL){
            temp = temp->right;
        }
        root->data = temp->data;
        root->left = delbycopying(root->left, temp->data);
    }
    return root ;
}

leli* delbymerging(leli*& root , int value){
    if(root = NULL){
        return ;
    }
    if(value < root->data){
        root->left = delbymerging(root->left ,value);
    }else if (value > root->data){
        root->right = delbymerging(root->right, value);
    }else{
        leli * temp ;
        if(root->left == NULL){
            return root->right;
        }
        if(root->right == NULL){
            return root->left;       
        }else{

        
        leli* leftsub = root->left;
        leli* rightsub = root->right;
        leli* rightmost = leftsub;
        while(rightmost ->right != NULL){
            rightmost = rightmost->right;
        }
        rightmost->right = rightsub;
        temp = leftsub;
    }
    delete root;
    return temp;
    }
    return root;
    
}
int maxvalue(leli*& root){
    if(root == NULL){
        cout<<"Tree is empty";
        return -1;
    }
    leli* temp = root;
    while(temp->right!= NULL){
        temp = temp->right;
    }
    return temp->data;
}
int minvalue(leli*& root){
    if(root == NULL){
        cout<<"Tree is empty";
        return -1;
    }
    leli* temp = root;
    while(temp->left!= NULL){
        temp = temp->left;
    }
    return temp->data;
}
int sizeoftree(leli*& root){
    if(root== NULL){
        return 0;
    }
    return 1 + sizeoftree(root->left) + sizeoftree(root->right);
}
int height(leli* & root){
    if(root == NULL){
        return -1;
    }

    return 1+ max(height(root->left), height(root->right));
}
int main(){
    leli* root = NULL;
    insertvalue(root,50);
    return 0;
}