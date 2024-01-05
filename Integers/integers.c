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
#include <stdlib.h>
#define UNSIGNED_MAX_POWER_OF_TWO 0x80000000


// FILL IN THE BODY OF THIS FUNCTION.
// Feel free to create any other functions you like; just include them in this file.
void repr_convert(char source_repr, char target_repr, unsigned int repr){
    // Checks if input and output types are valid
    if ((source_repr != 'S' && source_repr != '2') || (target_repr != 'S' && target_repr != '2'))
        printf("error\n"); 
    // If input and output representation are equal or number is positive
    // No conversion necessary in those cases, so original number is returned
    else if (source_repr == target_repr || repr < UNSIGNED_MAX_POWER_OF_TWO)
        printf("%c: %08x\n", source_repr == 'S' ? '2' : 'S', repr);
    // Checks if number is impossible to convert (This assumes the value for -0 in sign-mag can be represented as 0 in 2's comp)
    else if (repr == UNSIGNED_MAX_POWER_OF_TWO && source_repr == '2')
        printf("undefined\n");
    // When converting from sign-mag to 2's comp, it first negates the sign to get the magnitude (since it must be negative),
    // Then reverses the number to get 1's comp and adds 1 to get final result. the logic gates were simplified
    else if (source_repr == 'S')
        printf("2: %08x\n", (~repr | UNSIGNED_MAX_POWER_OF_TWO) + 1);
    // When converting from 2's comp to sign-mag, it first subtracts 1 to get 1's comp, then negates that to get the magnitude
    // And finally adds the negative sign (since it must be negative)
    else
        printf("S: %08x\n", ~(--repr) | UNSIGNED_MAX_POWER_OF_TWO);
}


// DO NOT CHANGE ANY CODE BELOW THIS LINE
int main(int argc, char *argv[]){
    (void) argc; // Suppress compiler warning
    (void) argv;
    repr_convert(argv[1][0], argv[2][0], (int)strtol(argv[3], NULL, 16));
    return 0;
}
