void showBackward(){
    node *c = tail;

    while(c != NULL){
        printf("%d -> ",c->data);
        c = c->prev;
    }

    printf("NULL");
}