void insertMid(int data, int pos){
    node *newNode = createNode(data);

    if (pos < 0){
        printf("Invalid\n");
        return;
    }
    
    if (pos == 1){
        insertHead();
        return;
    }

    node *curr = head;
    int count = 1;

    while(count < pos -1 && curr != NULL){
        curr = curr->next;
        count++;
    }

    if (curr == NULL){
        printf("Posisi tidak valid\n");
        return;
    }

    if (curr->next == NULL){
        curr->next = newNode;
        newNode->prev = curr;
        return;
    }

    newNode->next = curr->next;
    curr->next->prev = newNode;
    curr->next = newNode;
    newNode->prev = curr;

}