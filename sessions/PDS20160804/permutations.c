/*****************************************************
Name : Yash M Sawant
Roll : MTC - 1614
Date : 3rd Aug, 2016
Desc : Permutation of a Word
0Acks : 
*****************************************************/


#include <stdio.h>


void permute(char* prefix, char* suffix) {
	int i;
	char* newPrefix;
	char* newSuffix;
	if(strlen(prefix) == strlen(suffix)) {
		
	} else {
		for(i = 0 ; i < strlen(suffix) ; i ++) {
			
			strcpy(newPrefix, prefix);
			strcat(newPrefix, "0");
			newPrefix[strlen(newPrefix) - 1] = suffix[i];

			temp = suffix[i];
			suffix[i] = '\0';
			strcpy(newSuffix, suffix);
			suffix[i] = temp;
			strcat(newSuffix, suffix + i + 1);

			permute(newPrefix, newSuffix);
		}
	}
}

int main(int argc, char* argv[]) {


}
