/*---------------------------------------------------------
Name : Yash M Sawant
Roll : MTC-1614
Date : 26th July, 2016
Desc : GCD Computation
Acks : Euclid's Algorithm Implementation
---------------------------------------------------------*/

#include <stdio.h>


int gcd(int num1, int num2) {
	if(num1 == 0) {
		return num2;
	} else if(num1 == 1) {
		return 1;	
	} else {
		return gcd(num2 % num1, num1);	
	}

}
int main(int argc, char* argv[]) {
	
	int i = 0;
	int len = 0;
	int num1 = 0;
	int num2 = 0;
	if(argc != 3) {
		printf("Usage : <number1> <number2>");
		exit(-1);
	} else {
		len = strlen(argv[1]);
		for(i = 0 ; i < len ; i ++) {
			k = (char)(argv[1][i]) - '0';
			if(k >= 0 && k <= 10) {			
				num1 = num1 * 10 + k;
			} else {
				printf("Wrong Input : Code 20");			
				exit(20);			
			}		
		}
		len = strlen(argv[2]);
		for(i = 0 ; i < len ; i ++) {
			k = (char)(argv[1][i]) - '0';
			if(k >= 0 && k <= 10) {
				num2 = num2 * 10 + k;			
			} else {
				printf("Wrong Input : Code 20");
				exit(20);			
			}		
		}
		gcdValue = gcd(num1, num2);		
		printf("%d", gcdValue);	
	}
	return 0;
}
