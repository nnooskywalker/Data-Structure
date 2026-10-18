#include <stdio.h>
#define MAX 10

int parent[MAX];
int rank[MAX];

void makeSet(int v){
    parent[v] = v;
   
}

// make set with rank
void makeSetRank(int v){
    parent[v] = v;
    rank[v] = 0;
}

int findSet(int v){
    if (v == parent[v]) return v;
    return findSet(parent[v]);
}

// with path compression
int findSetCompression(int v){
    if (v == parent[v]) return v;
    return parent[v] = findSetCompression(parent[v]);
}

void unionSet(int a , int b){
    a = findSet(a);
    b = findSet(b);
    if (a != b) parent[b] = a;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// union with rank
void unionSetRank(int a , int b){
    a = findSet(a);
    b = findSet(b);
    if (a != b){
        if (rank[a] < rank[b]) swap(&a, &b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}


int main(){
    makeSet(0);
    makeSet(1);
    makeSet(2);
    makeSet(3);
    makeSet(4);

    unionSet(2, 3);
    unionSet(1, 2);
    printf("%d", findSet(3));


    return 0;
}