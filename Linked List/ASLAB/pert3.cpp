#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Double Linked List
struct mahasiswa{
    int nim;
    char nama[100];
    struct mahasiswa *next;
    struct mahasiswa *prev;
};


//queueu --> FIFO
//enqueue --> add data
// dequeue --> delete data
struct mahasiswa *head = NULL;


struct mahasiswa *createMahasiswa(int nim, char *nama){
    struct mahasiswa *newData = (mahasiswa*)malloc(sizeof(mahasiswa));
    newData->nim = nim;
    strcpy(newData->nama, nama);
    newData->next = NULL;
    newData->prev = NULL;


    return newData;
}

//push(head)
void pushHead(struct mahasiswa *newData){
    if (head == NULL){
        head = newData;
        return;
    }

    head->prev = newData;
    newData->next = head;
    head = newData;
}

//Push (tail)
void pushTail(struct mahasiswa *newData){
    if (head == NULL){
        head = newData;
    }

    struct mahasiswa *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newData;
    newData->prev = temp;
}

// Push (Mid)
void pushMid(struct mahasiswa *newData){
    if (head == NULL){
        head = newData;
        return;
    }


    struct mahasiswa *temp = head;
    //kondisi kalau data baru lebih kecil dari head
    if (temp->nim > newData->nim){
        pushHead(struct mahasiswa *newData);
        return;
    }

    while(temp->next != NULL && temp->next->nim < newData->nim){
        temp = temp->next;
    }

    newData->prev = temp;
    newData->next = temp->next;
    temp->next = newData;

    if(newData->next != NULL){
        temp->next->prev = newData;
    }



}

void popHead(){
    if (head == NULL){
        printf("Tidak ada data\n");
        return;
    }

    struct mahasiswa *temp = head;
    if(temp->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    head = head->next;
    head->prev = NULL;

    free(temp);
}

void popTail(){
    if (head == NULL){
        printf("Tidak ada data\n");
        return;
    }

    struct mahasiswa *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }   

    //case cuma 1 data
    if(temp->prev == NULL){
        free(temp);
        head = NULL;
        return;
    }

    temp->prev->next = NULL;
    free(temp);


     
}

struct mahasiswa *find(int nim){
    if(head == NULL){
        printf("No Data\n");
        return NULL;
    }

    struct mahasiswa *temp = head;
    while(temp != NULL){
        if (temp->nim == nim){
            return temp;
        }
        temp = temp->next;
    }
    printf("Data not found\n");
    return NULL:
}

void popMid(int nim){
        if (head == NULL){
            printf("No Data\n");
            return ;
        }

        struct mahasiswa *temp = find(nim);
        if(temp == NULL){
            return;
        }

        if(temp->prev == NULL){
            popHead();
            return;
        }

        if(temp->next == NULL){
            popTail();
            return;
        }

        temp->prev = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
}
//print(Forward)
void printForward(){
    if (head == NULL){
        printf("No data\n");
        return;
    }

    struct mahasiswa *temp = head;

    while(temp != NULL){
        printf("%d - %s\n",temp->nim, temp->nama);

        temp =  temp->next;
    }
}


void printBackward(){
    if (head == NULL){
        printf("No data\n");
        return;
    }

    struct mahasiswa*temp = head;

    //pakai kalau tidak ada tail
    while(temp->next != NULL){
        printf("%d - %s",temp->nim, temp->nama);
        temp = temp->next;
    }

    while(temp != NULL){
        printf("%d - %s\n", temp->nim, temp->nama);
        temp = temp->prev;
    }
}
int main (){
    // pushHead(createMahasiswa(5, "Zenli"));
    // pushHead(createMahasiswa(5, "Mr.Whatsit"));
    // pushHead(createMahasiswa(5, "Bob"));
    // pushTail(createMahasiswa(10,"Jevon"));
    // printForward();

    //Queueu biasa
    pushMid(createMahasiswa(8, "Zenli"));
    pushMid(createMahasiswa(3, "Jeremy"));
    pushMid(createMahasiswa(10, "Marchel"));
    pushMid(createMahasiswa(10, "Zenli"));
    pushMid(createMahasiswa(3, "Jevon"));





    return 0;
}