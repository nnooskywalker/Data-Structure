#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#define gc getchar()
#define SIZE 10

typedef struct node{
	char nama[100];
	char major[100];
	char id[7];
	int numClass;
	int year;
	int key;
	node *next;
}node;

node *hashTable[SIZE];

void fillTable(){
	for (int i = 0; i < SIZE; i++){
		hashTable[i] = NULL;
	}
}

int sumID(char *id){
	int len = strlen(id);
	int sum = 0;
	
	for(int i = 0; i < len; i++){
		sum += id[i];
	}
	
	return sum;
}

int hashFunction(int key){
	return key % SIZE;
}


node *createNode (char *nama, char *major, char *id, int year, int numClass, int key){
	node *newNode = (node*)malloc(sizeof(node));
	
	strcpy(newNode->nama, nama);
	strcpy(newNode->major, major);
	strcpy(newNode->id, id);
	newNode->year = year;
	newNode->numClass = numClass;
	newNode->key = key;
	newNode->next = NULL;
	
	return newNode;	
}

void insertData(int key, char *nama, char *major, char *id, int year, int numClass){
	int index = hashFunction(key);
	node *newNode = createNode(nama, major, id, year, numClass, key);

	if (hashTable[index] == NULL){
		hashTable[index] = newNode;
		puts("Sucesfully Input!");
	}
	else{
		node *curr = hashTable[index];
		
		while(curr != NULL){
			curr = curr->next;
		}
		
		curr->next = newNode;
		newNode = curr;
		puts("Sucesfully Input!");
	}
}

void display(){

		for(int i = 0; i < SIZE; i++){
			node *curr = hashTable[i];
						
			if (curr != NULL){
				while(curr != NULL){
					printf("%d. Nama : %s\n",i+1, curr->nama);
					printf("    Major : %s\n",curr->major);
					printf("    Number Of Class : %d\n",curr->numClass);
					printf("    Admission Year : %d\n",curr->year);
					printf("    ID : %s\n\n",curr->id);
					curr = curr->next;
				}
			}
			else{
				printf("%d. Data Empty\n",i+1);
			}
		}
}

void deleteList(int key){
	int index = hashFunction(key);
	node *prev = NULL;
	node *curr = hashTable[index];
	
	while(curr != NULL){
		if (curr->key == key){
			if (prev == NULL){
				hashTable[index] = curr->next;
			}
			else{
				prev->next = curr->next;
			}
			free(curr);
			printf("Data with id \"%s\" sucesfully deleted\n",curr->id);
			return;
		}
		
		prev = curr;
		curr = curr->next;
	}
	
	
	printf("Data with id \"%s\" not found\n",curr->id);
	
	
}


void generateID(char *id, char *major){
	id[0] = toupper(major[0]);
	id[1] = toupper(major[1]);
	id[2] = toupper(major[2]);
	
	for(int i = 3; i < 6; i++){
		id[i] = '0' + rand()%10;
	}
	
	id[6] = '\0';
}


void menu(){
	int choose = 0;
	fillTable();
	char inputName[20];
	char inputMajor[20];
	char id[7];
	char inputID[100];
	int key = 0, len = 0;
	int numOfClass = 0, year = 0;
	
	while(choose != 4){
		puts("1. Insert Mahasiswa");
		puts("2. View Mahasiswa");
		puts("3. Delete Mahasiswa");
		puts("4. Exit");
		printf(">> ");
		scanf("%d",&choose); gc;
		
		switch(choose){
			case 1:
				do{
					printf("Name (1-15 character) : ");
					scanf(" %[^\n]",inputName);
					len = strlen(inputName);
					
				}while(len < 1 || len > 15);
				
				do{
					printf("Major (Compsci / Marketing / Architect): ");
					scanf("%s",inputMajor);
				}while(strcmp(inputMajor,"Compsci") != 0 && strcmp(inputMajor, "Marketing") != 0 && strcmp(inputMajor, "Architect") != 0);
				
				do{
					printf("Number Of Class (19 - 25): ");
					scanf("%d", &numOfClass); gc;
				}while(numOfClass <= 19 || numOfClass >= 25);
				
				do{
					printf("Admission Year (2024 - 2026) : ");
					scanf("%d",&year); gc;
				}while(year < 2024 || year > 2026);
				
				generateID(id, inputMajor);
				key = sumID(id);
				
				printf("Name : %s\n",inputName);
				printf("Major : %s\n",inputMajor);
				printf("Number Of Class : %d\n",numOfClass);
				printf("Admission Year : %d\n",year);
				printf("ID : %s\n",id);
				
				insertData(key, inputName, inputMajor, id, year, numOfClass);
				break;
			case 2:
				if (key == 0){
					printf("List is Empty!\n");
				}
				else{
					display();
				} 
				break;
			case 3:
				if (key == 0){
					printf("List is Empty!\n");
				}
				else{
					display();
					
					printf("Enter ID : ");
					scanf("%s",inputID);
					
					if (inputID == 0){
						return;
					}
					
					
					key = sumID(inputID);
					
					deleteList(key);
				}
				break;
			case 4:
				printf("Exiting....");
				break;
			default :
				printf("Invalid\n");
				break;
		}
	}
}

int main(){
	srand(time(NULL));
	menu();
	
	
	return 0;
}
