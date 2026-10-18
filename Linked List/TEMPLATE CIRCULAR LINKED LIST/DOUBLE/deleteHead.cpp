void deleteHead(){
    if (head == NULL){
        printf("List kosong\n");
        return;
    }
    if (head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        node *temp = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}