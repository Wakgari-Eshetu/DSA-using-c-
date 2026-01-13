#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}



Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}


bool search(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}


void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}
int height(Node* root) {
  
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}


// Deletion by copying: replace node with inorder successor (smallest in right subtree)
Node* deleteByCopy(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteByCopy(root->left, key);
    else if (key > root->data)
        root->right = deleteByCopy(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: get the inorder successor (min in right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data; // copy successor's value
        root->right = deleteByCopy(root->right, temp->data);
    }
    return root;
}

// Helper to merge two BSTs where all keys in left are <= keys in right
Node* mergeTrees(Node* left, Node* right) {
    if (left == NULL) return right;
    Node* cur = left;
    while (cur->right != NULL)
        cur = cur->right;
    // attach right subtree as the rightmost's right child
    cur->right = right;
    return left;
}

// Deletion by merging: replace deleted node by merging its left and right subtrees
Node* deleteByMerge(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteByMerge(root->left, key);
    else if (key > root->data)
        root->right = deleteByMerge(root->right, key);
    else {
        Node* L = root->left;
        Node* R = root->right;
        delete root;
        return mergeTrees(L, R);
    }
    return root;
}

// To calculate the height of the tree 


int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "\n1. Insert\n2. Search\n3. Inorder Traversal\n4. Delete (copying)\n5. Delete (merging)\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value))
                cout << "Value found\n";
            else
                cout << "Value not found\n";
            break;

        case 3:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Enter value to delete (copying): ";
            cin >> value;
            root = deleteByCopy(root, value);
            break;

        case 5:
            cout << "Enter value to delete (merging): ";
            cin >> value;
            root = deleteByMerge(root, value);
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}
