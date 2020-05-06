#include <iostream>
#include "sorting_algorithms.h"
/*
 * Documentation...
 * ...
 *
 */


int main() {
    int size = 10;
    int testData[size] = {10, 9, 8, 7, 6, 5, 5, 5, 2, 1};
    insertion_sort(testData, size);
    for (int i = 0; i < size; i++){
        printf("%d", testData[i]);
    }
    return 0;
}
