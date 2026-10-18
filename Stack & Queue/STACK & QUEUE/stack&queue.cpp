#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct{
    node *top;
}stack;

typedef struct{
    node *front;
    node *rear;
}queue;

    node *createNode(int data){
        node *newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    void enqueu(queue *q, int data){
        node *newNode = createNode(data);

        if (q->front == NULL){
            q->front = q->rear = newNode;
        }
        else{
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }

    void dequeu(queue *q){
        if (q->front == NULL){
            printf("List Empty");
            return;
        }

        if (q->front == q->rear){
            free(q->front);
            q->front = q->rear = NULL;
        }
        else{
            node *temp = q->front;
            q->front = q->front->next;
            free(temp);
        }
    }

    void push(stack *S, int data){
        node *newNode = createNode(data);
        if(S->top == NULL){
            S->top = newNode;
        }
        else{
            newNode->next = S->top;
            S->top = newNode;
        }
    }

    void pop(stack *s){
        if (s->top == NULL){
            printf("Empty List");
        }
        else{
            node *temp = s->top;
            s->top = s->top->next;
            free(temp);
        }

    }

    void displayQueue (queue *q){
        node *curr = q->front;

        while(curr != NULL){
            printf("%d ",curr->data);
            curr = curr->next;
        }
    }

    void displayStack(stack *s){
        node *curr = s->top;

        while(curr != NULL){
            printf("%d ", curr->data);
            curr = curr->next;
        }
    }


    

int main(){
    stack s;
    queue q;

    s.top = NULL;
    q.front = NULL;
    q.rear = NULL;
    

    return 0;
}