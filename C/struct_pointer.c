#include <stdio.h>


typedef struct Date{
    short day;
    char month;
    short year;
}Date;

int main(){
    Date *T1 = malloc(sizeof(Date));
    Date *T2 = calloc(20, sizeof(Date));

    T1 -> day = 19;
    T1 -> month = 12;
    T1 -> year = 2021;

    // T2[0].day = 19;
    // T2[0].month ;
    // T2[0].year = 202089;

    // printf("T1 ==> %02i - %02i - %04i \n", T1->day, T1->month, T1 -> year);
    // printf("T2 ==> %02i - %02i - %04i \n", T2->day, T2->month, T2 -> year);

    for(int i=0; i<400;i++){
        T2[i].day = 1 + i;
        T2[i].month = 9;
        T2[i].year = 2020 + i;       
        
        printf("T2[%i] ==> %02i - %02i - %04i \n", i, T2[i].day, T2[i].month, T2[i] .year);
    
    }
    
    free(T2);
    free(T1);

    return 0;
}