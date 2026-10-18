#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Fruit{
    int key;
    char name[100];
    int price;
    struct Fruit *left;
    struct Fruit *right;
};

struct Fruit *newFruit(int key, char *name, int price){
    struct Fruit *curr = (struct Fruit*) malloc(sizeof(struct Fruit));
    curr->key = key;
    strcpy(curr->name,name);
    curr->price = price;
    curr->right = NULL;
    curr->left = NULL;

    return curr;
}

//Input Data
struct Fruit *insertFruit(struct Fruit *curr, int key, char *name, int price){
    if (curr == NULL){
        return newFruit(key, name, price);
    }
    else if (key < curr->key){
        curr->left = insertFruit(curr->left, key, name, price);
    }else if (key > curr->key){
        curr->right = insertFruit(curr->right, key, name, price);
    }
    else{
        printf("[!] Key already used\n");
    }

    return curr;
}

//view Data
void preOrder(struct Fruit *curr){
    if (curr == NULL){
        return;
    }  
    printf("%2d. %s (%d)\n", curr->key, curr->name, curr->price);
    preOrder(curr->left);
    preOrder(curr->right);
}

void inOrder(struct Fruit *curr){
    if(curr == NULL)return;
    inOrder(curr->left);
    printf("%2d. %s (%d)\n",curr->key,curr->name, curr->price);
    inOrder(curr->right);
    
    
}

void postOrder(struct Fruit *curr){
    if (curr == NULL) return;
    postOrder(curr->left);
    postOrder(curr->right);
    printf("%2d. %s (%d)\n",curr->key,curr->name, curr->price);
}


void updateFruit(struct Fruit *curr, int key, int price){
    if (curr == NULL){
        printf("Data Not Found\n");
    }
    else if(key < curr->key){
        updateFruit(curr->left,key, price);
    }
    else if (key > curr->key){
        updateFruit(curr->right, key, price);
    }
    else {
        curr->price = price;
        printf("Data with key %d has update the price into %d\n",curr->key, curr->price);
    }
}

void printTree(Fruit *curr, int depth){
    if (curr == NULL){
        return;
    }

    printTree(curr->right, depth+1);
    for(int i = 0; i < depth; i++){
        printf("\t");
    }
    printf("%2d. %s (%d)\n",curr->key,curr->name,curr->price);
    printTree(curr->left, depth + 1);
}



int main(){
    struct Fruit *root = NULL;
    root = insertFruit(root, 5, "Mangga", 15000);
    root = insertFruit(root, 10, "Apel", 4000);
    root = insertFruit(root, 7, "Jeruk",10000);
    updateFruit(root,20,20000);
    
    inOrder(root);
    printTree(root, 0);



    return 0;
}