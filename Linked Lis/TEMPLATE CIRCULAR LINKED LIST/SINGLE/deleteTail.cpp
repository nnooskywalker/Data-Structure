void deleteTail(){
    if (head == NULL){
        printf("Empty List\n");
        return;
    }

    if (head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        node *c = head;

        while(c->next != tail){
            c = c->next;
        }

        c->next = head;
        free(tail);
        tail = c;
    }
}