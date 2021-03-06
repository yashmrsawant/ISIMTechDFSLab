/*-----------------------------------------------
Name : Yash M Sawant
Roll : MTC-1614
Date : 26th July, 2016
Desc : Fibonacci Number
Acks : Recursive Version 
-----------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int n = 0;
	int len = 0;
	int k = 0;	
	if(argc != 2) {
		printf("Usage : <numeric_value_n>\n");
		exit(-1);
	} else {
		len = strlen(argv[1]);
		for(i = 0 ; i < len ; i++) {
			k = (char)(argv[1][i]) - '0';
			if(k >= 0 && k <= 9) {
				n = n * 10 + k;			
			} else {
				printf("Wrong Input : Code 20");			
			}		
		}
		fibValue = fibonacci(n);
		printf("%d", fibValue);			
	}
	return 0;
}
int fibonacci(n) {
	if(n == 0) {	
		return 0;
	} else if(n == 1) {
		return 1;
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2);	
	}
}
