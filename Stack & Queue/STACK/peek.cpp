// peek = mengambil / melihat data terdepan tanpa menghapus

int peek(){
    if(head == NULL){
        printf("List is Empty");
        return -1;
    }

    return head->value;
}