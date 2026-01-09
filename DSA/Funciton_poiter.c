#include <stdio.h>

int add(int a,int b){return a + b;}
int sub(int a,int b){return a - b;}

int main(){

    //void Function pointer declaration
  //  void (*ptr)(void);
    int (*ptr)(int , int );
    
    ptr = add;

    printf("Addition is : %d\n",ptr(10,5)) ;
    return 0;

}