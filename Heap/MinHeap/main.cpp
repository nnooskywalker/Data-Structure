#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int size; // size heap now
    int capacity; // max size
    int *elements; //array
}node;

    node *createHeap(int capacity){
        node *minHeap = (node*)malloc(sizeof(node));
        minHeap->size = 0;
        minHeap->elements = (int*)malloc(capacity *sizeof(int));
        minHeap->capacity = capacity;
        return minHeap;
    }

    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapify(node *minHeap, int idx){
        int smallest = idx;
        int left = 2*idx+1;
        int right = 2*idx+2;

        if (left < minHeap->size && minHeap->elements[left] < minHeap->elements[smallest]){
            smallest = left;
        }
        if (right < minHeap->size && minHeap->elements[right] < minHeap->elements[smallest]){
            smallest = right;
        }
        if (smallest != idx){
            swap(&minHeap->elements[smallest], &minHeap->elements[idx]);
            heapify(minHeap, smallest);
        }
    }

    void insert(node *minHeap, int key){
        if (minHeap->size == minHeap->capacity){
            printf("Heap overflow\n");
            return;
        }

        int i = minHeap->size++;
        minHeap->elements[i] = key;

        // (i-1)/2 = parent
        while (i != 0 && minHeap->elements[(i-1)/2] > minHeap->elements[i]){
            swap(&minHeap->elements[i], &minHeap->elements[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    int findMin(node *minHeap){
        if (minHeap->size <= 0){
            printf("Heap is empty\n");
            return 0;
        }
        return minHeap->elements[0];
    }

    int findMax(node *minHeap){
        if (minHeap->size <= 0){
            printf("Heap is Empty\n");
            return 0;
        }

        int max = minHeap->elements[0];
        for (int i = 1; i < minHeap->size; i++){
            if (minHeap->elements[i] > max){
                max = minHeap->elements[i];
            }
        }
        return max;
    }

    void deleteMin(node *minHeap){
        // size empty
        if (minHeap->size <= 0){
            printf("Heap is Empty\n");
            return;
        }
        
        //contains 1 node
        if (minHeap->size == 1){
            minHeap->size--;
            return;
        }

        // contains > 1 node & do heapify

        //change with last acessed node
        minHeap->elements[0] = minHeap->elements[minHeap->size - 1]; 
        minHeap->size--;
        heapify(minHeap, 0);
    }

    void displayHeap(node *heap){
        for (int i = 0; i < heap->size; i++){
            printf("%d ",heap->elements[i]);
        }
        printf("\n");
    }

int main(){
    node *heap = createHeap(100);

    insert(heap, 50);
    insert(heap, 20);
    insert(heap, 10);
    insert(heap, 30);
    // displayHeap(heap);
    deleteMin(heap);
    displayHeap(heap);


    return 0;
}