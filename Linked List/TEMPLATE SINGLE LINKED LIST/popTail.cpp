void popTail(){
    if (tail == NULL){
        printf("List Kosong");
        return;
    }
    if (head == tail){
        free(head);
        head = tail = NULL;
        return;
    }

    node *c = head;

    while(c->next != NULL){
        c = c->next;
    }
    free(tail);
    tail = c;
    tail->next = NULL;
}