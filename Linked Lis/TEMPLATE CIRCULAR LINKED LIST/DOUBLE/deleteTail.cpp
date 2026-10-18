void deleteTail(){
    if (head == NULL){
        printf("List Kosong\n");
        return;
    }

    if (head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        node *temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}