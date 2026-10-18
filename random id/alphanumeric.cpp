#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void randId(char temp[]){
	char alphaNum[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	int size = sizeof(alphaNum) - 1;
	
	for (int i = 0; i < 6; i++){
		int index = rand()%size;
		
		temp[i] = alphaNum[index];
	}
	
	temp[6] = '\0';
}

int main(){
	srand(time(NULL));
	
	char id[7];
	
	randId(id);
	
	printf("%s",id);
	
	
	
	return 0;
}
