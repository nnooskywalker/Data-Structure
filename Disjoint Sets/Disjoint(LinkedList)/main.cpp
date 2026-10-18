#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char name[100];
    int power;
    struct node *parent;
    int rank;
}node;

    node *makeSet(int power, char *name){
        node *newSet = (node*)malloc(sizeof(node));
        newSet->power = power;
        strcpy(newSet->name, name);
        newSet->rank = 0;
        newSet->parent = newSet;

        return newSet;
    }

    node *findSet(node *set){
        if (set == set->parent) return set;

        return set->parent = findSet(set->parent);
    }


    void swap(node **a, node **b){
        node *temp = *a;
        *a = *b;
        *b = temp;
    }

    void unionRank(node *a, node *b){
        node *rootA = findSet(a);
        node *rootB = findSet(b);

        if (rootA != rootB){
            if (rootA->rank < rootB->rank){
                swap(&rootA, &rootB);
            }
            rootB->parent = rootA;

            if (rootA->rank == rootB->rank){
                rootA->rank++;
            }
        }
    }
int main(){




    return 0;
}