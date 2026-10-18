#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void setID(char temp[]){
	//Alphabet
	for(int i = 0; i < 2; i++){
		temp[i] = 'A' + rand()%26;
	}
	
	
	//Number
	for(int i = 2; i < 5; i++){
		temp[i] = '0' + rand()%10;
	}
	
	temp[5] = '\0';
}



int main(){
	//WAJIBBBB
	srand(time(NULL));
	
	char id[6];
	
	setID(id);
	
	printf("%s",id);
	
	
	
	return 0;
}
