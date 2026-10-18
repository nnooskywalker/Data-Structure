#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char nama[100];
    int power;
    int rank;
    struct node *parent;
}node;

    node *makeSet(char *nama, int power){
        node *newSet = (node*)malloc(sizeof(node));
        strcpy(newSet->nama, nama);
        newSet->power = power;
        newSet->rank = 0;
        newSet->parent = newSet;

        return newSet;
    }

    node *findSet(node *v){
        if (v == v->parent) return v;

        return v->parent = findSet(v->parent);
    }

    void swap(node **a, node **b){
        node *temp = *a;
        *a = *b;
        *b = temp;

    }

    void unionSet(node *a, node *b){
        node *rootA = a;
        node *rootB = b;

        if (rootA != rootB){
            if (rootA->rank < rootB->rank) swap(&a, &b);
            rootB->parent = rootA;
            if (rootA->rank == rootB->rank) rootA->rank++; 
        }
    }
int main(){




    return 0;
}