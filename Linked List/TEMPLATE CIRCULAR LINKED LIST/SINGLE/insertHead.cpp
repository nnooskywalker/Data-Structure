    void insertHead(int num){
        node *newNode = createNode(num);
        if (head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
        } 
    }