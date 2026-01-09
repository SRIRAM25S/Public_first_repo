#include <stdio.h>

int main() {
    int arr[] = {10, 20, 4, 45, 99};
    int n = sizeof(arr)/sizeof(arr[0]);

    int first = -1e9, second = -1e9;  // very small initial values

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == -1e9)
        printf("No second largest element\n");
    else
        printf("Second largest = %d\n", second);

    return 0;
}
