#include <stdio.h>

int main() {
     int n;
    printf("Enter no of element in array : ");
    scanf("%d", &n);
    int myArray[n];
    printf("Enter Element\nPlease enter one element extra them number of total element(bug)\n");
    for(int i=0;i<n;i++){
        scanf("%d ", &myArray[i]);
    }

    for (int i = 1; i < n; i++) {
        int insertIndex = i;
        int currentValue = myArray[i];
        int j = i - 1;

        while (j >= 0 && myArray[j] > currentValue) {
            myArray[j + 1] = myArray[j];
            insertIndex = j;
            j--;
        }
        myArray[insertIndex] = currentValue;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", myArray[i]);
    }

    return 0;
}
