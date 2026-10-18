void insertPrio(int num){
    node *newNode = createNode(num);


    if (head == NULL || num < head->num){
        newNode->next = head;
        head = newNode;
        return;
    }

    node *curr = head;


    while(curr->next != NULL && curr->next->num <= num){
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;



}