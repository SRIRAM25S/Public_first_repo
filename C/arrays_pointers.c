#include <stdio.h>

int main(){
    // int arr[10][2] = {
    //     {1,2},
    //     {3,4},
    //     {5,6},
    //     {7,8},
    //     {9,10},
    //     {11,12},
    //     {13,14},
    //     {15,16},
    //     {17,18},
    //     {19,20}
    // };

//    int *p_arr = &arr;
    
//     printf("%d \n", arr[0][1]);
//     printf("%d \n", *(p_arr + 5 ));

//  // int *parr[10]; // Array of 10 integer pointers

    // for(int i=0; i< 10; i++){
    //     parr[i] = &arr[i][0]; //for pointer we need address of first element
    // }

    // for(int i=0; i<10; i++){
    //     printf("%d \n", *(parr[i]+ 1));
// // }

    char *s1 = "Hi, Volt here!";
    printf("%s\n", s1);


    char *s2[] = {"Hello"};
    s2[0] = 'H'; // Modifying first character
    printf("%s\n", s2);

    if(0.0){
        printf("0.0 -> True\n");
    } else {
        printf("0.0 -> False\n");
    }

    if(NULL){
        printf("NULL -> True\n");
    } else {
        printf("NULL -> False\n");
    }

    if(0.3){
        printf("0.3 -> True\n");
    } else {
        printf("0.3 -> False\n");
    }

    if(0.7){
        printf("0.7 -> True\n");
    } else {
        printf("0.7 -> False\n");
    }   

    int a = 1;
    int b= 2;

    int c;

    c = b;
    printf("a: %d, b: %d, c: %d\n", a, b, c);

    if(a==b==c){
        printf("Chained equality is True\n");
    } else {
        printf("Chained equality is False\n");
    }

    int fa = fabs(a - b);
    printf("Absolute value of b - a is: %d\n", fa);

    return 0;
}