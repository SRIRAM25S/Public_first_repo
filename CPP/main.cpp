#include <iostream>
#include <string>
using namespace std;

class Addition{
    public:
     int add( int a, int b);
    string add(char a, char b);
     int add( int a, int b, int c);
     int add( int a, int b, int c, int d);
     int add( int a, int b, int c, int d, int e) = delete; // Deleting this function to prevent its use
};

int Addition::add( int a, int b){
    return a + b;
}

std::string Addition::add(char a, char b){
    std::string res;
    res += a;
    res += b;
    cout<<"value of res char = "<< res <<endl;
    return res;
}

int Addition::add( int a, int b, int c){
    return a + b + c;
}

int Addition::add( int a, int b, int c, int d){
    return a + b + c + d;
}

int main() {
   

   int a;
   cin >> a;
    int res = 1;
    if(a != 0 && a != 1){
   for(a; a>=1; --a){
    res *= a;
   }
}else{
    cout<<"Invalid input"<<endl;
    return 0;
}

   cout << res << endl;
    return 0;
}