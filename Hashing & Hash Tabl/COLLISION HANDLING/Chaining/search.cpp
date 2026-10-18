void searching(int key){
    int index = hashFunction(key);
    node *curr = hashMap[index];

    while(curr != NULL){
        if(curr->key == key){
            printf("%d",curr->data);
            return;
        }
        curr = curr->next;
    }
}