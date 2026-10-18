#include <stdio.h>

int heap[100] = {};
int counter = 1;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(int newData){
    int currentIdx = counter;
    heap[currentIdx] = newData;
    // min heap : '<'
    // max heap : '>'
    while(currentIdx != 1 && heap[currentIdx] < heap[currentIdx/2]){
        //                   (membandingkan value now dengan parent nya)
        int parentIdx = currentIdx/2;
        swap(&heap[currentIdx], &heap[parentIdx]);

        currentIdx = parentIdx;
    }
    counter++;
}

bool isLeaf(int currentIdx){
    // leaf node: jumlah node / 2;
    if (currentIdx > (counter-1)/2) return true;
    return false;
}

void heapify(int currentIdx){
    printf("%d\n", currentIdx);
    if (isLeaf(currentIdx)) return;                                                                                                                                           

    int leftChildIdx = currentIdx*2;
    int rightChildIdx = currentIdx*2+1;
    
    if (heap[leftChildIdx] < heap[currentIdx] || heap[rightChildIdx] < heap[currentIdx]){
        if (heap[leftChildIdx] < heap[rightChildIdx]){
            swap(&heap[leftChildIdx], &heap[currentIdx]);

            heapify(leftChildIdx);
        }
        else{
            swap(&heap[rightChildIdx], &heap[currentIdx]);
    
            heapify(rightChildIdx);

        }
    }
}


void pop(){
    int rootIdx = 1;
    printf("Pop: %d\n", heap[rootIdx]);
    heap[rootIdx] = heap[counter-1]; 
    heap[counter-1] = 9999;
    counter--;

    heapify(rootIdx);
}



void print(){
    for(int i = 1; i < counter; i++){
        printf("%d ", heap[i]);
    }
    puts("");
}



int main(){
    push(3);
    push(5);
    push(1);
    push(2);
    push(15);
    print();
    pop();
    print();
}