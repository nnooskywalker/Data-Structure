#include <stdio.h>
#include <string.h>
#define SIZE 100

int midSquare(int key){
    long long int temp = key*key;
    char str[20];
    sprintf(str,"%lld",temp);
    int len = strlen(temp);
    int mid = len / 2;
    int result = 0;

    if (len % 2 == 0){
        result = (str[mid-1] - '0')*10 + (str[mid] - '0');
    }
    else{
        result = (str[mid-1] - '0')*100 + (str[mid] - '0')*10 + (str[mid+1] - '0');
    }


    return result % SIZE;
}

int folding(int key){
    int index = 0;

    while(key > 0){
        index += key % 100;


        key /= 100;
    }

    return index % key;
}

int digitExtraction(int temp[], int key, int len){
    char save[100];

    sprintf(save, "%d", key);
    int index = 0;

    for(int i = 0; i < len; i++){
        index = index*10 + (save[temp[i]-1]-'0');
    }


    return index % SIZE;

}


int rotatingHash(int key){
    int right = 0, index = 0;

    while(key > 0){
        right = key % 10;

        index *= 10 + right;
        key/= 10;
    }

    return index % SIZE;
}

int main(){
   



    return 0;
}