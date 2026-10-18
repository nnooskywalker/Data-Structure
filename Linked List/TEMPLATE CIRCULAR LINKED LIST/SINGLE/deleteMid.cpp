void deleteMid(int num){
    if (head == NULL){
        printf("Empty List\n");
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

    node *c = head;

    do{
        c = c->next;
    }while(c != head && c->next->num != num);

    if (c == head){
        printf("Not Found\n");
        return;
    }

    node *del = c->next;
    c->next = del->next;
    free(del);
}