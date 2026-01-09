#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){ 
    int n,T;
    cin >> n >> T;

    vector<int> arr;
    arr.resize(n);

    unordered_map<int,int> um;

    for(int i=0;i < n;i++){
        cin >> arr[i];
        um[arr[i]] = i;

        
    }

    

    cout << -1 << -1;

   // return 0;
}