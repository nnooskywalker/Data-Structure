void showList(){
    node *c = head;
    do{
        printf("%d -> ",c->num);
        c = c->next;
    } while(c != head);
}