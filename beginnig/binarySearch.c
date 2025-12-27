#include <stdio.h>

int main() {
    int data[13] = {11, 22, 30, 33, 40, 44, 55, 60, 66, 77, 80, 88, 99};
    int low = 0, high = 12, mid, item = 44;

    while(low <= high){
        mid = (low + high) / 2;

        if(data[mid] == item){
            printf("Item %d found at index %d (position %d)\n", item, mid, mid + 1);
            return 0;
        } else if(data[mid] > item) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("Item not found.\n");
    return 0;
}