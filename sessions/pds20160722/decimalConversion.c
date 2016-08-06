/*-------------------------------------------------------
Name : Yash M Sawant
Roll : MTC-1614
Date : 26th July, 2016
Desc : Octal to Hexadecimal or Vice-Versa
Acks : 
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	float value = 0.0f;
	if(argc != 2) {
		printf("Usage : <o|O|x|X><numeric_value>");
		exit(-1);
	} else {
		len = strlen(argv[1]) - 1;
		
		for(i = 0 ; i < len ; i++) {		
			if(argv[1][0] == 'O' || argv[1][0] == 'o') {
				switch(argv[1][i + 1]) {
				case '0': break;
				case '1':				
				case '2': if(floatStarted == FALSE) {
					  	value = value + 2 * power(8, len - i);	
					  } else {
					  	value = value + 2 / apower(8, len - i);
					  }
					  break;
				case '3': if(floatStarted == FALSE) {
					  	value = value + 3 * power(8, len - i);
					  } else {
					  	value = value + 3 / apower(8, len - i);
					  }
					  break;
				case '4': if(floatStarted == FALSE) {	
					  	value = value + 4 * power(8, len - i);
					  } else {
					  	value = value + 4 / apower(8, len - i);
					  }
					  break;
				case '5': if(floatStarted == FALSE) {
				          	value = value + 5 * power(8, len - i);
					  } else {
					  	value = value + 5 / apower(8, len - i);
					  }
					  break;
				case '6': if(floatStarted == FALSE) {
					  	value = value + 6 * power(8, len - i);
					  } else {
					  	value = value + 6 / power(8, len - i);
					  }
				          break;
				case '7': if(floatStarted == FALSE) {
					  	value = value + 7 * power(8, len - i);
					  } else {
					  	value = value + 7 / power(8, len - i);
					  }
					  break;
				case '.': floatStarted = TRUE;
					  break;
				default : printf("Wrong Input : Code 40\n");
					  exit(40);
				
										
				}								
			} else if(argv[1][0] == 'X' || argv[1][0] == 'x') {
				switch(argv[1][i + 1]) {
				case '0': 
				case '1': if(floatStarted == TRUE) {
					  }
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				case 'A':
				case 'a':
				case 'B':
				case 'b':
				case 'C':
				case 'c':
				case 'D':
				case 'd':
				case 'E':
				case 'e':
				case '.':
				default :
				}
			}
		}
	}
}
