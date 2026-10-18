void deleteHead(){
    if (head == NULL){
        printf("List Kosong");
        return;
    }
    else{
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}