int is_operator(char data){
    switch (data) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 1;
        case '/': return 1;
        case '^': return 1;
        default : return 0;
    } 
}


// InOrder Traversal
void inorder(node* root) {
    if (root == NULL) return;
    
    if(is_operator(root->item)) putchar('(');
    inorder(root->left);
    printf("%c", root->item);
    inorder(root->right);
    if(is_operator(root->item)) putchar(')');
}


// PreOrder Traversal
void preorder(node* root) {
    if (root == NULL) return;
    printf("%c", root->item);
    preorder(root->left);
    preorder(root->right);
}


// PostOrder Traversal
void postorder(node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->item);
}