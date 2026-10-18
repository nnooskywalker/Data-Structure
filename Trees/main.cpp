#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define gc getchar()

typedef struct node{
    char nama[100];
    int nim;
    struct node *left;
    struct node *right;
}node;

node *createNode(char *nama, int nim){
    node *newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->nama,nama);
    newNode->nim = nim;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node *insertData(node *root, char *nama, int nim){

    if(root == NULL){
        return createNode(nama, nim);
    }
    else if(nim < root->nim){
         root->left = insertData(root->left, nama, nim);
    }
    else if(nim > root->nim){
         root->right = insertData(root->right, nama, nim);
    }

    return root;
}


void searching(node *root, int nim){
    if (root == NULL){
        printf("Data Kosong\n");
    }
    else if (nim < root->nim){
        searching(root->left, nim);
    }
    else if (nim > root->nim){
        searching(root->right, nim);
    }
    else{
        printf("Nama : %s\n",root->nama);
        printf("NIM : %d",root->nim);
    }
}

    node * largestLeft(node *root){
        while(root != NULL){
            root = root->right;
        }

        return root;
    }


node *deleteNode(node *root, int nim){
    if (root == NULL){
        printf("Data Kosong\n");
        return root;
    }
    

    if (nim < root->nim){
        return root->left = deleteNode(root->left, nim);
    }
    else if(nim > root->nim){
        return root->right = deleteNode(root->right, nim);
    }
    else{
        if (root->right == NULL && root->left == NULL){
            free(root);
            return NULL;
        }
        else if(root->right == NULL){
            node *temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left == NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }

        node *temp = largestLeft(root);
        strcpy(root->nama, temp->nama);
        root->nim = temp->nim;
        root->left = deleteNode(root->left, temp->nim);



    }
}

void inOrder(node *root){
    if(root == NULL) return;
    inOrder(root->left);
    printf("Nama : %s\n",root->nama);
    printf("NIM : %d\n\n",root->nim);
    inOrder(root->right);
}

void menu(){
    int choose = 0, inputNim = 0;
    node *root = NULL;
    char inputNama[100];

    while(choose != 5){
        puts("1. Find Mahasiswa");
        puts("2. Insert Mahasiswa");
        puts("3. Delete Mahasiswa");
        puts("4. View List");
        puts("5. Exit");
        printf(">> ");
        scanf("%d",&choose); gc;

        switch(choose){
            case 1:
                printf("Input NIM (key) : ");
                scanf("%d",&inputNim); gc;
                searching(root, inputNim); 
                break;
            case 2:
                printf("Nama : ");
                scanf("%s",inputNama);gc;
                printf("NIM : ");
                scanf("%d",&inputNim); gc;

                root = insertData(root, inputNama, inputNim);
                break;
            case 3:
                printf("Insert NIM (key) : ");
                scanf("%d",&inputNim); gc;
                root = deleteNode(root, inputNim);
                break;
            case 4:
                if(root == NULL){
                    printf("Data Kosong\n");
                }
                else{
                    inOrder(root);
                }
                break;
            case 5:
                printf("Exiting....");
                break;
            default :
                printf("Not Found\n");
                break;
        }
    }
}
int main(){
    menu();




    return 0;
}