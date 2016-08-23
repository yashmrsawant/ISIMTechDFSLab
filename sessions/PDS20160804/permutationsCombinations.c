// PermutationsAndCombinations.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
* File:   main.cpp
* Author: dell
*
* Created on 8 March, 2015, 1:46 AM
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


void permute(int n, const char* prefix, const char* suffix) {
	char* newPrefix;
	char* newSuffix;
	int i = 0;
	char temp;
	int index = 0;
	int j = 0;
	if (strlen(prefix) == n) {
		fputs(prefix, stdout);
		fputs("\n", stdout);
	}
	else {
		for (i= 0; i < strlen(suffix); i++) {
			if (strlen(prefix) != 0) {
			newPrefix = (char*)(malloc(sizeof(char)* (strlen(prefix) + 1)));
				strcpy(newPrefix, prefix);strcat(newPrefix, "0");
				newPrefix[strlen(newPrefix) - 1] = suffix[i];

			} else {
		
				newPrefix = (char*)(malloc(sizeof(char)* 2));
				newPrefix[0] = suffix[i];
				newPrefix[1] = '\0';
			}
			newSuffix = (char*)(malloc(sizeof(char)* (strlen(suffix))));
			strcpy(newSuffix, suffix);
			if (strlen(suffix) > 1) {
		
				index = 0;
				j = 0;
				while (suffix[j] != '\0') {
					if (index == i) {
					index++;
					continue;
					} else {
						newSuffix[j++] = suffix[index++];
					}	
		
				}
				newSuffix[index++] = '\0';
			} else {
				strcpy(newSuffix, "");
		
			}
			permute(n, newPrefix, newSuffix);

		}
	}
}


void combinate(int n, const char* prefix, const char* suffix) {																								int i = 0;
	char* newPrefix;
	char* newSuffix;
	char* set;
	int index = 0;
	int previousNoticedCharFlag = FALSE;
	char temp;
	int newIndex;
	if (strlen(prefix) == n) {
		fputs(prefix, stdout);
		fputc('\n', stdout);
	
	} else {

		set = (char*)(malloc(sizeof(char) * (strlen(suffix) + 1)));
		set[strlen(suffix) - 1] = '\0';
		
		for (i = 0; i < strlen(suffix); i++) {
			set[i] = '\0';
		}
		for (i = 0; i < strlen(suffix); i++) {
			index = 0;
		
			while (set[index] != '\0') {
		
				if (set[index] == suffix[i]) {
					previousNoticedCharFlag = TRUE;
					break;
				}
				index++;
			}
		
			if (previousNoticedCharFlag == TRUE)
				continue;
		
			if (set[index] == '\0') {
				set[index] = suffix[i];
				strcat(set, "");

			}
			if (strlen(prefix) != 0) {
		
				newPrefix = (char*)(malloc(sizeof(char)* (strlen(prefix) + 1)));
				strcpy(newPrefix, prefix);
				strcat(newPrefix, "0");
				newPrefix[strlen(newPrefix) - 1] = suffix[i];
			} else {
		
				newPrefix = (char*)(malloc(sizeof(char)* (2)));
				strcpy(newPrefix, "0");
				newPrefix[strlen(newPrefix) - 1] = suffix[i];
			}


			if (strlen(suffix) > 1) {

				newSuffix = (char*)(malloc(sizeof(char)* strlen(suffix)));

				strcpy(newSuffix, suffix);
				index = 0;
				newIndex = 0;
				while (suffix[index] != '\0') {
					if (index == i) {
					index++;
					continue;
					}
					newSuffix[newIndex ++] = suffix[index ++];
				}

				newSuffix[newIndex] = '\0';

			} else {
				newSuffix = (char*)(malloc(sizeof(char) * 1));
				newSuffix[0] = '\0';
			}	

		combinate(n, newPrefix, newSuffix);

		}
	}
}

int main(int argc, char* argv[]) {

	if (argc != 3) {
		printf("Usage : {permute|combinate} <string_char>");
		exit(-1);

	}

	if(!strcmp("permute", argv[1])) {

		fputs("The Permutations are : \n", stdout);
		permute(strlen(argv[2]), "", argv[2]);
	} else {
		fputs("The Combinations are : \n", stdout);
		combinate(strlen(argv[2]), "", argv[2]);

	}

	return 0;
}

