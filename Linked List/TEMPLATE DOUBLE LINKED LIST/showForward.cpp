void showForward(){
    node *c = head;

    while(c != NULL){
        printf("%d -> ",c->data);
        c = c->next;
    }
    printf("NULL");
}