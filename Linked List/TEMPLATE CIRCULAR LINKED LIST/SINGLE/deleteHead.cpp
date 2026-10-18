void deleteHead(){
    if (head == NULL){
        printf("List Kosong\n");
        return;
    }

    if (head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        node *temp = head;
        tail->next = head->next;
        head = head->next;
        free(temp);
    }
}