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
#define MAX_8_BIT_NUM 0xFF
#define MAX_23_BIT_NUM 0x7FFFFF


float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
    /* DO NOT CHANGE THE DECLARATION OF "f" (This will be converted to float later) */
    unsigned int f = 0; // DO NOT CHANGE
    /*------------------------------------------------------------------------------*/
    // Shifts sign bit over to the MSB, then shifts the masked exponent over 23, so that it takes up 8 bits after the MSB
    // Then, the fraction is masked so that the only leftmost 23 bits are utilized and is then appended into the bit sequence
    f = (sign_bit << 31) | (((int)exponent & MAX_8_BIT_NUM) << 23) | (fraction & MAX_23_BIT_NUM);
    /* DO NOT CHANGE THE RETURN VALUE (This returns the binary representation of "f" as float) */
    return *((float*)&f); // DO NOT CHANGE
    /* ----------------------------------------------------------------------------------------*/
}


int main(int argc, char** argv){
    (void) argc; // to supress compiler warning
    (void) argv;  // to supress compiler warning

    // Adding test cases provided in instruction sheet plus some of my own 
    // Casted to double in order to suppress compiler warnings
    // Cases added to TestCases.txt just in case
    // printf("f = %g\n", (double) construct_float_sf(0x01, 0x81, 0x300000));
    // printf("f = %g\n", (double) construct_float_sf(0x00, 0x7F, 0x200000));
    // printf("f = %g\n", (double) construct_float_sf(0x01, 0x7F, 0x200000));
    // printf("f = %g\n", (double) construct_float_sf(0x00, 0x81, 0x300000));
    // printf("f = %g\n", (double) construct_float_sf(0x00, 0x76, 0x299B6F));
    // printf("f = %g\n", (double) construct_float_sf(0x01, 0x76, 0x299B6F));
    // printf("f = %g\n", (double) construct_float_sf(0x00, 0x89, 0xABCDEF));
    // printf("f = %g\n", (double) construct_float_sf(0x01, 0x89, 0xABCDEF));
    // printf("f = %g\n", (double) construct_float_sf(0x00, 0x90, 0x7973C0));
    // printf("f = %g\n", (double) construct_float_sf(0x01, 0x90, 0x7973C0));
    // printf("f = %g\n", (double) construct_float_sf(0x01, 0x9F, 0xFFFFFFFF));
    // printf("f = %g\n", (double) construct_float_sf(0x00, 0x00, 0x000000));

    return 0;
}