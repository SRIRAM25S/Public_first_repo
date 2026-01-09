#include <stdio.h>

int palindrome(int n){

    int divisor = 1;
    while( n/divisor >= 10){
        divisor *= 10;
    }
    
    while(n > 0){
        int l = n/divisor;
        int r = n%10;

        if( l != r){
            return 0;    
        }

        n = (n%divisor) / 10;
        divisor/=100;

        printf("n => %d\n",n);
        printf("d => %d\n",divisor);
    }
    return 1;
    
}

int main(){

    int n;
    scanf("%d",&n);
    if(palindrome(n)){
        printf("Pali\n");
    }else{
        printf("Nah");
    }

    return 0;
}