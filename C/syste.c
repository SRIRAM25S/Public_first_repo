#include <stdio.h>
#include <Windows.h>

int main(){

    printf("Open Notepad\n");
    system("notepad.exe syste.c");
    
    printf("Gonna sleep for 5 seconds...\n");
    Sleep(5000); // Sleep for 5000 milliseconds (5 seconds)

    printf("Sleeping completed.\n");

    return 0;
}
