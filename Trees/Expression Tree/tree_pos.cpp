node *tree(char postfix[]){
    struct node *stack [100];
    int top = -1;
    int i = 0;

    while(postfix[i] != '\0'){
        char ch = postfix[i];

        if (ch >= 'A' && ch <= 'Z'){
            node *newNode = create(ch);
            stack[++top] = newNode;
        }
        else{
            node *newNode = create(ch);
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
        i++;
    }
    return stack[top];
}
