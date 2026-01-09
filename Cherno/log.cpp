#include "log.h"
#include <iostream>

void Multiplyandlog(int a, int b){
    std::cout << "Multiplied value :" << a*b << std::endl;
}

void Getinputs(){
    int a,b;
    std::cout << "Enter two numbers to multiply: ";
    std::cin >> a >> b;
    Multiplyandlog(a,b); 
}