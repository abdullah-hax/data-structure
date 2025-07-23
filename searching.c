#include <stdio.h>

int main() {
    int arr[5];
    int x;
    int i;
    
    for(i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);
    
    for(i = 0; i < 5; i++){
        if (arr[i] == x){
            printf("found");
            return 0;
        }
    }

    printf("not found");

}