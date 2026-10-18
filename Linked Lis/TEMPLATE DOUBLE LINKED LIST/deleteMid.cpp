void deleteMid(int target){
    if (head == NULL){
        printf("List Kosong\n");
        return;
    }

    if (head->num == target){
        deleteHead();
        return;
    }

    if(tail->num == target){
        deleteTail();
        return;
    }

    node *curr = head;

    while(curr != NULL && curr->num != target){
        curr = curr->next;
    }

    if (curr == NULL){
        printf("Not Found\n");
        return;
    }

    node *sNext = curr->next;
    node *sPrev = curr->prev;

    sPrev->next = sNext;
    sNext->prev = sPrev;
    free(curr);



}