node *insertTree(node *root, char data){
    if (root == NULL){
        return createNode(data);
    }
    // anak kiri
    else if(data < root->data){
        root->left = insertTree(root->left, data);
    }
    //anak kanan
    else if(data > root->data){
        root->right = insertTree(root->right, data);
    }

    return root;
}