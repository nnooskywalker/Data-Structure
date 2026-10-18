#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define gc getchar()

typedef struct node{
    char song[100];
    char singer[100];
    int durasi;
    char id[100];
    struct node *next;
    struct node *prev;
}node;

    node *head = NULL;
    node *tail = NULL;
    node *curr = NULL;
    
    node *createNode(char *song, char *singer, int time, char *id){
        node *newNode = (node*) malloc(sizeof(node));

        
        strcpy(newNode->song,song);
        strcpy(newNode->singer,singer);
        newNode->durasi = time;
        strcpy(newNode->id, id);
        newNode->next = NULL;
        newNode->prev = NULL;
        
        return newNode;
    }
    
    
    void insertTail(char *song, char *singer, int time, char *id){
        node *newNode = createNode(song, singer, time, id);
        
        if (head == NULL){
            head = tail = newNode;
            curr = head;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertCurr(char *song, char *singer, int time, char *id){
        node *newNode = createNode(song, singer, time, id);

       if (curr->next == NULL){
        insertTail(song, singer, time, id);
       }
       else{
        newNode->next = curr->next;
        curr->next->prev = newNode;
        curr->next = newNode;
        newNode->prev = curr;
       }

    }
    
    void deleteHead(){
        if (head == NULL){
            printf("List Kosong\n");
        }

        if (head == tail){
            free(head);
            head = tail = NULL;
        }
        else{
            node *temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
    }
    
    void deleteTail(){
        if (tail == NULL){
            printf("List Kosong");
            return;
        }
        
        
        if (head == tail){
            free(tail);
            head = tail = NULL;
        }
        else{
            node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
        
        
    }
    
    void deleteMid(char *song){
        if (head == NULL){
            printf("List Kosong");
            return;
        }
        
        if (strcmp(head->song,song) == 0){
            deleteHead();
            return;
        }
        
        if(strcmp(tail->song, song) == 0){
            deleteTail();
            return;
        }
        
        node *curr = head;
        
        while(curr != NULL && strcmp(curr->song,song) != 0){
            curr = curr->next;
        }
        
        if (curr == NULL){
            printf("Song %s is Not Found!\n",song);
        }
        
        node *sNext = curr->next;
        node *sPrev = curr->prev;
        
        sNext->next = sPrev;
        sPrev->prev = sNext;
        
        free(curr);
    }
    
    
    
    void showList(){
        node *c = head;
        int no = 1;
        
        puts("Playlist Song : ");
        while(c != NULL){
            printf("%d. Tittle : %s\n",no,c->song);
            printf("    Artist : %s\n",c->singer);
            c = c->next;
            no++;
        }
    }
    
    void menu(){
        int choose = 0, inputDuration = 0;
        int k = 0, input2 = 0;
        char inputSong[100], inputArtistName[100], inputID[100];
        char inputTittle[100], inputArtist[100], inputIDNEWW[100];
        int inputDurationNEWW = 0;
        char delSong[100];
        
        while(choose != 5){
            if (k == 0){
                printf("There are no song in the playlist!\n");
            }
            else{
                showList();
            }
            
            puts("===============================");
            puts("1. Add Song");
            puts("2. Change Song");
            puts("3. Remove Song");
            puts("4. Add To Up Next");
            puts("5. Exit");
            printf(">> ");
            scanf("%d",&choose); gc;
            system("cls");
            
            switch(choose){
                case 1:
                printf("Input song tittle : ");
                scanf("%[^\n]",inputSong); gc;
                printf("Input Artist Name : "); 
                    scanf("%[^\n]",inputArtistName); gc;
                    printf("Input duration (second) : ");
                    scanf("%d",&inputDuration); gc;
                    printf("Input song ID : "); 
                    scanf("%s",inputID); gc;
                    insertTail(inputSong, inputArtistName, inputDuration, inputID);
                    k++;
                    gc;
                    system("cls");
                    break;
                    case 2:

                    if (k == 0){
                        printf("There is no song in the list\n");
                    }
                    else{
                        printf("Current Song : %s by %s\n",curr->song, curr->singer);
                        
                        puts("1. Previous Song");
                        puts("2. Next Song");
                        puts("3. Exit");
                        printf(">> ");
                        scanf("%d",&input2); gc;
                        
                        switch(input2){
                            case 1:
                                if (curr->prev == NULL){
                                    printf("There is no previous song!");
                                }
                                else{
                                    curr = curr->prev;
                                }
                                break;

                                case 2:
                                if (curr->next == NULL){
                                    printf("There is no next song!");
                                }
                                else{
                                    curr = curr->next;
                                }
                                break;

                            case 3:
                                break;
                        }
                    }
                    break;
                    case 3:
                    showList();
                    printf("Input Song Tittle : ");
                    scanf("%[^\n]",delSong); gc;
                    deleteMid(delSong);
                    gc;
                    system("cls");
                    break;
                    case 4:
                    printf("Current Song : %s",curr->song);
                    printf("Input song title : ");
                    scanf(" %[^\n]",inputTittle);
                    printf("Input artist name : ");
                    scanf(" %[^\n]",inputArtist);
                    printf("Input Duration (second) : ");
                    scanf("%d",&inputDuration); gc;
                    printf("Input song ID : ");
                    scanf("%s",inputIDNEWW); 
                    insertCurr(inputTittle, inputArtist, inputDuration, inputIDNEWW);
                    break;
                    case 5:
                    printf("Exiting....");
                    break;
                }
        }
    }
    
    int main (){
        menu();
        
        
        
        return 0;
    }