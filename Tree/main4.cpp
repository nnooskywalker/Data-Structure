#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int score;
    int km;
    int height;
    struct node *right;
    struct node *left;
}node;

    node *createNode(int score, int km){
        node *newNode = (node*)malloc(sizeof(node));
        newNode->score = score;
        newNode->km = km;
        newNode->height = 1;
        newNode->right = NULL;
        newNode->left = NULL;

        return newNode;
    }

    node*findKey(node *root, int km){
        if (root == NULL) return NULL;
        if (km == root->km) return root;

        node *left = findKey(root->left, km);

        if (left != NULL){
            return left;
        }

        return findKey(root->right, km);

    }
int main(){




    return 0;
}