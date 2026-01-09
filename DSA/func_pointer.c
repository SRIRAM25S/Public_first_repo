#include <stdio.h>


int add(int n,int m){ return(n + m);}

int main(){
    int (*ptr)(int, int) = NULL;
    ptr = add;
    int res = ptr(10,5);

    printf("Added value is : %d\n", res);
    return 0;
}