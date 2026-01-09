#include <stdio.h>


int sumofsquare(int n){
    if(n ==0 || n==1){
        return n;
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum = sum + (i*i);
    }

    return sum;
}
int main()
{   
    printf("Sum of squares of n numbers is %d\n", sumofsquare(2 ));
    return 0;
}