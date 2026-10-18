/*
perbedaan c & c->next :
c = traversal sampai tail 
c->next = traversal sampai node sebelum tail


10 30 50 70 90 100
                c

10 30 50 70 90       100
           c->next
*/


void searchSong(char target[]){
    
    node *c = head;
    int flag = 0, no = 0;
   

    while(c != NULL){
        if (strcmp(c->song,target) == 0){
            printf("%d. %s-%s\n",no+1,c->song,c->singer);
            flag = 1;
        }
        c= c->next;
        no++;
    }

    if (flag == 0){
        printf("Song \"%s\" not found\n",target);
    }
}