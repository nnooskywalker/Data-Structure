void search(node *root, int data){
    if (root == NULL){
        printf("Data Not Found\n");
    }
    else if (data < root->data){
        search(root->left, data);
    }
    else if(data > root->data){
        search(root->right, data);
    }
    else{
        printf("Data Was Found\n");
    }
}