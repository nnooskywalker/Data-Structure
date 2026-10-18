#include <stdio.h>
#include <string.h>
#define TABLE_SIZE 100
#define OCCUPIED 0 // sedang berisi data
#define EMPTY 1 // belum pernah diisi
#define DELETED 2 // pernah diisi, lalu dihapus

typedef struct{
    int key;
    int data;
    int status;
}mahasiswa;

mahasiswa hashTable[TABLE_SIZE];

void setHash(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashTable[i].status = EMPTY;
    }
}

int hashFunction(int key){
    //mid square
    long long temp = key * key;
    char str[20];
    sprintf(str,"%lld",temp);
    int len = strlen(str);

    int mid = len / 2;
    int index = 0;

    if (len % 2 == 0){
        index = (str[mid-1] - '0')*10 + (str[mid] - '0');
    }
    else{
        index = (str[mid-1] - '0')*100 + (str[mid] - '0')*10 + (str[mid+1] - '0'); 
    }

    return index % TABLE_SIZE;
}

//insert data
void insert(mahasiswa mhs){
    int index = hashFunction(mhs.key);

    while(hashTable[index].status != EMPTY && hashTable[index].status != DELETED){
/*  atau : hashTable[index].status == OCCUPIED  */
        index = (index + 1) % TABLE_SIZE;
    }

    hashTable[index].key = mhs.key;
    hashTable[index].data = mhs.data;
    hashTable[index].status = OCCUPIED;
    
}

//delete data
void deleteData(mahasiswa mhs){
    int index = hashFunction(mhs.key);
    int start = index;

    while(hashTable[index].status != EMPTY){
        if(hashTable[index].status == OCCUPIED && hashTable[index].key == mhs.key){
            hashTable[index].status = DELETED;
            return;
        }

        index = (index + 1) % TABLE_SIZE;
        if (index == start){
            break;
        }
    }
}

//searching
void search(mahasiswa mhs){
    int index = hashFunction(mhs.key);
    int start = index;

    while(hashTable[index].status != EMPTY){
        if ( hashTable[index].status == OCCUPIED && hashTable[index].key == mhs.key){
            printf("Data mahasiswa pada index ke %d adalah %d",index+1,hashTable[index].data);
            return;
        }
        index = (index + 1) % TABLE_SIZE;

        if(index == start){
            printf("Data Not Found\n");
            break;
        }
    }
}


//display data
void display(){
    for(int i = 0; i < TABLE_SIZE; i++){
       if(hashTable[i].status == EMPTY){
        printf("index ke - %d : EMPTY\n",i);
       }
       else if(hashTable[i].status == DELETED){
        printf("Index ke - %d : DELETED\n",i);
       }
       else{
        printf("Index ke - %d :\n",i);
        printf("Key = %d\n",hashTable[i].key);
        printf("Data  = %d\n",hashTable[i].data);

       }
    }
}



int main (){
    setHash();
display();



    return 0;
}