#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char name[100];
    int grade;
    struct node *parent;
    int rank;
}node;

    node *makeSet(char *name, int grade){
        node *newSet = (node*)malloc(sizeof(node));
        strcpy(newSet->name, name);
        newSet->grade = grade;
        newSet->rank = 0;
        newSet->parent = newSet;

        return newSet;
    }

    node *findSet(node *set){
        if (set == set->parent) return set;

        return set->parent = findSet(set->parent);
    }

    node *swap(node **a, node **b){
        node *temp = *a;
        *a = *b;
        *b = temp;
    }

    void unionSet(node *a, node *b){
        node *rootA = findSet(a);
        node *rootB = findSet(b);

        if (rootA != rootB){
            if (rootA->rank < rootB->rank){
                swap(&a,&b);
            }
            rootB->parent = rootA;

            if (rootA->rank == rootB->rank){
                rootA->rank++;
            }
        }
    }
int main(){
    node *set[100];

    set[0] = makeSet("Nino",100);
    set[1] = makeSet("Otong",70);
    set[2] = makeSet("Ucup Surucup",50);

    unionSet(set[0],set[1]);
    node *root = findSet(set[1]);

    printf("%s %d",root->name, root->grade);





    return 0;
}