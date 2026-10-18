void deleteMid(int num){
    if (head == NULL){
        printf("List Kosong\n");
        return;
    }
    if (head->num == num){
        deleteHead();
        return;
    }
    if (tail->num == num){
        deleteTail();
        return;
    }

    node *curr = head;

    do{
        curr = curr->next;
    }while(curr != head && curr->num != num);

    if(curr == head){
        printf("Not Found\n");
        return;
    }

    node *sNext = curr->next;
    node *sPrev = curr->prev;
    sPrev->next = sNext;
    sNext->prev = sPrev;
    free(curr);
}