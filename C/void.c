#include <stdio.h>

int main() {
    int num = 42;
    float pi = 3.14;
    char ch = 'A';
    
    void *ptr;  // Generic pointer
    
    // Can point to int
    ptr = &num;
    printf("Int: %d\n", *(int*)ptr);  // Must cast to use
    
    // Can point to float
    ptr = &pi;
    printf("Float: %.2f\n", *(float*)ptr);
    
    // Can point to char
    ptr = &ch;
    printf("Char: %c\n", *(char*)ptr);
    
    printf("\nsizeof(ptr): %zu (always pointer size)\n", sizeof(ptr));
    
    return 0;
}