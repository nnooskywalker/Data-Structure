#include <stdio.h>
#include <stdlib.h>

//implementation using array
/*
    left child = 2p + 1
    right child = sp + 1
    parent = (p - 1) / 2
*/

//implementation using linked list
struct node {
    int data;
    struct node *right;
    struct node *left;
    struct node *parent == NULL;
}
struct node *root = NULL;

// Type of treea
/*
    1. Perfect binary tree
    2. Complete binary tree(mengisi node paling kiri)
    3. Complete binary tree
    4. Skewed binary tree(gak punya cabang)
    5. Balanced binary tree(sisi kiri dan kanan terlihat seimbang)
*/

//prefix
char s[MAX];
// int p = 0;

// void f(struct node *curr){

// }

//DFS 
//BFS --> zig zag

int main(){




    return 0;
}