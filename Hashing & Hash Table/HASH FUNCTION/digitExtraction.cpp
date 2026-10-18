#include <stdio.h>
#define SIZE 100

int digitExtraction(int key, int pos[], int len){
    char temp[100];

    sprintf(temp,"%d",key); // convert key to string

    int extractedValue = 0;


    for(int i = 0; i < len; i++){
        extractedValue = extractedValue * 10 + (temp[pos[i] - 1] - '0');
        /*                                     pos = 1 == temp[0]        
          awal : 0
          ambil 1 : 0 * 10 + 1
          ambil 3 : 1 * 10 + 3
          ambil 5 : 13 * 10 + 5
          */
    }


    return extractedValue % SIZE;
}

int main (){

    int key = 312156;

    int temp[] = {1, 3, 5};

    int len = sizeof(temp) / sizeof(temp[0]);

    int hasil = digitExtraction(key, temp, len);


    printf("%d", hasil);






    return 0;
}