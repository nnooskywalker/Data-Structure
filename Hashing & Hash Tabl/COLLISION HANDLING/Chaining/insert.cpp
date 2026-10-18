void insert(int key, int data){
    int index = hashFunction(index);
    node *newNode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newNode->next = hashMap[index];

    if(hashTable[index] == NULL){
        hashTable[index] = newNode;
    }
    else{
        node *curr = hashTable[index];

        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = newNode;
    }

}