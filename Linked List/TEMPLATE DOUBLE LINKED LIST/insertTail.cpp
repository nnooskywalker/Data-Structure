void insertTail(int num){
    node *newNode = createNode(num);
    
    if (head == NULL){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}