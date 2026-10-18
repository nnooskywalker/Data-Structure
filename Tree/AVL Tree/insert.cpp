node *insertNode(node *root, int data){
    if (root == NULL){
        return createNode(data);
    }
    if (data < root->data){
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data){
        root->right = insertNode(root->right, data);
    }
    else{
        return root;
    }

    root->height = 1 + max(height(root->left),height(root->right));
    int balance = getBalance(root);

    //LL
    if (balance > 1 && data < root->left->data){
        return rightRotate(root);
    }
    //RR
    if (balance < -1 && data > root->right->data){
        return leftRotate(root);
    }
    //LR
    if (balance > 1 && data > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //RL
    if (balance < -1 && data < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

}