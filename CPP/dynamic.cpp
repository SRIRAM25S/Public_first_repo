#include <iostream>
using namespace std;

class Todo{

    int* arr;
public:
    Todo(int n){
        arr = new int[n];
    }

    int Getinput(int n){
        for(int i=0; i < n; i++){
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }
    }

    double Average(int n){
        int sum{0};
        for(int i=0; i < n; i++){
            sum += arr[i];
        }
        return static_cast<double>(sum) / n;
    }
    ~Todo(){
        delete[] arr;
    }

};

int main(){
    int n{};
    
    cout << "Enter the number of elements: ";
    cin >> n;
    Todo obj(n);
   
    obj.Getinput(n);
    cout<< "Average:   " << obj.Average(n)<< endl ;
    obj.~Todo();

   return 0;
}