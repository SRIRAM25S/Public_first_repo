#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  
   int a;
   cout << "Enter the range of Multiplication Grid: ";
   cin >> a;

   for (int i = 1; i<= a; i++){
      cout << setw(4) << i ;
   }

    cout << endl << "\t+";

   for(int i=1; i <= 40; i++){
     cout << "-";
   }

   cout << endl;

   for (int i=1; i<=a; i++)
   {
      cout << setw(4) << i << " |";
      /* code */
      for ( int j=1; j <= a; j++){
         cout << setw(4)<< i*j;
      }
      cout << endl;
   }
   
   


   return 0;
}

