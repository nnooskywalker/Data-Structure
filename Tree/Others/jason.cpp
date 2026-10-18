#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* createNew(int data){
    Node* newNode = (Node* ) malloc (sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data){
    if (root == NULL)
        return createNew(data);

    if (data == root->data)                             //
        return root;
    
    if (data < root->data)
        root->left = insert(root->left, data);          // insert with compare it's value
    else 
        root->right = insert(root->right, data);

    return root;
}

Node* search(Node* root, int data){
    if (root == NULL || root->data == data ){
        return root;
    }

    if (data < root->data){
        return search(root->left, data);        //return the search result 
    } else {
        return search(root->right, data);       
    }

    return root;
}

//Find Largest Left Subtree
Node* find_largest_left(Node* root){
    if (root->right != NULL){
        root = root->right;
    }
    return root;
} 

Node* deleteNode(Node* root, int key){
    if (root == NULL){
        return root;
    }

    //Traverse
    if (key < root->data){
        root->left = deleteNode(root->left, key);
    } else {
        root->right = deleteNode(root->right, key);
    }

    //Delete 0 node
    if (root->left == NULL && root->right == NULL){
        //delete temp
        free(root);
        return NULL;
    } else if (root->left == NULL){     //1 child
        Node* temp = root->right;
        free(root);
        return temp;
    } else if (root->right == NULL){    //1 child
        Node* temp = root->left;
        free(root);
        return temp;
    }

    //2 child
    Node* temp = find_largest_left(root->left);
    root->data = temp->data;
    root->left = deleteNode(root->left, temp->data);       //fix the tree
    return root;
}


void postOrder(Node* root){
    if (root == NULL)
        return;
    
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

//              50
//        30         70
//      20  40    60   80
//             45

int main () {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Before Delete : \n");
    postOrder(root);
    printf("\n");

    root = deleteNode(root, 20);
    puts("After Delete : ");
    postOrder(root);

    return 0;
}