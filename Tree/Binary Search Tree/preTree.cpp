// prefix tree

node *preTree(char prefix[]){
    struct node *stack[100];
    int top = -1;
    int i = strlen(prefix) - 1;

    while(i >= 0){
        int ch = prefix[i];

        if(ch >= 'A' && ch <= 'Z'){
            node *newNode = createNode(ch);
            stack[++top] = newNode;
        }
        else{
            if (top < 1) return;
            node *newNode = createNode(ch);
            newNode->left = stack[top--];
            newNode->right = stack[top--];

            stack[++top] = newNode;
        }
        i--;
    }
    if(top != 0) return NULL;

    return stack[top];
}