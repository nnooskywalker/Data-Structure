#include <stdio.h>
#define gc getchar()
int main() {
    int n = 0;
    scanf("%d", &n); gc;

    int arr[n];
    int sum = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); gc;
        sum += arr[i];
    }

    int min = arr[0], max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }

    int total = max - min + 1;
    int expected_sum = (min + max) * total / 2;

    int missing = expected_sum - sum;

    printf("The given array is : ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nThe missing number is : %d\n", missing);

    return 0;
}
