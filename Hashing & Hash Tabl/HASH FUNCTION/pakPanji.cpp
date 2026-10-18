#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 5


int division(int key){
    return key % TABLE_SIZE;
}


int digitExtraction(int key, int pos[], int size){
    char buffer[100];
    sprintf(buffer, "%d", key);

    int extractedValue = 0;

    for(int i = 0; i < size; i++){
        extractedValue = extractedValue * 10 + (buffer[pos[i] - 1] - '0');
    }

    return extractedValue;
}


int folding(int key){
    int sum = 0;


    while(key > 0){
        sum = sum + key % 100;
        key = key / 100;
    }


    return sum;
}
 
int midSquare(int key){
    long long int square = (long long) key * key;
    char str[20];
    sprintf(str, "%lld", square);

    int length = strlen(str);
    int mid = length / 2;


    int result;

    if (length % 2 == 0){
        result = (str[mid-1] - '0') *100 + (str[mid] - '0');
        
    }
    else{
        result = (str[mid-1] - '0') *100 + (str[mid] - '0') * 10 + (str[mid + 1] - '0');

    }



    return result;
}


int rotatingHash(int key){
    int reminder = 0;
    int reverse = 0;

    while (key != 0){
        reminder = key % 10;
        reverse = reverse * 10 + reminder;
        key = key / 10;
    }

    return reverse;
}


int main(){
    // int key = 14568;
    int key = 3121;

    //Division
    int divNum = division(key);
    printf("Division : %d\n",divNum);
    
    
    //Digit Extraction
    int pos[] = {1, 3, 5};
    int size = sizeof(pos) / sizeof(pos[0]);
    
    int digitNum = digitExtraction(key, pos, size);
    
    printf("Digit Extraction :  : %d\n",digitNum);
    
    //Folding
    int foldNum = folding(key);
    printf("Folding:  : %d\n",digitNum);


    //Mid Square
    int midNum = midSquare(key);
    printf("Mid Square : %d\n", midNum);


    // Rotating Hash
    int rotNum = rotatingHash(key);
    printf("Rotating Hash : %d\n",rotNum);
















    return 0;
}