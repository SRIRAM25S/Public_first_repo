#include <stdio.h>

typedef union{
    int a;
    float b;
}u_uni;

 int main(){
    u_uni u1;
    u1.a = 42;
     u1.b = 3.14f;
    

    printf("Integer representation of int & float 3.14: %f %i \n", u1.b, u1.a);
    printf("Size of union: %zu\n", sizeof(u1)); // Size of largest member
 }