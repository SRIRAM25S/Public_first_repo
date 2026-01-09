#include <stdio.h>

void remove_char(char *str, char del){
    
    char *r = str;
    char *w = str;

    while(*r != '\0'){
        if(*r != del){
            *w = *r;
            w++;
        }
        r++;
    }
    *w = '\0';
}

void reverse(char *str){
    char *start = str;
    char *end = str;
    char temp;

    int i = 0;
    while(*end != '\0'){
        end++;
    }

    end --;

    while(start < end){
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int palindrom (char *str){
    char *start = str;
    char *end = str;

    // int i=0;
    while(*end != '\0'){
        end++;
    }
    end--;

    while(start < end){
        if(*start != *end){
            return 0;
        }
            start++;
            end--;
    }
    return 1;
}

int main(){

    char str[] = "Welcome to Hello World!";
    char del[] = "Hello";

    remove_char(str,del);
    printf("After removing the char : %s",str);

    reverse(str);
    printf("\nAfter reversing the string: %s\n",str);

    char pal[] = "malaylalam";
    if(palindrom(pal)){
        printf("The string is a palindrom\n");
    } else {
        printf("The string is not a palindrom\n");
    }

    return 0;
}