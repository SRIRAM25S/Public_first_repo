#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){

    int a =11;
    int b =22;
    swap(&a, &b);

    printf("After SWAP --> \na : %d\nb : %d",a,b);

}