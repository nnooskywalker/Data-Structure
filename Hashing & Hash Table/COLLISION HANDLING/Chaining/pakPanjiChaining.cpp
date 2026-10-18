#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct DataItem {
    int key;
    int data;
    struct DataItem *next;
} DataItem;

DataItem* hashTable[SIZE];

int hashFunc(int key) {
    return key % SIZE;
}

void insert(int key, int data) {
    DataItem* newItem = malloc(sizeof(DataItem));
    newItem->key = key;
    newItem->data = data;
    newItem->next = NULL;

    int hashIndex = hashFunc(key);

    if (hashTable[hashIndex] == NULL) {
        // Jika bucket kosong, langsung sisipkan data baru di sana
        hashTable[hashIndex] = newItem;
        printf("Data dengan key %d berhasil ditambahkan di bucket %d\n", key, hashIndex);
    } else {
        // Traversal hingga mencapai akhir chain, kemudian sisipkan data baru di belakang
        DataItem* current = hashTable[hashIndex];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newItem;
        printf("Data dengan key %d berhasil ditambahkan di bucket %d (di belakang chain)\n", key, hashIndex);
    }
}

DataItem* search(int key) {
    int hashIndex = hashFunc(key);
    DataItem* current = hashTable[hashIndex];
    while (current != NULL) {
        if (current->key == key) {
            printf("Data ditemukan: %d\n", current->data);
            return current;
        }
        current = current->next;
    }
    printf("Data dengan key %d tidak ditemukan\n", key);
    return NULL;
}

DataItem* deleteItem(int key) {
    int hashIndex = hashFunc(key);
    DataItem* current = hashTable[hashIndex];
    DataItem* prev = NULL;
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                // Hapus data pada awal chain
                hashTable[hashIndex] = current->next;
            } 
            else {
                prev->next = current->next;
            }
            printf("Berhasil menghapus data dengan key %d\n", key);
            return current;
        }
        prev = current;
        current = current->next;
    }
    printf("Data dengan key %d tidak ditemukan, tidak dapat menghapus\n", key);
    return NULL;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("Bucket %d:", i);
        DataItem* current = hashTable[i];
        while (current != NULL) {
            printf("(%d, %d) -> ", current->key, current->data);
            current = current->next;
        }
        printf("~~~\n");
    }
}

int main() {
    insert(1, 56);
    insert(11, 23);
    insert(111, 34);
    display();

    search(111);
    
    deleteItem(11);
    display();

    return 0;
}