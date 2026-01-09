#include <iostream>

template<typename T, std::size_t M>
void findsize(T (&arr)[M]){
    
    std::cout<<"Size of array is: "<<  M  << std::endl;
    // return size;
}

int main(){
    int arr[] = {1,2,3,4,5};
    findsize(arr);

    return 0;
}