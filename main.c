#include <stdio.h>

int main(void) {
    int arr[] = {5, 2, 8, 1, 9, 3};
    int n = 6;
    int i, j, temp;

    (void)printf("Tablica przed sortowaniem: ");
    for(i = 0; i < n; i++) {
        (void)printf("%d ", arr[i]);
    }
    (void)printf("\n");

    for(i = 0; i < (n - 1); i++) {
        for(j = 0; j < (n - i - 1); j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    (void)printf("Tablica po sortowaniu: ");
    for(i = 0; i < n; i++) {
        (void)printf("%d ", arr[i]);
    }
    (void)printf("\n");

    return 0;
}
