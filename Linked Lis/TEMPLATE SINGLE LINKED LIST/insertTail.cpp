    void insertTail(char *name){
        node *newNode = createNode(name);

        if (head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }