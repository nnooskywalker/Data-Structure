#include <stdio.h>
#define MAX_SIZE 100

int rotatingHash(int key){
    int right = 0;
    int index = 0;

    while (key != 0){
        right = key % 10; // ambil digit paling kanan
        index = index * 10 + right;
        /*
        e.g : key = 1234
              reverse = 0
        ambil 4 -> 0*10 + 4 = 4
        ambil 3 -> 4*10 + 3 = 43
        ambil 4 -> 43*10 + 2 = 432
        ambil 4 -> 432*10 + 1 = 4321
        */
        key = key / 10;
    }

    return index % MAX_SIZE;
}

int main (){
    int key = 1234;

    int hasil = rotatingHash(key);

    printf("%d", hasil);





    return 0;
}