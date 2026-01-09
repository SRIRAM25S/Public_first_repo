#include <stdio.h>

void remove_char(char *st, char remove);
void reverse(char *str);

void remove_char(char *st, char remove){
    char *r = st;
    char *w = st;

    while(*r != '\0'){
        if(*r != remove){
            *w = *r;
            w++;
        }
        r++;
    }
    //printf("Value of w : %s\n",w);
    *w = '\0';

  //  printf("After removing characters: %s\n",st);

}

void reverse(char *str){
    char *start = str;
    char *end = str;

    char temp;

    while(*end != '\0'){
        end++;
    }
    end--;

    while(start < end){
        temp = *start;
        *start = *end;
        *end = temp;
                
        start++;
        end--;
    }

  //  printf("Reversed string: %s\n",str);
}


int main(){

    char str[] = "Hello World is beautiful.";
    char dup[sizeof(str)];
    char rem = 'l';
    //char *v = "Sriram";
    remove_char(str,rem);
    printf("After removing character: %s\n",str);
    // reverse(v);
    
    //char dup[sizeof(str)];
    int i = 0;
    while(str[i] != '\0'){
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';

    printf("Cloning the string: %s\n",dup);

    


     reverse(dup);
     printf("Final reversed string: %s\n",dup);
    printf("Original string after operations: %s\n",str);

    return 0;
}