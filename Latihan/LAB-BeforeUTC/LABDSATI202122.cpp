#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define gc getchar()
#define SIZE 10
int convertToKey(char *id){
	int len = strlen(id);
	int sumAlpha = 0, sumNum = 0;
	int k = 1, l = 1;
	
	for(int i = 0; i < len; i++){
		if (id[i] >= 'A' && id[i] <= 'Z'){
			sumAlpha = (id[i] - 'A')*k;
			k++;
		}
		else{
			sumNum = (id[i] - '0')*l;
			l++;
		}
	}
	
	return sumAlpha + sumNum;
}



int hashFunction(int key){
	return key % SIZE;
}



typedef struct node{
	char type[100];
	char destination[100];
	int prio;
	int travelTime;
	char id[6];
	int key;
	struct node *next;
}node;

node *hashTable[SIZE];

void setTable(){
	for(int i = 0; i < SIZE; i++){
		hashTable[i] = NULL;
	}
}

int count = 0;
node *createData(char *type, char *destination, char *id,  int prio, int travelTime, int key){
	node *newNode = (node*)malloc(sizeof(node));
	strcpy(newNode->type, type);
	strcpy(newNode->destination, destination);
	strcpy(newNode->id, id);
	newNode->prio = prio;
	newNode->travelTime = travelTime;
	newNode->key = key;
	newNode->next = NULL;
	
	return newNode;
}

void insertData(char *type, char *destination, char *id, int prio, int travelTime, int key){
	node *newNode = createData(type, destination,id, prio, travelTime, key);
	int index = hashFunction(key);
	node *curr = hashTable[index];
	
	if (hashTable[index] == NULL){
		hashTable[index] = newNode;
		count++;
	}
	else{
		while(curr->next != NULL){
			curr = curr->next;
		}
		
		curr->next = newNode;
		
	
		count++;		
		}
	}
	


void display(){
	
	if (count == 0){
		puts("No data available.");
	}
	else{
	for(int i = 0; i < SIZE; i++){
		node *curr = hashTable[i];
		if (curr != NULL){
			while(curr != NULL){
				printf("ID : %s\n",curr->id);
				printf("Destination Code : %s\n",curr->destination);
				printf("Type : %s\n",curr->type);
				printf("Priority Level : %d\n",curr->prio);
				printf("Travel Time : %d\n\n",curr->travelTime);
				curr= curr->next;
			}
		}
	}	
	}
}

bool remove (int key){
	int index = hashFunction(key);
	
	node *curr = hashTable[index];
	node *prev = NULL;
	
	while(curr != NULL){
		if (curr->key == key){
			if (prev == NULL){
				hashTable[index] = curr->next;
			}
			else{
				prev->next = curr->next;
			}
			free(curr);
			return true;
		}
		prev = curr;
		curr = curr->next;
	}
	
	
	return false;
	
}

void generateID(char *id){
	for(int i = 0; i < 2; i++){
		id[i] = 'A' + rand()%26;
	}
	
	for(int i = 2; i < 5; i++){
		id[i] = '0' + rand()%10;
	}
	
	id[5] = '\0';
}





void menu(){
	srand(time(NULL));
	setTable();
	int choose = 0, prioLevel = 0, travelTime = 0, key = 0;
	char aircraftType[100], destinationCode[100], id[6];
	char inputId[100];
	char yayNay;
	bool flag = false;
	
	while(choose != 4){
		cp1:
		puts("Aircravd Manager");
		puts("1. Insert Aircraft");
		puts("2. View Aircraft");
		puts("3. Delete Aircraft");
		puts("4. Exit Aircraft");
		printf(">> ");
		scanf("%d",&choose); gc;
		
		switch(choose){
			case 1:
				do{
					printf("Enter the Aircraft type [Cargo | Passenger]: ");
					scanf("%s",aircraftType);
					
					if (strcmp(aircraftType, "Cargo") != 0 && strcmp(aircraftType, "Passenger") != 0){
						printf("Invalid Aircraft Type. Please try again.\n");
					}
					else{
						break;
					}
				}while(true);
				
				do{
					printf("Enter the destination code ['LAX', 'CDG', 'JFK']: ");
					scanf("%s",destinationCode);
					
					if (strcmp(destinationCode,"LAX") != 0 && strcmp(destinationCode, "CDG") != 0 && strcmp(destinationCode, "JFK") != 0){
						printf("Invalid Destination Code. Please try again.\n");						
					}
					else{
						break;
					}
				}while(true);
				
				do{
					printf("Enter the priority level [1-3] : ");
					scanf("%d",&prioLevel);
					
					if (prioLevel < 1 || prioLevel > 3){
						printf("Invalid Priority Level. Please try again.\n");						
					}
					else{
						break;
					}
				}while(true);
				
				while(1){
					printf("Enter the travel time [number] : ");
					
					if (scanf("%d",&travelTime) == 1){
						while(getchar() != '\n');
						break;
					}
					else{
						printf("Travel Time must be in integer\n");
						while(getchar() != '\n');
					}			
				}
				
				printf("Are You Sure ? [Y/N]: ");
				scanf("%c",&yayNay);
				
				if (yayNay == 'Y'){
					generateID(id);
					key = convertToKey(id);
					insertData(aircraftType, destinationCode, id, prioLevel, travelTime, key);
					
					printf("Aircraft has been inserted\n");
					printf("Please enter to continue.....\n");
				}
				else{
					goto cp1;
				}
				break;
			case 2:
				display();
				break;
			case 3:
				display();
	
				while(true){
				printf("Enter the Aircraft ID [0 to cancel]: ");
				scanf("%s", inputId);
				int len = strlen(inputId);
				
				if (strcmp(inputId,"0") == 0){
					break;
				}
				else if (len != 5){
					printf("Invalid Aircraft ID. Please ensure it is 5 characters long.\n");
					printf("Press Enter to continue....");
				}
				else{
					key = convertToKey(inputId);
					
					bool isValid = remove(key);
					
					if (isValid == true){
						flag = true;
						break;
					}
					else{
						printf("Invalid Aircraft ID. Please Try Again.\n");
						printf("Press Enter to continue....\n");
					}
				}
					
				}
				
				if (flag == true){
				printf("Aircraft has been deleted\n");
				printf("Press Enter to continue....");					
				}
				else{
					goto cp1;
				}
				
				break;
			case 4:
				printf("Exiting...\n");
				break;
			default :
				printf("Invalid\n");
				break;
		}
	}
	
	
	
}

int main(){
	menu();
	
	
	
	
	return 0;
}

