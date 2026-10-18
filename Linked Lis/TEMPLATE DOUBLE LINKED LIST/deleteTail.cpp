void deleteTail(){
    if (tail == NULL){
        printf("List Kosong\n");
        return;
    }
    
    if (head == tail){
        head = tail = NULL;
    }
    else{
        node *del = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(del);
    }

}