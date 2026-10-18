#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct mahasiswa{
    char nama[30];
    char nim[5];
    int height;
    struct mahasiswa *right;
    struct mahasiswa *left;
};

struct mahasiswa *createNode(char *name, char *nim){
    struct mahasiswa* newNode = (struct mahasiswa*)malloc(sizeof(struct mahasiswa));
    strcpy(newNode->nama,name);
    strcpy(newNode->nim,nim);
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;


    return newNode;
}

//Get Height
int getHeight(struct mahasiswa *node){
    if (node == NULL) return 0;

    return node->height;
}

int printLevel(struct mahasiswa *root, int level){
    if(root == NULL){
        return 0;
    }
    if (level == 1){
        return 1;
    }

    return printLevel(root->left, level-1) + printLevel(root->right, level-1);
}

//Update Height
void updateHeight(struct mahasiswa *node){
    int left = getHeight(node->left);
    int right = getHeight(node->right);

    //Condition ? return value if true : return value if false
    node->height = 1 + ((left > right)? left : right);
}

//Get Balance
int getBalance(struct mahasiswa *node){
    return getHeight(node->left) - getHeight(node->right);
}

struct mahasiswa *rightRotate(struct mahasiswa *node){
    struct mahasiswa *newRoot = node->left;
    struct mahasiswa *orphan = newRoot->right;

    newRoot->right = node;
    node->left = orphan;
    updateHeight(newRoot);
    updateHeight(node);

return  newRoot;
}

struct mahasiswa *rebalance (struct mahasiswa *node){
    //Kalau dia berat ke kiri
    if (balance > 1){
        // kalau child kiri berat ke kanan
        if (getBalance(node->left) < -1){
            node->left = leftRotate(node->left);
        }
        return rightRotate(node);
        // kalaua child seimbang atau berat ke kiri
    }
    if (balance < -1){
        if (getBalance(node->right) > 0){
            node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }

    return node;
}

struct mahasiswa *insertNode(struct mahasiswa *node, struct mahasiswa *newData){
    if (node == NULL){
        return newData;
    }

    if(strcmp(node->nim, newData->nim) > 0){
        node->left = insertNode(node->left,newData);
    }
    else if (strcmp(node->nim, newData->nim) < 0){
        node->right = insertNode(node->right, newData);
    }
    else{
        free(newData);
        return node;
    }
}

void inOrder(struct mahasiswa *node){
    if (node == NULL){
        return;
    }
    inOrder(node->left);
    printf("%s - %s",node->nim, node->nama);
    inOrder(node->right);
}

void level(mahasiswa *root, int depth,  int *maxDepth, int save[], int count){
    if (root == NULL){
        return;   
    }
    if (depth > *maxDepth){
        *maxDepth = depth;
        save[count] = *maxDepth;
        count++;
    }

    if (depth == *maxDepth){
        save[count] = *maxDepth;
        count++;
    }

    level(root->right, depth+1, maxDepth, save);
    level(root->left, depth+1, maxDepth, save);
}

int main(){
    struct mahasiswa *root = NULL;
    root = insertNode(root, createNode("Jevon","1234"));
    root = insertNode(root, createNode("Louis","5232"));
    root = insertNode(root, createNode("Jerlo","9734"));
    root = insertNode(root, createNode("Martin","6634"));
    inOrder(root);
    


    return 0;
}