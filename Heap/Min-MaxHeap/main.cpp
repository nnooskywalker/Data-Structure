#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define gc getchar()

typedef struct{
    char id[100];
    int score;
}data;

typedef struct heap{
    int size;
    int capacity;
    data *elements;
}heap;

    heap *createHeap(int capacity){
        heap *newHeap = (heap*)malloc(sizeof(heap));
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

    int parent(int i){
        return (i-1)/2;
    }

    int leftChild(int i){
        return (2*i) + 1;
    }

    int rightChild(int i){
        return (2*i)+2;
    }

    int isEvenLevel(int i){
        int level = 0;
        while(i > 0){
            i = parent(i);
            level++;
        }

        return level % 2 == 0;
    }

    void bubbleUpMin(heap *h, int i){
        if (parent(parent(i)) >= 0 && h->elements[i].score < h->elements[parent(parent(i))].score){
            swap(&h->elements[i],&h->elements[parent(parent(i))]);
            bubbleUpMin(h, parent(parent(i)));
        }
    }

    void bubbleUpMax(heap *h, int i){
        if (parent(i) > 0 && h->elements[i].score > h->elements[parent(parent(i))].score){
            swap(&h->elements[i], &h->elements[parent(parent(i))]);
            bubbleUpMax(h, parent(parent(i)));
        }
    }

    void bubbleUp(heap *h, int i){
        if (i == 0) return;

        if (isEvenLevel(i)){
            if (h->elements[i].score > h->elements[parent(i)].score){
                swap(&h->elements[i], &h->elements[parent(i)]);
                bubbleUpMax(h, parent(i));
            }
            else{
                bubbleUpMin(h, i);
            }
        }

        else{
            if (h->elements[i].score < h->elements[parent(i)].score){
                swap(&h->elements[i], &h->elements[parent(i)]);
                bubbleUpMin(h, parent(i));
            }
            else{
               bubbleUpMax(h, i);
            }

        }
    }

    void bubbleDownMin(heap *h, int i){
        int n = h->size;

        int smallest = i;
        int  left = leftChild(i);
        int right = rightChild(i);

        if (left < n && h->elements[left].score < h->elements[smallest].score){
            smallest = left;
        }
        if (right < n && h->elements[right].score < h->elements[smallest].score){
            smallest = right;
        }

        int g;
        if (left < n){
            g = leftChild(left);
            if (g < n && h->elements[g].score < h->elements[smallest].score){
                smallest = g;
            }

            g = rightChild(right);
            if (g < n  && h->elements[g].score < h->elements[smallest].score){
                smallest = g;
            }
        }

        if (smallest != i){
            swap(&h->elements[i], &h->elements[smallest]);

            if (smallest >= leftChild(left)){
                int p = parent(smallest);
                if (h->elements[smallest].score > h->elements[p].score){
                    swap(&h->elements[smallest], &h->elements[p]);
                }
                bubbleDownMin(h, smallest);
            }
        }
    }

    void bubbleDownMax(heap *h, int i){
        int n = h->size;
        
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < n && h->elements[left].score > h->elements[largest].score){
            largest = left;
        }
        if (right < n && h->elements[right].score > h->elements[largest].score){
            largest = right;
        }

        int g;
        if (left < n){
            g = leftChild(left);
            if (g < n && h->elements[g].score > h->elements[largest].score){
                largest = g;
            }

            g = rightChild(right);
            if (g < n  && h->elements[g].score > h->elements[largest].score){
                largest = g;
            }
        }

        if (largest != i){
            swap(&h->elements[i], &h->elements[largest]);

            if (largest >= leftChild(left)){
                int p = parent(largest);
                if (h->elements[largest].score < h->elements[p].score){
                    swap(&h->elements[largest], &h->elements[p]);
                }
                bubbleDownMin(h, largest);
            }
        }
    }

    void bubbleDown(heap *h, int i){
        if (isEvenLevel(i)){
            bubbleDownMin(h, i);
        }
        else{
            bubbleDownMax(h, i);
        }
    }


    void insert(heap *newHeap, char *name, int score){
        if(newHeap->size == newHeap->capacity){
            printf("Heap overflow\n");
            return;
        }

       newHeap->elements[newHeap->size].score = score;
       strcpy(newHeap->elements[newHeap->size].id, name);
        newHeap->size++;
        bubbleUp(newHeap, newHeap->size-1);
    }

    void deleteMin(heap *newHeap){
        if (newHeap->size <= 0){    
            printf("Heap is empty!\n");
            return;
        }

        if (newHeap->size == 1){
            newHeap->size--;
            return;
        }

        newHeap->elements[0] = newHeap->elements[newHeap->size-1];

        newHeap->size--;
        bubbleDown(newHeap, 0);
    }

    void deleteMax(heap *newHeap){
        if (newHeap->size <= 0){
            printf("Heap is Empty!\n");
            return;
        }

        if (newHeap->size == 1){
            newHeap->size--;
            return;
        }

        int maxIndex;

        if (newHeap->size == 2){
            maxIndex = 1;
        }
        else{
            maxIndex = (newHeap->elements[1].score > newHeap->elements[2].score ? 1 : 2);
        }

        newHeap->elements[maxIndex] = newHeap->elements[newHeap->size-1];
        newHeap->size--;
        bubbleDown(newHeap, maxIndex);
    }

int main(){


    return 0;
}