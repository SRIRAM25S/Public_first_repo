#include <stdio.h>
#include <string.h>

int string_compare(const char *str1, const char *str2){
    while(*str1 && (*str1 == *str2)){
        str1++;
        str2++;
    }
    return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

int main(){

    char *str_1 = malloc(100);
    char *str_2 = malloc(100);

    scanf("%s", &str_1);
    scanf("%s", &str_2);

    int inbuild = strcmp(str_1, str_2);
    printf("Inbuilt strcmp result: %d\n", inbuild);

    int res = string_compare(str_1, str_2);
    printf("Custom string_compare result: %d\n", res);

    return 0;
}