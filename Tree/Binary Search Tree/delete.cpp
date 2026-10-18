node *largestleft(node *root){
    while(root->right != NULL){
        root = root->right;
    }

    return root;
}

node *deleteNode(node *root, int key){
    if (root == NULL){
        return root;
    }

    if (key < root->key){
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key){
        root->right = deleteNode(root->right, key);
    }
    else{
        // kondisi di leaf (no child)
        if (root->right == NULL && root->left == NULL){
            free(root);
            return NULL;
        }
        // 1 child
        else if(root->left == NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }
        // 1 child
        else if(root->right == NULL){
            node *temp = root->left;
            free(root);
            return temp;
        }
        // 2 children
        node *temp = largestleft(root->left);
        root->key = temp->key; // copy data
        root->left = deleteNode(root->left, temp->key);

    }
}