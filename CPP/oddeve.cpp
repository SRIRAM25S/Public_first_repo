#include <iostream>
using namespace std;

int main(){
    // int n{};
    // cin >> n;

    // if((n&1)==0){
    //     std::cout<<"Even"<<endl;
    // }else{
    //     std::cout<<"Odd"<<endl;
    // }
    int a{0};
    int b{1};
    int temp{0};

    int count{0};
     cout << a <<" "<< b << " ";
    while(true){
      
        if(count == 8){
            break;
        }

        temp = a+ b;
        cout << temp << " ";

        a = b;
        b =temp;
    
        count++;
    }
   return 0;
}