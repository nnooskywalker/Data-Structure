#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct mahasiswa{
    // data
    char nim[11];
    char nama[50];
    int age;
    //pointer
    struct mahasiswa *next;
};

struct mahasiswa *createMahasiswa(char *nim, char *name,int age){
    struct mahasiswa *curr = (struct mahasiswa*) malloc(sizeof(struct mahasiswa));

    //insert data ke struct
    strcpy(curr->nim,nim);
    strcpy(curr->nama,name);
    curr->age = age;

    //assign pointer
    curr->next = NULL;

    return curr;
}

struct mahasiswa *pushHead(struct mahasiswa *head,char *nim, char *name,int age){
    //kondisi gak ada data
    if(head == NULL){
        struct mahasiswa *head = createMahasiswa(nim,name, age);
    }
    //kondisi ada data
    else{
        struct mahasiswa *curr = createMahasiswa(nim, name, age);
        curr->next = head;
        head = curr;
    }

    return head;
}

struct mahasiswa *pushTail(struct mahasiswa *head,char *nim, char *name,int age){
    //kondisi gak ada data
    if(head == NULL){
        struct mahasiswa *head = createMahasiswa(nim,name, age);
    }
    //kondisi ada data
    else{
        struct mahasiswa *curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = createMahasiswa(nim,name, age);

    }

    return head;
}

struct mahasiswa *pushMid (struct mahasiswa *head, char *nim, char *name, int age){
    if (head == NULL){
        head = pushHead(head, nim, name, age);
    }
    if (strcmp(head->nim, nim) > 0){
        head = pushHead(head, nim, name, age);
    }
    //kondisi ada di tengah atau di akhir
    else{
        struct mahasiswa *curr = head;
        while(curr){ // sama kyk curr != NULL
            if (curr->next != NULL && strcmp(curr->next->nim,nim) < 0){
                curr = curr->next;
            }
            else{
                break;
            }
        }
        struct mahasiswa *temp = createMahasiswa(nim, name, age);
        temp->next = curr->next;
        curr->next = temp;
    }

    return head;
}


void view(struct mahasiswa *curr){
    while(curr != NULL){
        printf("%[%s] %s (%d)\n",curr->nim,curr->nama,curr->age);
        curr = curr->next;
    }
}

struct mahasiswa *search(struct mahasiswa *curr, char *nim){
    while(curr){
        if (strcmp(curr->nim,nim) == 0){
            return curr;
        }

        curr = curr->next;
    }

    return NULL;
}

struct mahasiswa *popHead(struct mahasiswa *head){
    // kondisi ga ada data
    if (head == NULL){ // sama kayak !head
        return NULL;
    }
    else{
        struct mahasiswa *curr = head;
        head = head->next;
        free(curr);
        printf("[!] Succesfully delete one data\n");
        return head;
    }
};

struct mahasiswa *popTail(struct mahasiswa *head){
    if (head == NULL){ // sama kayak !head
        return NULL;
    } //kondisi ada data
    else{
        struct mahasiswa *prev = NULL;
        struct mahasiswa *curr = head;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        //kondisi data > 1
        if (prev != NULL){
            prev->next = NULL;
        }
        //kondisi data hanya 1
        else{
            head = NULL;
        }
        free(curr);

        return head;
    }
    
}

struct mahasiswa *popMid(struct mahasiswa *head, char *nim){
    //kondisi gak ada data
    if (head != NULL){
        printf("[!] Nothing To Delete\n");
        return NULL;
    }
    else{
        struct mahasiswa *curr = head;
        struct mahasiswa *prev = NULL;

        while(curr){
            if(strcmp(curr->nim,nim) == 0){
                if(prev != NULL){
                    prev->next = curr->next;
                    free(curr);
                    return head;
                }
                else{
                    return popHead(head);
                }
            }
            curr = curr->next;
        }
    }
}





int main (){
    struct mahasiswa *head = NULL;
    // head = pushHead(head,"2902726864","nino",19);
    // head = pushHead(head,"2902726888","MrWhatsit",19);
    // view(head);

    head = pushMid(head,"1111111","Badui",28);
    head = pushMid(head,"9289382","Luna",30);
    head = pushMid(head,"7281278","Joseph",25);
    head = pushMid(head,"2827373","Shane",22);
    view(head);

    // struct mahasiswa *temp;
    // temp = search(head,"katak");

    // if(temp != NULL){
    //     printf("Found : [%s] %s (%d)\n",temp->nim,temp->nama,temp->age);
    // }
    // else{
    //     printf("Data Not Found\n");
    // }

    head = popHead(head);
    view(head);





    return 0;
}