#include <stdio.h>

void swap(int *v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}
/**
 * Implementation of insertion sort algorithm. Receives and array to be sorted, sorts and returns nothing
 * @param array: array to be sorted
 * @param n: size of the array
 */
void insertion_sort(int* array, int n){
    for (int i = 1; i < n; i++){
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key){
            swap(array, j, j + 1);
            j -= 1;
        }
    }
}

