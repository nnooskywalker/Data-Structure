#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct mhs{
    int key;
    char nim[5];
    char nama[15];
    int height;
    struct mhs *left;
    struct mhs *right;
};

    struct mhs *createNode(int key, char *nim, char *nama){
        struct mhs *newNode = (struct mhs*)malloc(sizeof(struct mhs));

        newNode->height = 1;
        newNode->key = key;
        strcpy(newNode->nim, nim);
        strcpy(newNode->nama, nama);
        newNode->left = newNode->right = NULL;

        return newNode;
    }
// getHeight -> supaya bisa get height tanpa error buat node null
    int getHeight(struct mhs *node){
        if (!node){
            return 0;
        }
        return node->height;
    }
// udpateHeight -> ngubah height
    void updateHeight(struct mhs *node){
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        node->height =  1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
    }
// getBalance -> menghitung balance suatu node
    int getBalance(struct mhs *node){
        if (!node){
            return 0;
        }

        return getHeight(node->left) - getHeight(node->right);
    }


    struct mhs *rotateRight(struct mhs *root){
        struct mhs *newRoot = root->left;
        struct mhs *orp = newRoot->right;
        
        newRoot->right = root;
        root->left = orp;
        
        //update height
        updateHeight(root);
        updateHeight(newRoot);
        
        return newRoot;
    }
    
    struct mhs *rotateLeft(struct mhs *root){
        struct mhs *newRoot = root->right;
        struct mhs *orp = newRoot->left;
        
        newRoot->left = root;
        root->right = orp;
        
        //update height
        updateHeight(root);
        updateHeight(newRoot);
        
        return newRoot;
    }

    struct node *rebalance(struct mhs *node){
         if (node == NULL) return NULL;

         int nodeBalance = getBalance(node);
         int leftBalance = getBalance(node->left);
        int rightBalance = getBalance(node->right);

        if (nodeBalance > 1 && leftBalance >= 0){
            node = rotateRight(node);
        }
        else if (nodeBalance > 1 && leftBalance < 0){
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
        }
        else if(nodeBalance < -1 && rightBalance <= 0){
            node = rotateLeft(node);
        }
        else if (nodeBalance < -1 && rightBalance > 0){
            node->ri
        }
        else if (nodeBalance < -1 && rightBalance > 0){
            node->right = rotateRight(node->right);
            node = rotateLeft(node);
        }
    }

    struct mhs *insertNode (struct mhs *root, int key, char *nama, char *nim){
        if (!root){
            return createNode(key, nim, nama);
        }
        if (root->key > key){
            root->left = insertNode(root->left, key, nama, nim);
        }
        else if (root->key < key){
            root->right = insertNode(root->right, key, nama, nim);            
        }
        else{
            printf("Data Duplikat !");
        }

        updateHeight(root);
        return rebalance(root);
    }

    struct mhs *findNode(struct mhs *root, int key){
        if (!root){
            return NULL;
        }
        if (root->key > key){
            return findNode(root->left, key);
        }
        else if (root->key < key){
            return findNode(root->right, key);
        }
        else{
            printf("Data ketemu !!\n");
            return root;
        }
    }


    void printOrder(struct mhs *node){
        if (!node){
            return;
        }

        printOrder(node->left){
        printf("(%d) - %s - %s\n", node->key, node->nim, node->nama);
        printintOrder(node->right)
        }
    }

    struct mhs *findSuccessor(struct mhs *node){
        while(node->left){
            node = node->left;
        }
        return node;
    }

    struct mhs *deleteData(struct mhs *node, int key){
        if (!node){
            return null;
        }
        if (node->key > key){
            node->left = deleteData(node->left, key);
        }
        else if (node->key < key){
            node->right = deleteData(node->right, key);
        }
        else{
            //tidak ada child
            struct mhs *temp = node;
            if (!node->left && !node->right){
                free(temp);
                node = NULL;
            }
            else if (node->left && !node->right){
                temp = node->left;
                free(node);
            }
            else if (node->right && !node->left){
                temp = node->right;
                free(node);
            }
            else{
                struct mhs *sucessor = findSuccessor(node->right);
                node->key = sucessor->key;
                strcpy(node->nama, nama);
                strcpy(node->nim, nim);
                node->right = deleteData(node->right, sucessor->key);
            }
        }

        return rebalance(temp);
    }

    //Pop All
    struct mhs *popAll(struct mhs *root){
        while(root){
            root = deleteData(root, root->key);
        }

        return root;
    }
//    Rotate :
//   1. left left
//    2. left right
//   3. right right
//    4. right left






int main(){
    struct mhs *root = NULL;
    root = insertNode(root, 3, "Lius", "1662");
    root = insertNode(root, 6, "Gaexcel", "1231");
    root = insertNode(root, 7, "Zeordy", "5551");
    root = insertNode(root, 8, "Ziggy", "3231");
    root = insertNode(root, 9, "Arnol", "8231");

    printOrder(root);
    printf("============================\n");

    struct mhs *find = findNode()



    return 0;
}