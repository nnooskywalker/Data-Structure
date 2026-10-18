    void insertHead(char *name){
        node *newNode = createNode(name);

        if (head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }