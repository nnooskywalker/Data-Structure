void display(int key){
    for(int i = 0; i < SIZE; i++){

        printf("Index ke - %d\n"); //display index
        node *curr = hashMap[i];


        //display value dari index
        if (curr == NULL){
            printf("Data Kosong\n");
        }
        else{
            while(curr != NULL){
                printf("%d",curr->data);
                curr = curr->next;
            }
        }
        printf("\n");
    }
}