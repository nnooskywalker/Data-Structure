void show(){
    node *c = head;

    while(c != NULL){
        printf("%s -> ",c->name);
        c = c->next;
    }
}