void insertMid(int pos, int num){
    node *newNode = createNode(num);

    if(head == NULL){
        printf("List Kosong\n");
        return;
    }
    
    if (pos < 1){
        printf("posisi tidak valid\n");
        return;
    }

    if (pos == 1){
        insertHead(num);
        return;
    }

    node *curr = head;
    int count = 1;

    do{
        curr = curr->next;
        count++;

    }while(curr != head && count < pos -1);

    if(curr == head){
        printf("Not Found\n");
        return;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    if (curr == tail){
        tail = newNode;
    }

}