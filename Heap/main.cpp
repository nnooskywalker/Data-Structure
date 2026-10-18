#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int size;
    int capacity;
    int *elements;
}node;

    node *createNode(int capacity){
        node *newNode = (node*)malloc(sizeof(node));
        newNode->size = 0;
        newNode->capacity = capacity;
        newNode->elements = (int*)malloc(capacity*sizeof(int));

        return newNode;
    }

    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapify(node *heap, int idx){
        int smallest = idx;
        int left = (2*idx)+1;
        int right = (2*idx)+2;

        if (left < heap->size && heap->elements[left] < heap->elements[smallest]){
            smallest = left;
        }
        if (right < heap->size && heap->elements[right] < heap->elements[smallest]){
            smallest = right;
        }
        if (smallest != idx){
            swap(&heap->elements[smallest], &heap->elements[idx]);
            heapify(heap, smallest);
        }
    }

    void insert(node *heap, int data){
        if (heap->size == heap->capacity){
            printf("Heap Overflow!");
            return;
        }

        int i = heap->size++;
        heap->elements[i] = data;

        while(i != 0 && heap->elements[(i-1)/2] > heap->elements[i]){
            swap(&heap->elements[i], &heap->elements[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void deleteMin(node *heap){
        if (heap->size <= 0){
            printf("Heap is Empty !");
            return;
        }

        if (heap->size == 1){
            heap->size--;
            return;
        }

        heap->elements[0] = heap->elements[heap->size-1];
        heap->size--;
        heapify(heap, 0);
    }

    int findMax(node *heap){
        if (heap->size <= 0){
            printf("Heap is Empty\n");
            return 0;
        }

        int max = heap->elements[0];

        for(int i = 0; i < heap->size; i++){
            if (heap->elements[i] > max){
                max = heap->elements[i];
            }
        }

        return max;
    }


    void display(node *heap){
        for(int i = 0; i < heap->size; i++){
            printf("%d ", heap->elements[i]);
        }
        printf("\n");
    }



int main(){
    node *heap = createNode(150);
    
    insert(heap, 100);
    insert(heap, 120);
    insert(heap, 50);
    display(heap);





    return 0;
}