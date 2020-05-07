#include <limits>
#include <cstdlib>
#include <iostream>
using namespace std;
/**
 * Merge auxiliary function that merges two subarrays that are already ordered. The subarray are in A[p..r]. Values
 * must be less than the maximum int allowed, since that number is used as +oo (sentinel)
 * @param A: Array that contains the two subarrays
 * @param p: Start of the first subarray A[p, q]
 * @param q: End of the first subarray and start of the second subarray A(q, r]
 * @param r: End of the second subarray
 */
void merge(int *A, int p, int q, int r){
    int i, j;
    int n1 = q - p + 2;
    int n2 = r - q + 1;
    // Sentinel value
    int sentinel = std::numeric_limits<int>::max();
    // Allocate space for the new subarrays L[0..n1 + 1] and R[0..n2 + 1]
    int *L = (int *) malloc((n1) * sizeof(int));
    int *R = (int *) malloc((n2) * sizeof(int));
    // Copy the values from A to L
    for (i = 0; i < n1 - 1; i++){
        L[i] = A[p + i];
    }
    // Copy the values from A to R
    for (j = 0; j < n2 - 1; j++){
        R[j] = A[q + j + 1];
    }
    // Assign the last element to be the sentinel
    L[n1 - 1] = sentinel;
    R[n2 - 1] = sentinel;
    // Set the indices to start iterating
    i = 0;
    j = 0;
    // Start comparing the two arrays and changing the values of the A array
    for (int k = p; k <= r; k++){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
    // Free memory
    free(L);
    free(R);
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * Implementation of insertion sort algorithm. Receives and array to be sorted, sorts and returns nothing
 * @param array: array to be sorted
 * @param n: size of the array
 */
void insertion_sort(int* array, int n){
    // Starts always with the first element
    for (int i = 1; i < n; i++){
        // Key is the current element to be compared with the left array [0, j -1] which is already sorted
        int key = array[i];
        // Set the other index to be the element before the key
        int j = i - 1;
        // If we are in the array and swaps need to be made, swaps.
        while (j >= 0 && array[j] > key){
            // Swaps and decrease j to compare with the next left element
            swap(&array[j], &array[j+1]);
            j -= 1;
        }
    }
}

/**
 * Implementation of selection sort algorithm. Receives and array to be sorted, sorts and returns nothing
 * @param A: Array to be sorted
 * @param n: Length of the array
 */
void selection_sort(int* A, int n){
    for (int i = 0; i < n-1; i++){
        // Set the smallest to be the leftmost of the unsorted array A[i...n]
        int smallest = i;
        // Find the smallest element in the array
        for (int j = i + 1; j < n; j++){
            if (A[j] < A[smallest])
                smallest = j;
        }
        // Once the smallest element has been found, swap it with A[i]
        swap(&A[i], &A[smallest]);
    }
}

/**
 * Implementation of the classic bubblesort algorithm. Some modifications could be made to make it a little more better.
 * @param A: Array to be sorted
 * @param n: Length of the array
 */
void bubblesort(int* A, int n){
    // Starts iterating over all the array n*n times
    for (int i = 0; i < n - 1; i++){
        for (int j = n - 1; j >= i + 1; j--){
            // If the elements are out of order, swap
            if (A[j - 1] > A[j])
                swap(&A[j], &A[j - 1]);
        }
    }
}

/**
 * Implementation of merge sort algorithm. Receives and array to be sorted, sorts and returns nothing
 * @param A: Array to be sorted
 * @param p: Initial value when called MUST be 0
 * @param r: Final value of the array. Initial value when called MUST BE the length of the array
 */
void merge_sort(int* A, int p, int r){
    // If p >= r the length of the array = 1 so it is already sorted
    if (p < r){
        // Find the middle position
        int q = (p + r) / 2;
        // Sort left array
        merge_sort(A, p, q);
        // Sort right array
        merge_sort(A, q + 1, r);
        // Merge the entire array. Each subarray is already sorted
        merge(A, p, q, r);
    }
}

void quicksort(int* A, int n){

}
