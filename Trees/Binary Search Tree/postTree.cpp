// Postfix tree

/*
    kalau ketemu operand -->push ke stack
    kalau ketemu operator --> pop(), jadikan anak kanan & kiri & push ke stack
*/

node *postTree(char postFix[]){
    struct node *stack[100];
    int top = -1;
    int i = 0;

    while(postFix[i] != '\0'){
        int ch = postFix[i];

        if(ch >= 'A' && ch <= 'Z'){
            node *newNode = createNode(ch);
            stack[++top] = newNode;
        }
        else{
            if (top < 1) return NULL;
            node *newNode = createNode(ch);
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
        i++;
    }
    if (top != 0) return NULL; // expression tidak valid
    return stack[top];
}