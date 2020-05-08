#include <iostream>
#include <valarray>
#include "sorting_algorithms.h"
/*
 * Documentation...
 * ...
 *
 */
using namespace std;

int main() {
    int size = 10;
    /*
    int testData[] = {10, 9, 8, 7, 6, 5, 5, 5, 2, 1};
    printf("\n");
    printf("Selection Sort.... \n");
    selection_sort(testData, size);
    for (int i = 0; i < size; i++){
        cout << testData[i] << " ";

    }
    cout << endl;
    int testData2[] = {10, 9, 8, 7, 6, 5, 5, 5, 2, 1};
    printf("Insertion Sort.... \n");
    insertion_sort(testData2, size);
    for (int i = 0; i < size; i++){
        cout << testData2[i] << " ";
    }
    cout << endl;
    int testData3[] = {10, 9, 8, 7, 6, 5, 5, 5, 2, 1};
    printf("Bubblesort.... \n");
    bubblesort(testData3, size);
    for (int i = 0; i < size; i++){
        cout << testData3[i] << " ";
    }
    cout << endl;
     */
    printf("Testing merge.... \n");
    int testData4[] = {10, 9, 8, 7, 6, 5, 5, 5, 2, 1};
    merge_sort(testData4, 0, 9);
    for (int i = 0; i < 10; i++){
        cout << testData4[i] << " ";
    }
    printf("Testing quicksort.... \n");
    int testData5[] = {10, 9, 8, 7, 6, 5, 5, 5, 2, 1};
    quick_sort(testData5, 0, 9);
    for (int i = 0; i < 10; i++){
        cout << testData5[i] << " ";
    }



    return 0;



}
