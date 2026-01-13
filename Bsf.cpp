#include <iostream>
using namespace std;

struct leli{
    int data;
    leli* left;
    leli* right;
};

// delete by copying 
leli* delcopy(leli* root,int value){
    if(root==NULL){
        cout<<"Nothing to delete";
        return root;
    }
    if(value>root->data){
        root->right = delcopy(root->right, value);
    }
    else if(value<root->data){
        root->left = delcopy(root->left, value);
    }
    else{
        if(root->left == NULL){
            leli* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            leli* temp = root->left;
            delete root;
            return temp;
        }
        else{
            //inorder predcessor
            leli* temp = findmax(root->left);
            root->data = temp->data;
            root->left = delcopy(root->left, temp->data);

            //inorder sucssor

            leli* temp = findmin(root->right);
            root->data = temp->data;
            root->right = delcopy(root->right, temp->data);
        }
    }
}

leli* findmax(leli* root){
    if(root==NULL){
        return root;
    }
    while(root->right!=NULL){root = root->right};
    return root;
}
leli* findmin(leli* root){
    if(root== NULL){return root;}
    while(root->left!=NULL){root = root->left};
    return root;
}

leli* delmerging(leli* root, int value){
    if(root==NULL){return root;}
    if(value>root->data){root->right = delmerging(root->right, value);}
    else if(value<root->data){root->left = delmerging(root->left, value);}
    else{
        leli* L = root->left;
        leli* R = root->right;
        delete root;
        return mergetree(L,R);
    }
}
leli* mergetree(leli* left, leli* right){
    if(left==NULL)return right;
    while(left->right != NULL){ left = left->right;}
    left->right = right;
    return left;
}

leli* mergetree(leli* left, leli* right){
    if(right==NULL){return left;}
    while(right->left!= NULL){right= right->left;}
    right->left = left;
    return right;
}