#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* ===================== SELECTION SORT ===================== */
void selectionSort(int A[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min])
                min = j;
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

/* ===================== HEAP SORT ===================== */
void heapify(int A[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        heapify(A, n, largest);
    }
}

void heapSort(int A[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(A, n, i);

    for (int i = n-1; i >= 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapify(A, i, 0);
    }
}

/* ===================== QUICK SORT ===================== */
int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (A[j] < pivot) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[i+1];
    A[i+1] = A[high];
    A[high] = temp;

    return i + 1;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

/* ===================== MERGE SORT ===================== */
void merge(int A[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n1)
        A[k++] = L[i++];

    while (j < n2)
        A[k++] = R[j++];
}

void mergeSort(int A[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

/* ===================== MAIN MENU ===================== */

int main() {
    int n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("\n1. Selection Sort");
    printf("\n2. Heap Sort");
    printf("\n3. Quick Sort");
    printf("\n4. Merge Sort");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectionSort(A, n);
            printf("Sorted Array (Selection Sort): ");
            break;

        case 2:
            heapSort(A, n);
            printf("Sorted Array (Heap Sort): ");
            break;

        case 3:
            quickSort(A, 0, n-1);
            printf("Sorted Array (Quick Sort): ");
            break;

        case 4:
            mergeSort(A, 0, n-1);
            printf("Sorted Array (Merge Sort): ");
            break;

        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printArray(A, n);
    return 0;
}
