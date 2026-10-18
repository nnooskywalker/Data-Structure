void delete(int key){
    int index = hashFunction(key);
    node *curr = hashMap[index];
    node *prev = NULL;

    while(curr != NULL){

        if (curr->key == key){
            if (prev == NULL){ //hapus di head
                hashMap[index] = curr->next;
            }
            else{ // hapus di tengah / akhir
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}