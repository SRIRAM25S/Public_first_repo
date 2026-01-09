#include <stdio.h>

int main(){

    const int n;
    printf("Enter size of array: ");
    scanf("%d",&n);

    int arr[n];
    int dup[n];
   // int sub_arr[n][n]; //2D array to hold duplicates

    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int dup_count = 0;
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1; j<n;j++){
            if(arr[i] == arr[j]){
               
                int flag = 0;

                for(int k=0; k<dup_count;k++){
                    if(arr[i] == arr[k]){
                        flag = 1;
                        break;
                    }
                }
                if(!flag){
                    dup[dup_count] = arr[i];
                    dup_count++;
                }
            }

        }
    }
printf("Duplicate elements are:\n");
    for(int i =0;i<dup_count;i++){
        printf("%d ", dup[i]);
    }

return 0;

    }