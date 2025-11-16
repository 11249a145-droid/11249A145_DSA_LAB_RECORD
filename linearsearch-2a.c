#include <stdio.h>

int main() {
    int n, key, i, found = 0;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Linear Search logic
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    // If not found
    if (!found) {
        printf("Element not found in the array.\n");
    }

    return 0;
}

output:
Enter number of elements: 5
Enter 5 elements:
2 8 3 1 6
Enter element to search: 3
Element found at position 3
