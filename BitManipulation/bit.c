/*
 * Name: Luciano Adam
 * ID: 115157187
 * Class: CSE 220.01
 * Prof.: Abid M. Malik
 * Recitation: R03
 * Assignment: HW2
 * Due Date: 09/29/2023 23:59 EST
 */

#include <stdio.h>
#define SIZE_OF_INT 32

char flag = 0; // Used to detect erroneous terminal input

// Simple function to get the absolute value, used to prevent edge cases
unsigned int myAbs(int num){ return num > 0 ? num : num * (-1); }

int GetBit(int num, int pos){ return (num >> (myAbs(pos) % SIZE_OF_INT)) & 1; }

int SetBit(int num, int pos){ return num | (1 << (myAbs(pos) % SIZE_OF_INT)); }

int ClearBit(int num, int pos){ return num & ~(1 << (myAbs(pos) % SIZE_OF_INT)); }

int Reversbit(int num){ 
	char i;
	int reverse = 0;
	for(i = 0; i < SIZE_OF_INT; i++)
		reverse = (reverse << 1) | GetBit(num, i);
	return reverse;
}

int CountBit(int num){
	char count = 0;
	while (num != 0){
		count += num & 1;
		num >>= 1;
	}
	return count;
}

int PowerofTwo(unsigned int num){ return num > 0 && (num & (num - 1)) == 0; }

int RotateLeft(int num, unsigned int pos){
	pos %= SIZE_OF_INT;
	return (num << pos) | (num >> (SIZE_OF_INT - pos));
}

int RotateRight(int num, unsigned int pos){
	pos %= SIZE_OF_INT;
	return (num >> pos) | (num << (SIZE_OF_INT - pos));
}

// Simple function to convert from string to int
int myAtoi(char* num){
	int i = num[0] == '-' ? 1 : 0, newNum = 0;
	while (num[i] != '\0'){
		if (num[i] >= '0' && num[i] <= '9')
			newNum = newNum * 10 + (num[i] - '0');
		else{
			flag = 1;
			return 0;
		}
		i++;
	}
	return num[0] == '-' ? newNum * -1 : newNum;
}


int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;

	unsigned int selection = 0;
	if (argc > 2 && argc < 5) selection = myAtoi(argv[1]);
	else flag = 2;
	if (flag) goto end_program; // Line 122
	const int NUM = myAtoi(argv[2]);
	if (flag) goto end_program; // Line 122

	if (argc == 4){
		const int POS = myAtoi(argv[3]);
		if (flag) goto end_program; // Line 122
		switch (selection){
			case 1:
				printf("Bit at position %d in %d: %d\n", POS, NUM, GetBit(NUM, POS));
				break;
			case 2:
			case 3:
				 printf("%d when bit %d is %d: %d\n", NUM, POS, selection==2 ? 1 : 0, 
					selection==2 ? SetBit(NUM, POS) : ClearBit(NUM, POS));
				 break;
			case 7:
			case 8:
				{const unsigned int U_POS = myAbs(POS);
				 printf("%d rotated %s by %u: %d\n", NUM, selection==7 ? "left" : "right", U_POS,
					selection==7 ? RotateLeft(NUM, U_POS) : RotateRight(NUM, U_POS));
				 break;}
			default:
				flag = (selection > 3 && selection < 7) ? 2 : 3;
				break;
		}
	}
	else{
		switch (selection){
			case 4:
				 printf("%d with reversed binary: %d\n", NUM, Reversbit(NUM));
				 break;
			case 5:
				 printf("Number of 1s in %d: %d\n", NUM, CountBit(NUM));
				 break;
			case 6:
				{const unsigned int U_NUM = myAbs(NUM);
				 printf("Is %u a power of two? %s\n", U_NUM, PowerofTwo(U_NUM) ? "Yes" : "No");
				 break;}
			default:
				flag = 3;
				break;
		}
	}

	end_program:
	switch (flag){
		case 1:
			printf("Invalid input\n");
			return -1;
		case 2:
			printf("Invalid number of arguments\n");
			return -1;
		case 3:
			printf("Invalid selection\n");
			return -1;
		default:
			return 0;
	}
}