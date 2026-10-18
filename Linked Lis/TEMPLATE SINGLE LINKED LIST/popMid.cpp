// delete by value
    void popMid(int num){
        if (head == NULL){
            printf("List Kosong\n");
            return;
        }

        if (head->data == num){
            popHead();
            return;
        }

        if(tail->data == num){
            popTail();
            return;
        }

        node *c = head;

        while(c->next != NULL && c->next->data != num){
            c = c->next;
        }

        if (c->next == NULL){
            printf("Tidak ditemukan\n");
            return;
        }

        node *del = c->next;
        c->next = del->next;

        if (del == tail){
            tail = c;
        }

        free(del);

    }

    void show(){
        node *c = head;

        while(c != NULL){
            printf("%d -> ",c->data);
            c = c->next;
        }
    }

//delete by position
    void popMid(int pos){
        node *curr = head;
        int count = 1;

        while (curr != NULL && count < pos - 1){
            curr = curr->next;
            count++;
        }

        if (curr == NULL){
            printf("Empty\n");
            return;
        }

        node *del = curr->next;
        curr->next = del->next;
        free(del);
    }
