//#include "log.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    //Getinputs();
    char* str = new char[100];
    cin >> str;

    for(int i = 0; str[i] != '\0'; i++){
       // cout << str[i] << '\n';
       
        if(i%2 == 0){
           // std::cout << "Even Index\n";
            str[i] = '*';
            cout << str[i];
        }
        else{
         //   std::cout << "Odd Index\n";
          std::cout << str[i] ;
        }
    }
    return 0;
}