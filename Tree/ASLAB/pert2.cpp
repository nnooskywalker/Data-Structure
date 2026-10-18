#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char name[100];
    int age;
    node *left;
    node *right;
};

    struct node *createNode(char *name, int age){
        node *curr = (struct node*)malloc(sizeof( struct node));
        strcpy(curr->name,name);

        curr->age = age;
        curr->left = NULL;
        curr->right = NULL;
        return curr;
    }

    // Insert Data
    struct node *insertNode(node *curr, char *name, int age){
        if(curr == NULL){
            return createNode(name, age);
        }
        else if(strcmp(name, curr->name) < 0){
            curr->left = insertNode(curr->left, name, age);
        }
        else if(strcmp(name, curr->name) > 0){
            curr->right = insertNode(curr->right, name, age);
        }
        else{
            printf("Duplicated Name\n");
        }

        return curr;
    }


    void inOrder(struct node *curr){
        if (curr == NULL) return;
        inOrder(curr->left);
        printf("%s %d\n",curr->name, curr->age);
        inOrder(curr->right);
    }

    // Search Data
    struct node *searchNode(node *curr, char *name){
        if (curr == NULL){
            printf("Data Not Found\n");
            return NULL;
        }
        else if (strcmp(name, curr->name) < 0){
            return searchNode(curr->left,name);
        }
        else if(strcmp(name, curr->name) > 0){
            return searchNode(curr->right,name);
        }
        else{
            printf("%d %s\n",curr->age,curr->name);
            return curr;
        }
    }

    struct node *predecessor(struct node *now){

        while(now != NULL){
            now = now->right;
        }

        return now;
    }

    struct node *pop(struct node *curr, char *name){
        if (curr == NULL){
            printf("Data Not Found\n");
            return NULL;
        }

        if (strcmp(name, curr->name) < 0){
           curr->left = pop(curr->left,name);
        }
        else if (strcmp(name, curr->name) > 0){
            curr->right =  pop(curr->right,name);
        }
        else{
            if (curr->right == NULL && curr->left == NULL){
                free(curr);
                return NULL;
            }
            else if(curr->right == NULL){
                struct node *temp = curr->left;
                free(curr);
                return temp;
            }
            else if(curr->left == NULL){
                struct node *temp = curr->right;
                free(curr);
                return temp;
            }
            else{
                struct node *temp = predecessor(curr->left);
                strcpy(curr->name,temp->name);
                curr->age = temp->age;

                curr->left = pop(curr->left,temp->name);
            }
        }

        return curr;
    }

    //pop All
    struct node *popAll(struct node *curr){
        while(curr != NULL){
            curr = pop(curr, curr->name);
        }

        return curr;
    }





    int main(){
        struct node *root = NULL;
        root = insertNode(root,"Jepon",23);
        root = insertNode(root,"Danu",19);
        root = insertNode(root,"Randi",28);
        root = insertNode(root,"Tata",18);
        root = insertNode(root,"Darren",24);
        root = insertNode(root,"Michelle",22);
        inOrder(root);
        
        struct node *search = searchNode(root,"Tata");
        
        puts("====================");
        root = pop(root,"Darren");
        root = pop(root, "Michelle");
        
        inOrder(root);
        

        return 0;
    }





