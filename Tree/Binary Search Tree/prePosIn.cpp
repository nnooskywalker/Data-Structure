// pre (sebelum)
void prefix(node *root){
    if (root == NULL) return;

    printf("%c",root->data);
    prefix(root->left);
    prefix(root->right);
}

//pos (sesudah)
void postFix(node *root){
    if (root == NULL) return ;
    postFix(root->left);
    postFix(root->right);
    printf("%c",root->data);
}

//in(tengah)
int isOperator(char data){
    return data == '+' || data == '-' ||
            data == '*' || data == '/' ||
            data == '^';

    // return 1 kalau karakter nya salah satu dari ini
}


void infix(node *root){
    if (root == NULL){
        return;
    }

    if (isOperator(root->data)) putchar('(');
    infix(root->left);
    printf("%c",root->data);
    infix(root->right);
    if (isOperator(root->data)) putchar(')');
}