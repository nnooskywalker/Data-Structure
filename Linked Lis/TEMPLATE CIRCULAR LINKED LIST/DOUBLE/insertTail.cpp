void insertTail(int num){
    node *newNode = creaetNode(num);
    if (head == NULL){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        tail = newNode;
    }
}