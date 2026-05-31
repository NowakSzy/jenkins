#include <stdio.h>

int main() {
    int arr[] = {45, 12, 89, 2, 10, 33};
    int n = 6;
    int temp;
    printf("Tablica przed sortowaniem: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Tablica po sortowaniu: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}