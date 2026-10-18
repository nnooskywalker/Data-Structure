#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define gc getchar()
struct date{
    int day;
    char month[20];
    int year;
};

typedef struct node{
    date birth;
    char id[10];
    char name[100];
    struct node *left;
    struct node *right;
}node;

node *createNode(date birth, char *id, char *name){
    node *newNode = (node*)malloc(sizeof(node));

    newNode->birth.day = birth.day;
    strcpy(newNode->birth.month, birth.month);
    newNode->birth.year = birth.year;
    strcpy(newNode->id, id);
    strcpy(newNode->name,name);
    newNode->left = newNode->right = NULL;

    return newNode;
}

node *insertNode (node *root, char *id, char *name, date birth){
    if (root == NULL){
        return createNode(birth, id, name);
    }
    else if(strcmp(id,root->id) < 0){
        root->left = insertNode(root->left, id, name, birth);
    }
    else if(strcmp(id,root->id) > 0){
        root->right = insertNode(root->right, id, name, birth);
    }
    else{
        printf("Duplicated Data\n");
    }

    return root;

}

void updateData(node *root, char *id, char *newName){
    if (root == NULL){
        printf("Data Not Found\n");
    }
    else if(strcmp(id,root->id) < 0){
        updateData(root->left, id, newName);
    }
    else if(strcmp(id, root->id) > 0){
        updateData(root->right, id, newName);
    }
    else{
        strcpy(root->name,newName);
        printf("Update Sucesfully!\n");
    }
}


void inOrder(node *root){
    if (root == NULL) return;
    inOrder(root->left);
    printf("Name : %s\n",root->name);
    printf("ID : %s\n",root->id);
    printf("Day : %d\n",root->birth.day);
    printf("Month : %s\n",root->birth.month);
    printf("Year : %d\n\n",root->birth.year);
    inOrder(root->right);
}

node *findLeft(node *root){
    while(root->right != NULL){
        root = root->right;
    }

    return root;
}


node *removeNode(node *root, char *id){
    if (root == NULL){
        printf("Data Not Found\n");
        return NULL;
    }
    

    if (strcmp(id, root->id) < 0){
        root->left = removeNode(root->left, id);
    }
    else if(strcmp(id,root->id) > 0){
        root->right = removeNode(root->right, id);
    }
    else{
        if(root->right == NULL && root->left == NULL){
            free(root);
            printf("ID \"%s\" sucesfully removed !\n",id);
            return NULL;
        }
        else if(root->left == NULL){
            node *temp = root->right;
            free(root);
            printf("ID \"%s\" sucesfully removed !\n",id);
            return temp;
        }
        else if(root->right == NULL){
            node *temp = root->left;
            free(root);
            printf("ID \"%s\" sucesfully removed !\n",id);
            return temp;
        }
        else{
            node *temp = findLeft(root->left);
            strcpy(root->id,temp->id);
            strcpy(root->name,temp->name);
            root->birth.day = temp->birth.day;
            strcpy(root->birth.month, temp->birth.month);
            root->birth.year = temp->birth.year;
            root->left = removeNode(root->left, temp->id);
        }
        printf("ID \"%s\" sucesfully removed !\n",id);
    }


    return root;
}


void generateid(char *name, char *newId){
    newId[0] = toupper(name[0]);
    newId[1] = toupper(name[1]);

    for(int i= 2; i < 5; i++){
        newId[i] = '0' + rand() % 10;
    }

    newId[5] = '\0';


}


void menu(){
    node *root = NULL;
    date tgl;
    int choose = 0;
    char inputName[100], inputID[100];
    srand(time(NULL));
    char id[6];

    while(choose != 5){
        puts("1. Insert");
        puts("2. Update");
        puts("3. View");
        puts("4. Delete");
        puts("5. Exit");
        printf(">> ");
        scanf("%d",&choose); gc;

        switch(choose){
            case 1:
                printf("Name : ");
                scanf(" %[^\n]",inputName); 
                printf("Day : ");
                scanf("%d",&tgl.day); gc;
                printf("Month : ");
                scanf("%s",tgl.month); gc;
                printf("Year : ");
                scanf("%d",&tgl.year); gc;
                generateid(inputName, id);
                printf("Your ID is \"%s\"\n",id);

                root = insertNode(root, id, inputName, tgl);
                break;
            case 2:
                printf("Input New Name : ");
                scanf(" %[^\n]",inputName);
                printf("Input key (ID) : ");
                scanf("%s",inputID);

                updateData(root, inputID, inputName);
                break;
            case 3:
                if(root == NULL){
                    printf("Data Kosong\n");
                }
                else{
                    inOrder(root);
                }
                break;
            case 4:
                printf("Input Key (ID) : ");
                scanf("%s",inputID);
                root = removeNode(root, inputID);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid\n");
                break;
        }
    }
}

int main(){
    menu();






    return 0;
}