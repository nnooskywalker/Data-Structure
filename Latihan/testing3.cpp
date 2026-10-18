#include <stdio.h>
#include <stdlib.h>
#define gc getchar()
typedef struct node{
    int value;
    struct node *right;
    struct node *left;
}node;

    node *createNode (int value){
        node *newNode = (node*)malloc(sizeof(node));
        newNode->value = value;
        newNode->right = NULL;
        newNode->left = NULL;

        return newNode;
    }

    node *insertNode(node *root, int value){
        if (root == NULL){
            return createNode(value);
        }
        else if (value < root->value){
            root->left = insertNode(root->left, value);
        }
        else if (value > root->value){
            root->right = insertNode(root->right, value);
        }


        return root;
    }

    int lowestScore(node *root, int *value){
        if (root == NULL){
            return *value;
        }
        if (root->value < *value){
            *value = root->value;
        }

        lowestScore(root->left, value);
        lowestScore(root->right, value);

        return *value;
    }

    int highestScore(node *root, int *value){
        if (root == NULL){
            return *value;
        }
        if (root->value > *value){
            *value = root->value;
        }

         highestScore(root->left, value);
         highestScore(root->right, value);

        return *value;
    }
    
    void deepestLevel(node *root, int depth, int *maxDepth){
        if (root == NULL){
            return;
        }

        if (root->left == NULL && root->right == NULL){
            if (depth > *maxDepth){
                *maxDepth = depth;
                printf("%d ", root->value);
            }
            else if ( depth == *maxDepth){
                printf("%d ", root->value);
            }
        }
        deepestLevel(root->left, depth+1, maxDepth);
        deepestLevel(root->right, depth+1, maxDepth);
    }


int main(){
    node *root = NULL;
    int input = 0, lowest = 9999, highest = -9999;
    int maxLevel = 0;

    scanf("%d",&input); gc;

    for(int i = 0; i < input; i++){
        int scan = 0;
        scanf("%d",&scan); gc;
        root = insertNode(root,scan);
    }

    lowestScore(root,&lowest);
    highestScore(root,&highest);
    

    printf("Lowest : %d\n",lowest);
    printf("Hishest : %d\n",highest);
    printf("Deepest : ");
    deepestLevel(root, 1, &maxLevel);




    return 0;
}