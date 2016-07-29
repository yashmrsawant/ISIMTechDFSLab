/*------------------------------------------------------
Name : Yash M Sawant
Roll : MTC-1614
Date : 26th July, 2016
Desc : Temperature Conversion
Acks : 
------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

float apower(const int base, int p) {
	float result = 1.0f;
	int i = 0;
	for(; i < p ; i ++) {
		result = result / base;
	}
	return result;
}

int main(int argc, char* argv[]) {

	int i = 0;
	int len = 0;
	float num = 0.0f;
	int k = 0;
	int floatingStarted = FALSE;
	int p = 1;
	if(argc != 2) {
		printf("Usage : <numeric_value><f|c|C|F>\n");
		exit(-1);	
	} else {
		
		len = strlen(argv[1]) - 1;
		for(i = 0 ; i < len ; i ++) {
			if(argv[1][i] == '.') {
				floatingStarted = TRUE;
				continue;			
			} else {
				k = (char)(argv[1][i]) - '0';
				if(k >= 0 && k <= 9) {
					if(!floatingStarted) {
						num = num * 10.0 + k;					
					} else {
						printf("%f", k * apower(10, p));
						num = num + (float)(k) * apower(10, p);
						p++;					
					}				
				} else {
					printf("Wrong Input : Code 20");
					exit(20);				
				}
			}					
		}
		printf("%f\n", num);
	}
	
}
