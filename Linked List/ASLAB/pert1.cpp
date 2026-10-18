#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct mahasiswa{
    char nama[100];
   struct mahasiswa *next;
} mahasiswa;

    mahasiswa *head = NULL;
    mahasiswa *tail = NULL;

mahasiswa* createMahasiswa(char *nama){
    mahasiswa *newMahasiswa = (mahasiswa*)malloc(sizeof(mahasiswa));

    strcpy(newMahasiswa->nama,nama);
    newMahasiswa->next = NULL;

    return newMahasiswa;
 
}

void insertHead(char* name){
    mahasiswa *newMahasiswa = createMahasiswa(name);
 

    if (head == NULL){
        head = tail = newMahasiswa;
    }

    else{
        newMahasiswa->next = head;
        head = newMahasiswa;

    }

}

void printMahasiswa(){
    mahasiswa *curr = head;
    while(curr != NULL){
        printf("%s -> ",curr->nama);

        curr = curr->next;
        
    }


    printf("NULL\n");
}



int main (){
 
    insertHead((char*)"AC24DIA");
    insertHead((char*)"AMB17ON");
    insertHead((char*)"A22ADIANTS");
    insertHead((char*)"A21MUTH");
    printMahasiswa();



    //initialize array of String
    // char strings[][100] = {"Jevon","Louis","Edbert"};

    // int size = sizeof(strings) / sizeof(strings[0]);

    // for(int i = 0; i < size; i++){
    //     printf("%s, ",strings[i]);
    // }

    //pointer -> data yang menunjuk ke sebuah address
    //declare

    // //mallloc -> assign memory, tapi blocknya tidak dibersihkan
    // mahasiswa *mhs = (mahasiswa*)malloc(sizeof(mahasiswa));
    // mhs->nama = (char *)malloc(sizeof("Joko"));













    return 0;
}

