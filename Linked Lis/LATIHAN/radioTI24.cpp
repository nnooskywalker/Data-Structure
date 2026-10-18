#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define gc getchar()

typedef struct node{
    char song[100];
    char singer[100];
    struct node *next;
} node;

    node *head = NULL;
    node *tail = NULL;

 node *createNode(char *song, char *singer){
    node *newNode = (node*)malloc(sizeof(node));

    strcpy(newNode->song,song);
    strcpy(newNode->singer,singer);

    newNode->next = NULL;

    return newNode;
 }

 void insertHead(char *song, char *singer){
    node *newNode = createNode(song, singer);

    if (head == NULL){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
 }

 


 void show(){
     int no = 0;
    node *c = head;

    if (c == NULL){
        printf("List Kosong\n");
    }
    else{
        while(c != NULL){
            printf("%d. %s - %s\n",no+1, c->song,c->singer);
            c = c->next;
            no++;
        }
    }
 }

void searchSong(char target[]){
    node *c = head;
    int flag = 0, no = 0;
   

    while(c != NULL){
        if (strcmp(c->song,target) == 0){
            printf("%d. %s-%s\n",no+1,c->song,c->singer);
            flag = 1;
        }
        c= c->next;
        no++;
    }

    if (flag == 0){
        printf("Song \"%s\" not found\n",target);
    }
}

void searchSinger(char target[]){
    node *c = head;
    int flag = 0, no = 0;

    while(c != NULL){
        if (strcmp(c->singer,target) == 0){
            printf("%d. %s-%s\n",no+1,c->song,c->singer);
            flag = 1;
        }
        c = c->next;
        no++;
    }

    if (flag == 0){
        printf("Singer \"%s\" not found\n",target);
    }
}


void deleteSong(char *name){
    if(head == NULL){
        printf("List kosong\n");
        return;
    }

    // Hapus head
    if(strcmp(head->song, name) == 0){
        node *temp = head;
        head = head->next;

        if(head == NULL){ // list jadi kosong
            tail = NULL;
        }

        free(temp);
        printf("Delete Successfully\n");
        return;
    }

    // Cari node sebelum target
    node *c = head;

    while(c->next != NULL && strcmp(c->next->song, name) != 0){
        c = c->next;
    }

    if(c->next == NULL){
        printf("Song Not Found\n");
        return;
    }

    node *del = c->next;
    c->next = del->next;

    if(del == tail){
        tail = c;
    }

    free(del);
    printf("Delete Successfully\n");
}


 void menu(){
    int choose = 0, inputNum = 0;
    char singer[100], song[100];
    char cari[100], searchSongSing[100];
    char delSong[100];


    while(choose != 5){
        printf("----RADIO AC24DIA---\n");
        puts("1. Add Song");
        puts("2. View Song");
        puts("3. Search Song");
        puts("4. Delete Song");
        puts("5. Exit");
        printf(">> ");
        scanf("%d",&choose); gc;
        system("cls");

        switch(choose){
            case 1:
            printf("Add song : ");
            scanf("%[^\n]",song); gc;
            printf("Add singer : ");
            scanf("%[^\n]",singer); gc;
            insertHead(song,singer);
            printf("Press enter to continue....\n");
            gc;
            system("cls");
                break;
            case 2:
                show();
                printf("Press enter to continue....\n");
                gc;
                system("cls");
                break;
            case 3:
                strcpy(cari,"");
                while(strcmp(cari,"song") != 0 && strcmp(cari,"singer") != 0){
                    printf("Search by (song / singer) : ");
                    scanf("%s",cari); gc;
                }

                if(strcmp(cari,"song") == 0){
                    printf("Search Song : ");
                    scanf("%[^\n]",searchSongSing); gc;
                    searchSong(searchSongSing);
                }
                else{
                    printf("Search Singer : ");
                    scanf("%[^\n]",searchSongSing); gc;
                    searchSinger(searchSongSing);
                }

                printf("Press enter to continue...");
                gc;
                system("cls");
                break;
            case 4:
                printf("Input Song : ");
                scanf("%[^\n]",delSong); gc;
                deleteSong(delSong);
                gc;
                system("cls");
                break;
            case 5:
                printf("Exiting...");
                break;
        }
    }
 }


int main (){
    menu();



    return 0;
}