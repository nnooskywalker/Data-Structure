#include <stdio.h>
#include <stdlib.h>

node *closest(node *root, int temp){
    if (root == NULL) return NULL;

    node *curr = root;
    node *close = root;

    while(curr != NULL){
        int currTemp = abs(temp - curr->idx);
        int closeTemp = abs(temp - close->idx)

        if (currTemp < closeTemp || (currTemp == closeTemp && curr->idx < close->idx)){
            close = curr;
        }
        else if (temp < curr->idx){
            curr = curr->left;
        }
        else if (temp > curr->idx){
            curr = curr->right;
        }
        else{
            break;
        }
    }
}

int main(){





    return 0;
}