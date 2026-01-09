#include <stdio.h>

 void* vptrfunc(){}

int main() {
    // Basic types
    printf("sizeof(char): %zu\n", sizeof(char));          // 1
    printf("sizeof(int): %zu\n", sizeof(int));            // 4
    printf("sizeof(float): %zu\n", sizeof(float));        // 4
    printf("sizeof(double): %zu\n", sizeof(double));      // 8
    
    // Hexadecimal values - treated as integers
    printf("sizeof(0x10): %zu\n", sizeof(0x10));          // 4 (int)
    printf("sizeof(0xFF): %zu\n", sizeof(0xFF));          // 4 (int)
    printf("sizeof(0xFFFFFFFF): %zu\n", sizeof(0xFFFFFFFF)); // 4 (int)
    printf("sizeof(0xFFFFFFFFFF): %zu\n", sizeof(0xFFFFFFFFFF));
    
    // With type suffix
    printf("sizeof(0x10L): %zu\n", sizeof(0x10L));        // 4 or 8 (long)
    printf("sizeof(0x10LL): %zu\n", sizeof(0x10LL));      // 8 (long long)
    
    // Pointers
    int *ptr;
    printf("sizeof(ptr): %zu\n", sizeof(ptr));            // 4 or 8
    printf("sizeof(int*): %zu\n", sizeof(int*));          // 4 or 8
    
    // Arrays
    int arr[10];
    printf("sizeof(arr): %zu\n", sizeof(arr));            // 40 (10 * 4)
    printf("sizeof(arr[0]): %zu\n", sizeof(arr[0]));      // 4
    
    // printf("sizeof(void): %zu\n", sizeof(void)); 
    // pritnf("sizeof(vptrfunc): %zu\n", sizeof(vptrfunc));

        // Functions
        //printf("sizeof(void): %zu\n", sizeof(void)); not permitted since void has no size
       // printf("sizeof(vptrfunc): %zu\n", sizeof(*vptrfunc)); // Size
    
    // Structures
    struct Test {
        char c;
        int i;
        double d;
    };
    printf("sizeof(struct Test): %zu\n", sizeof(struct Test)); // Usually 16 (due to padding)
    
    return 0;
}