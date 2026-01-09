#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(int n){

    if(n <= 1){
        return false;
    }
    if(n == 2){
        return true;
    }
    if(n % 2 == 0){
        return false;
    }
    
    for(int i=3; i <= sqrt(n); i+=2){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int IsFact(int n){
   
    if(n > 1){
        n = n *  IsFact(n - 1);
    }
    return n;
}

int main(){
    int n{};
    cout << "Enter a number : ";
    cin >> n;

    cout << "Factorial of " << n << " is " << IsFact(n) << endl;

    // switch(IsPrime(n)){
    //     case true:
    //         cout << n << " is a prime number." << endl;
    //         break;
    //     case false:
    //         cout << n << " is not a prime number." << endl;
    //         break;
    // }
}