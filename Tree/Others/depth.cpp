// menghitung kedalaman (depth) dari setiap input
    
    node *insert(node *root, int id, int depth){
		if (root == NULL){
			printf("%d\n\n", depth);
			return createNode(id);
		}
		else if (id < root->id){
			root->left = insert(root->left, id, depth + 1);
		}
		else if (id > root->id){
			root->right = insert(root->right, id, depth + 1);
		}
		
		
		return root;
	}