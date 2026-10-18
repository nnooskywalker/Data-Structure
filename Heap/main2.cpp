#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int size;
    int capacity;
    int *elements;
}node;

    node *createHeap(int capacity){
        node *newHeap = (node*)malloc(sizeof(newHeap));
        newHeap->size = 0;
        newHeap->capacity = capacity;
        newHeap->elements = (int*)malloc(capacity*sizeof(int));
        return newHeap;
    }

    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }


    void heapify(node *heap, int idx){
        int largest = idx;
        int left = (2*idx) + 1;
        int right = (2*idx) + 2;

        if (left < heap->size && heap->elements[left] > heap->elements[largest]){
            largest = left;
        }
        if (right < heap->size && heap->elements[right] >  heap->elements[largest]){
            largest = right;
        }
        if (largest != idx){
            swap(&heap->elements[largest],&heap->elements[idx]);
            heapify(heap,largest);
        }
    }


    void insert(node *heap, int data){
        if (heap->size >= heap->capacity){
            printf("Heap overflow");
            return;
        }

        int i = heap->size++;
        heap->elements[i] = data;

        while(i != 0 && heap->elements[(i-1)/2] < heap->elements[i]){
            swap(&heap->elements[i],&heap->elements[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void remove(node *heap){
        if (heap->size <= 0){
            printf("Heap is empty");
            return;
        }
        if (heap->size == 1){
            heap->size--;
            return;
        }

        heap->elements[0] = heap->elements[heap->size-1];
        heap->size--;
        heapify(heap,0);
    }

int main(){



    return 0;
}