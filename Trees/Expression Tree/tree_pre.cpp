node *tree(char prefix[]){
    struct node *stack[100];
    int top = -1;
    int i = strlen(prefix) - 1;
    
    while(i >= 0){
        char ch = prefix[i];

        if (ch >='A' && ch <= 'Z'){
            node *newNode = create(ch);
            stack[++top] = newNode;
        }
        else{
            node *newNode = create(ch);
            newNode->left = stack[top--];
            newNode->right = stack[top--];
            stack[++top] = newNode;
        }
        i--;
    }

    return stack[top];
}