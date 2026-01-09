#include <stdio.h>
int main() {
    int *p;
    char *c;
    double *d;

    printf("sizeof(p) = %zu\n", sizeof(p));   // size of pointer (4 or 8)
    printf("sizeof(*p) = %zu\n", sizeof(*p)); // size of int (usually 4)

    printf("sizeof(c) = %zu\n", sizeof(c));   // pointer size
    printf("sizeof(*c) = %zu\n", sizeof(*c)); // size of char (1)

    printf("sizeof(d) = %zu\n", sizeof(d));   // pointer size
    printf("sizeof(*d) = %zu\n", sizeof(*d)); // size of double (8)
}
