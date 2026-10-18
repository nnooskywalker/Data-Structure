node *largestLeft(node *root){
    while(root->right != NULL){
        root = root->right;
    }

    return root;
}

node *deleteNode(node *root, int data){
    if (root == NULL){
        return root;
    }
    else if (data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else{
        if (root->right == NULL && root->left == NULL){
            free(root);
            return NULL;
        }
        else if (root->left == NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            node *temp = root->left;
            free(root);
            return temp;
        }
        else{
            node *temp = largestLeft(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
    }
    if (root == NULL) return root;

    root->height = 1 + max(height(root->left),height(root->right));
    int balance = getBalance(root);

    // ll
    if (balance > 1 && getBalance(root->left) >= 0){
        return rightRotate(root);
    }
    // rr
    if (balance < -1 && getBalance(root->right) <= 0){
        return leftRotate(root);
    }
    // lr
    if (balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // rl
    if (balance < -1 && data < getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;



}