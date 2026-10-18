void insertMid(int pos,int num){
    node *newNode = creaetNode(num);

    if(pos < 0){
        printf("Invalid Position\n");
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
    }while(curr != head && count < pos - 1);

    newNode->next = curr->next;
    curr->next->prev = newNode;
    curr->next = newNode;
    newNode->prev = curr;

    if (curr == tail){
        tail = newNode;
    }

}