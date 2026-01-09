#include <iostream>
using namespace std;

class Dummy {
    public:
    int x;
    string name;
    Dummy(){
        x = 0;
        name = "";
        cout<<"Default Constructor Called, x = " << x << ", name = " << name << "\n";
    }
    Dummy(const Dummy &other) {
        x = other.x;
        name = other.name;
        cout<<"Copy Constructor Called, x = " << x << ", name = " << name << "\n";
    }
};

int main(){
    Dummy obj1;
    obj1.x = 42;
    obj1.name = "TestObject";

    Dummy obj2 = obj1; // Invokes copy constructor
    cout<<"obj2.x = " << obj2.x << "\n";

    return 0;
}