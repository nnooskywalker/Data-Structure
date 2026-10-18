#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int parent[MAX];
int rank[MAX];

void makeSet(int v){
    parent[v] = v;
    rank[v]= 0;
}

int findSet(int v){
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);

    if (a != b){
        if (rank[a] < rank[b]) swap(&a, &b);

        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }

}

int main(){
    makeSet(1);
    makeSet(10);
    makeSet(3);

    unionSet(1, 10);
    unionSet(10, 3);

    printf("%d\n", findSet(3));



    return 0;
}