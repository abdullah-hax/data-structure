#include <stdio.h>

int main() {
    int arr[5];
    int i, j;

    for(i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 5 - 1; i++){
        for(j = i + 1; j < 5; j++){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    for (i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}