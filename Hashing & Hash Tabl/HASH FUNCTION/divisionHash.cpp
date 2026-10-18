#include <stdio.h>
#define MAX_SIZE 100
int divisionHash(int key){
    return key % MAX_SIZE;
}

int main (){
    int hasil = divisionHash(3121);

    printf("%d",hasil);





    return 0;
}