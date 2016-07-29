/*---------------------------------------------------
Name : Yash M Sawant
Roll : MTC-1614
Date : 26th July, 2016
Desc : Matrix Multiplication
Acks : 
---------------------------------------------------*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define COLUMNMAX 50
#define ROWMAX 10

int main(int argc, char* argv[]) {
	int** matrix1;
	int** matrix2;
	int** product;
	int* row;
	int negative;
	int num = 0;
	int len = 0;
	int m1 = 0;
	int n1 = 0;
	int m2 = 0;
	int n2 = 0;
	int i = 0;
	int k = 0;
	int j = 0;
	int matrix1Read = FALSE;
	int numberBuffer[COLUMNMAX];
	int *matrixBuffer[ROWMAX];
	int productElementK;	
	if(argc == 2) {
		if(strlen(argv[1]) == 2 && (argv[1][0] == '-' && argv[1][1] == 'h')) {
			printf("Usage : [ [ num0 num1 ...] ... [ numi ... ] ] [ [ num0 num1 ...] ... [ numj ... ] ]\n");	
		}
	} else {
		
		for(i = 1 ; i < argc ; i ++) {
			negative = FALSE; // Considering only positive numbers here
			num = (char)(argv[i][0]) - '0';
			if(num >= 0 && num <= 9) {
				len = strlen(argv[i]);
				for(i = 1 ; i < len ; i++) {
					k = (char)(argv[i][0]) - '0';
					if(k >= 0 && k <= 9) {
						num = num * 10 + k;					
					} else {
						printf("Wrong Input : 					
					}				
				}
				k = k + 1;
				if(negative == TRUE) {
					numberBuffer[i - 1] = num * -1;				
				} else {
					numberBuffer[i - 1] = num;				
				}			
			} else if(num == -3) {
				negative = TRUE;
				continue;			
			} else if(argv[i][0] == '[' && strlen(argv[i]) == 1) {
				continue;			
			} else if(argv[i][0] == ']' && strlen(argv[i]) == 1) {
				continue;			
			} else {
				printf("Wrong Input : Code 30\n");
				exit(30);			
			}

			if((argv[i + 1][0] == ']' && argv[i + 2][0] == ']') && matrix1Read == FALSE) {
				if(strlen(argv[i + 1]) != 1 || strlen(argv[i + 2]) != 1) {
					printf("Something Err : Point Format Suffix Code 31\n");
					exit(31);				
				}				
				matrix1Read = TRUE;
				matrix1 = (int **)(malloc(sizeof(int *) * n1));
				for(i = 0 ; i < n1 ; i ++) {
					matrix1[i] = matrixBuffer[i];				
				}
			} else if(argv[i + 1][0] == ']' && argv[i + 2][0] == ']') {
				if(strlen(argv[i + 1]) != 1 || strlen(argv[i + 2]) != 1) {
					printf("Something Err : Point Format Suffix Code 31\n");
					exit(31);				
				}				
				matrix2 = (int **)(malloc(sizeof(int *) * n2));
				for(i = 0 ; i < n2 ; i ++) {
					matrix2[i] = matrixBuffer[i];				
				}
				break;
			}
			if(matrix1Read == FALSE) {
				if(argv[i + 1][0] == ']' && strlen(argv[i + 1]) == 1) {
					row = (int *)(malloc(sizeof(int) * k));
					if(m1 != 0 && k == m1) {
						
						for(i = 0 ; i < k ; i ++) {
							row[i] = numberBuffer[i];
						}
						n1 = n1 + 1;				
					} else if(m1 == 0) {
						m1 = k;
						for(i = 0 ; i < k ; i ++) {
							row[i] = numberBuffer[i];
						}
						n1 = n1 + 1;
					} else {
						printf("Sorry Something Err : Point Dimension 	Mismatch\n");					
						exit(30);
					}
					matrixBuffer[n1] = row;
									
				} else if(argv[i + 1][0] == ']') {
					printf("Something Err : Point Suffix Format Code 31\n");
					exit(31);				
				}
							
			} else {
				if(argv[i + 1][0] == ']' && strlen(argv[i + 1]) == 1) {
					row = (int *)(malloc(sizeof(int) * k));
					if(m2 != 0 && k == m2) {
						for(i = 0 ; i < k ; i ++) {
							row[i] = numberBuffer[i];						
						}
						n2 = n2 + 1;					
					} else if(m2 == 0) {
						m2 = k;
						for(i = 0 ; i < k ; i ++) {
							row[i] =  numberBuffer[i];			
						}
						n2 = n2 + 1;					
					} else {
						printf("Sorry Sommethin Err : Point Dimension Mismatch\n");
						exit(30);					
					}
					matrixBuffer[n2] = row;				
				} else if(argv[i + 1][0] == ']') {
					printf("Something Err : Point Suffix Format Code 31\n");
					exit(31);				
				}			
			}							
		}
		product = (int**)(malloc(sizeof(int *) * n1));
		
		if(m1 == n2) {
			for(i = 0 ; i < n1 ; i++) {
				row = (int *)(malloc(sizeof(int) * m2));
				for(j = 0 ; j < m2 ; j++) {
					productElementK = 0;
					for(k = 0 ; k < m1 ; k ++) {
						productElementK = productElementK + matrix1[i][k] * matrix2[k][j]; 					
					}
					row[j] = productElementK;
									
				}
				product[i] = row;				
			}
		} 
	}
	return 0;
}
