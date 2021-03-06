/*-----------------------------------
Name : Yash M Sawant
Roll : MTC1614
Date : 25 Jul 2016
Desc : Finding the majority element if it exists
Acks : Trivial Algorithm implementation
------------------------------------*/


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char* argv[]) {
	char* argCharactersList;
	int i = 0;		
	int l = 0;
	int found = FALSE;
	struct CharacterCount {
		char id;
		int count;
		struct CharacterCount* next;	
	};
	struct CharacterCount* first = NULL;
	struct CharacterCount* majorityNode = NULL;
	struct CharacterCount* node = NULL;
	struct CharacterCount* prevNode = NULL;
		
	if(argc == 1) {
		printf("Usage : <character0> <character1> ... <characteri>\n");
		printf("Uppercase and Lowercase are treated differently\n");
	} else {
		argCharactersList = (char *)(malloc(sizeof(char) * (argc - 1)));
		printf("Size of the Array = %d\n", (argc - 1));
		for(i = 1 ; i < argc ; i++) {
			
			l = 0;
			while(argv[i][l] != '\0') {
				argCharactersList[i - 1] = (char)(argv[i][l]);
				if(l >= 1) {
					printf("Wrong Input : Code 20\n");
					exit(20);				
				}		
				l++;				
			}
			node = first;
			found = FALSE;
			while(found == FALSE && node != NULL) {

				if(argCharactersList[i - 1] == node -> id) {
					found = TRUE;
					node -> count = node -> count + 1;
					if(node -> count >= ((argc - 1) / 2)) {
						majorityNode = node;					
					}
					break;				
				} else {
					prevNode = node;
					node = node -> next;				
				}			
			}
			if(node == NULL && found == FALSE) {
				node = (struct CharacterCount*)(malloc(sizeof(struct CharacterCount)));
				node -> id = argCharactersList[i - 1];
				node -> count = 1;
				if(prevNode == NULL) {
					first = node;				
				} else {
					
					prevNode -> next = node;			
				}
			} else if(majorityNode != NULL) {
				break;			
			}
		}
		node = first;
		while(node != NULL) {
			printf("Node\n");
			printf("Character %c\n", node -> id);
			printf("Character Count %d\n\n", node -> count);
			node = node -> next;
		}
		if(majorityNode != NULL) {
			printf("Majority Element %c\n", majorityNode -> id);		
		} else {
			printf("Majority Element Not Exists\n");
		}
		free(argCharactersList);			
	}
	return 0;
}
