#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int size; // size heap now
    int capacity; // max size
    int *elements; // array
}node;

    node *createNode(int capacity){
        node *maxHeap = (node*)malloc(sizeof(node));
        maxHeap->size = 0;
        maxHeap->capacity = capacity;
        maxHeap->elements = (int*)malloc(capacity *sizeof(int));
        
        return maxHeap;
    }

    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapify(node *maxHeap, int idx){
        int largest = idx;
        int left = 2*idx+1;
        int right = 2*idx + 2;

        if (left < maxHeap->size && maxHeap->elements[left] > maxHeap->elements[largest]){
        //  (check whether the index valid or not)   
        largest = left;
        }
        if (right < maxHeap->size && maxHeap->elements[right] > maxHeap->elements[largest]){
        //  (check whether the index valid or not)   
            largest = right;
        }
        if (largest != idx){
            swap(&maxHeap->elements[largest], &maxHeap->elements[idx]);
            heapify(maxHeap, largest);
        }
    }

    void insert(node *maxHeap, int key){
        if (maxHeap->size == maxHeap->capacity){
            printf("Heap Overflow\n");
            return;
        }

        int i = maxHeap->size++;
        maxHeap->elements[i] = key;

        while(i != 0 && maxHeap->elements[(i-1)/2] < maxHeap->elements[i]){
            swap(&maxHeap->elements[i],&maxHeap->elements[(i-1)/2]);
            i = (i-1)/2;
        }
    }
    
    void deleteMax(node *maxHeap){
        if (maxHeap->size <= 0){
            printf("Heap is empty!\n");
            return;
        }

        if(maxHeap->size == 1){
            maxHeap->size--;
            return;
        }

        maxHeap->elements[0] = maxHeap->elements[maxHeap->size-1];
        maxHeap->size--;
        heapify(maxHeap, 0);
    }

    int findMax(node *maxHeap){
        if (maxHeap->size <= 0){
            printf("Heap is Empty\n");
            return 0;
        }

        return maxHeap->elements[0];
    }

    int findMin(node *maxHeap){
        if (maxHeap->size == 0){
            printf("Heap is Empty\n");
            return 0;
        }

        int min = maxHeap->elements[0];

        for (int i = 0; i < maxHeap->size; i++){
            if (maxHeap->elements[i] < min){
                min = maxHeap->elements[i];
            }
        }

        return min;
    }

    void display(node *heap){
        for(int i = 0; i < heap->size; i++){
            printf("%d ", heap->elements[i]);
        }
        printf("\n");
    }


int main(){
    node *heap = createNode(100);
    insert(heap, 50);
    insert(heap, 20);
    insert(heap, 10);
    insert(heap, 30);
    // display(heap);
    deleteMax(heap);
    display(heap);


    return 0;
}