#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char name[100];
    int power;
}data;

typedef struct node{
    int size;
    int capacity;
    data *elements;
}node;

    node *createHeap(int capacity){
        node *newHeap = (node*)malloc(sizeof(node));
        newHeap->size = 0;
        newHeap->capacity = capacity;
        newHeap->elements = (data*)malloc(capacity*sizeof(data));

        return newHeap;
    }

    void swap(data *a, data *b){
        data temp = *a;
        *a = *b;
        *b = temp;
    }

    int compare(data *a, data *b){
        if (a->power > b->power) return 1;
        if (a->power < b->power) return 0;

        if(strcmp(a->name, b->name) < 0) return 1;
    }

    void heapify(node *heap, int idx){
        int largest = idx;
        int left = (2*idx) + 1;
        int right = (2*idx) + 2;

        if (left < heap->size && compare(&heap->elements[left], &heap->elements[largest])){
            largest = left;
        }
        if (right < heap->size && compare(&heap->elements[right], &heap->elements[largest])){
            largest = right;
        }
        if (largest != idx){
            swap(&heap->elements[largest], &heap->elements[idx]);
            heapify(heap, largest);
        }
    }

    void insert(node *heap, int power, char *name){
        if (heap->size == heap->capacity){
            printf("Heap is overflow !\n");
            return;
        }

        int i = heap->size++;
        heap->elements[i].power = power;
        strcpy(heap->elements[i].name, name);

        while(i != 0 && compare(&heap->elements[i], &heap->elements[(i-1)/2])){
            swap(&heap->elements[i],&heap->elements[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void remove(node *heap){
        if (heap->size <= 0){
            printf("Heap is empty!\n");
            return;
        }
        printf("%s %d\n",heap->elements[0].name, heap->elements[0].power);
        
        if(heap->size == 1){
            heap->size--;
            return;
        }

        heap->elements[0] = heap->elements[heap->size-1];
        heap->size--;
        heapify(heap, 0);
    }
int main(){
    node *heap = createHeap(100);

    insert(heap, 100, "Otong Surotong");
    insert(heap, 120, "A20RA");
    insert(heap, 120, "A22ADIUS");
    insert(heap, 120, "A21MUTH");

    int n = heap->size;
    for(int i = 0; i < n; i++){
        remove(heap);
    }





    return 0;
}