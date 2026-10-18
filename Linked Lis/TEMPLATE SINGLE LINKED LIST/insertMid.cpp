void insertMid(int data, int pos){
    node *newNode = createNode(data);
    int count = 1;

    if (pos == 1){
        insertHead();
        return;
    }

    node *curr = head;

    while(count < pos - 1 && curr != NULL){
        curr = curr->next;
        count++;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}