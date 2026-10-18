#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int num;
    struct node *next;
}node;

typedef struct{
    node *front;
    node *rear;
}queue;

typedef struct{
    node *top;
}stack;

    node *createNode(int num){
        node *newNode = (node*)malloc(sizeof(node));
        newNode->num = num;
        newNode->next = NULL;

        return newNode;
    }

    void enqueue( queue *q, int num){
        node *newNode = createNode(num);

        if (q->rear == NULL){
            q->front = q->rear = newNode;
        }
        else{
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }

    void dequeue(queue *q){
        if (q->front == NULL){
            printf("List is Empty");
            return;
        }

        if (q->front == q->rear){
            free(q->front);
            q->front = q->rear = NULL;
        }
        else{
            node *del = q->front;
            q->front = q->front->next;
            free(del);
        }
    }

int main(){




    return 0;
}