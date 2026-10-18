void popHead(){
    if (head == NULL){
        printf("List Kossong");
        return;
    }

    if (head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        node *temp = head;
        head = head->next;
        free(temp);
    }
}