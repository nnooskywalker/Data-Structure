#include <stdio.h>
#include <string.h>
#define TABLE_SIZE 100
int midSquareHash(int key){
    long long int save =  key * key;

    char str[20];

    sprintf(str, "%lld", save); // convert int to String

    int len =strlen(str); // get length of String

    int mid = len / 2; // Find the middle value

    int index;

    if (len % 2 == 0){
        index = (str[mid-1] - '0')*10 + (str[mid] - '0');
        // e.g:
        // 1 2 3  4       5     6 7 8
        //       mid-1  mid
    }
    else{
        index = (str[mid-1] - '0')*100 + (str[mid] - '0')*10 + (str[mid+1] - '0');
        //e.g :
        // 2 2 8       8      8        6 6 4 1
        //     mid-1   mid    mid + 1
    }

    return index;

}

int main (){
    int hasil = midSquareHash(3214);

    printf("%d",hasil);


    return 0;
}