#include <stdio.h>
#define MAX_SIZE 100

int folding(long key){
    int sum = 0;

    while(key > 0){
        sum += key % 1000; // ambil 3 digit

        key/= 1000; // iterasi 
    }


    return sum % MAX_SIZE;
}

int main (){
    int hasil = folding(11763);
    printf("%d",hasil);



    return 0;
}