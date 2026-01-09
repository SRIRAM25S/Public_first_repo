#include <stdio.h>
#include <stdlib.h>

int main(){
    // int *arr = malloc(2 * sizeof(int));

    // arr[0] = 10;
    // arr[1] = 20;

    // arr = realloc(arr, 10 * sizeof(int));

    // arr[2] = 30;
    // arr[3] = 40; 

    // for(int i=0;i<4; i++){
    //     printf("%d ", arr[i]);
    // }

    // free(arr);

    int arr[] = {10, 20, 30};
    int *p = arr;

    printf("%d\n", *p++); // increments arr[0] from 10 → 11, prints 11
    printf("%d\n", *p); // moves pointer to arr[1], prints 20
    printf("%d\n", (*p)++); // prints 20, then increments to 21
    printf("%d\n", ++*p); // moves pointer to arr[1], prints 20
    // printf("%d\n", ++p*); // increments pointer to arr[2], increments value to 31, prints 31

    return 0;
}