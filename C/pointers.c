#include <stdio.h>
#include <string.h>

// Generic comparison function
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Generic swap function
void swap(void *a, void *b, const size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

 void printArray(void *arr, size_t count, size_t elemSize, char type) {
       // Print array of any type
    for (size_t i = 0; i < count; i++) {
        void *elem = (char*)arr + i * elemSize;
        switch (type) {
            case 'i':
                printf("%d ", *(int*)elem);
                break;
            case 'f':
                printf("%.2f ", *(float*)elem);
                break;
            case 'c':
                printf("%c ", *(char*)elem);
                break;
            // Add more types as needed
        }
   }
}

int main() {
    int arr[] = {5, 2, 8, 1, 9};
    int n = 5;
    
    // qsort uses void* for generic sorting
    qsort(arr, n, sizeof(int), compare);
    
    int a = 10;
    int *p_a = &a;

    //p_a++; // Move pointer to next integer location
    printf("Value after incrementing pointer: %d\n",*p_a);
    (*p_a)++;;
    printf("Value after post-incrementing pointer: %d\n",*p_a);
    // *p_a++;
    // printf("Value after another post-incrementing pointer: %d\n",*p_a);
    ++(*p_a); // Increment the value pointed to
    printf("Value after incrementing the value pointed to: %d\n",*p_a);
    *(++p_a); // Pre-increment pointer and dereference
    printf("Value after pre-incrementing pointer: %d\n",*p_a);  

    printf("Sorted: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


    
    return 0;
}