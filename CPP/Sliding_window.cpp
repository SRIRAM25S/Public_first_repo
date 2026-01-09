#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,S;
    cout << "Enter the size of the array and its sum: ";
    cin>>n>>S;

    vector<int> arr;

    arr.resize(n);
    cout << "ENter the values in the arr";
    for (int i=0; i<n; i++){
         cin >> arr[i];
    }

    int L{},R{},sum{},max_count{};
    int new_L{},new_R{};

    for (R=0; R<n; R++){
        sum += arr[R];
        
        while(sum >= S){
            sum -= arr[L];
            L++; 
        }
            if(R-L+1 > max_count){
                max_count = R - L + 1;
                new_L = L;
                new_R = R;
            }

        }
        cout << "\n"<< new_L <<"\n";
        cout << "\n"<< new_R <<"\n";
        
        for(int i = new_L; i<=new_R;++i){
            cout << arr[i]<< " ";
        }

        //cout << max_count;
         return 0;
    }

   
