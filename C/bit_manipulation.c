#include <stdio.h>

// Function to print binary representation
void printBinary(int num) {
    printf("Binary: ");
    
    for (int i=31; i>=0; i--){
        int bits = (num >> i) &1;
        printf("%d",bits);

        if(i%4 == 0 && i != 0){
            printf("\t");
        }
    }
    printf("\n");   
}

void countSetBits(int num) {
    int count = 0;
    while (num) {
        num &= (num - 1);  // Clears the rightmost set bit
        count++;
    }
    printf("Number of set bits: %d\n", count);
    // return count;
}

// Function to find which bit positions are set
void findSetBits(int num) {
    printf("Set bit positions: ");
    
    for(int i=0; i <= 31;i++){
        if(num & (1<<i)){
            printf("%d ", i);
    }
   // 
}
printf("\n"); 
}

int main() {
    int num;
    
    printf("Enter a number (decimal or hex): ");
    scanf("%i", &num);  // %i accepts both decimal and hex (0x...)
    

    int leftshifted = num << 1;
    printf("Left shifted by 2: %d\n", leftshifted);

    int rightshifted = num >> 1;
    printf("Right shifted by 2: %d\n", rightshifted);

    // printf("\nDecimal: %d\n", num);
    // printf("Hexadecimal: 0x%X\n", num);
    // printf("Octal: 0%o\n", num);
    
    printBinary(num);
    findSetBits(num);
    countSetBits(num);
    
    return 0;
}
