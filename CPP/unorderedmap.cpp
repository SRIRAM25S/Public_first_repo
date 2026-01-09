#include <iostream>
#include <unordered_map>
#include <string>
#include <map>

using namespace std;

int main() {

    unordered_map <int,int> um;

    int n;
    cout << "Enter number of elements to insert in unordered_map: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        um[arr[i]]++;
    }
    
    for(int i=0; i<n; i++){
        if(um[arr[i]] == 1){
            cout<< arr[i] << " ";
        }
    }
    
    return 0;
}