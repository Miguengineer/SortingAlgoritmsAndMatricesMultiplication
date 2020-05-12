#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include "sorting_algorithms.h"
#include "matrices_mult.h"

using namespace std;
int ARRAY_SIZES[3] = {1000, 100000};
// Arrays where to store information numbers
int *array_size1000 = new int[1000];
int *array_size100000 = new int[100000];

/**
 * Initialize matrix to some value, in this case just i + j
 * @param C: where to store result matrix
 * @param rows: Rows of C
 * @param cols: Columns of C
 */
void initialize_matrix(int **C, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            C[i][j] = i + j;
        }
    }
}

/**
 * Load data from disk
 */
void load_data_unordered_with_repetition(){
    // Declare input file stream
    ifstream inFile;
    string line;
    // Fill arrays with the datasets
    cout << "Filling arrays with the information ..." << endl;
    for (int i = 0; i < 2; i++){
        inFile.open("/home/krampus/CLionProjects/SortingMatricesHomework1/Datasets/UnorderedListsWithRepetition/" +
                    to_string(ARRAY_SIZES[i]) + ".txt");
        if (!inFile) {
            cerr << "Unable to open file datafile.txt";
            exit(1);   // call system to stop
        }
        if (i == 0){
            int j = 0;
            while(getline(inFile, line)){
                array_size1000[j] = stoi(line);
                j++;
            }
        }
        else {
            int j = 0;
            while(getline(inFile, line)){
                array_size100000[j] = stoi(line);
                j++;
            }
        }
        inFile.close();
    }
}
/**
 * Load data from disk
 */
void load_data_unordered_without_repetition(){
    // Declare input file stream
    ifstream inFile;
    string line;
    // Fill arrays with the datasets
    cout << "Filling arrays with the information ..." << endl;
    for (int i = 0; i < 2; i++){
        inFile.open("/home/krampus/CLionProjects/SortingMatricesHomework1/Datasets/UnorderedListsWithoutRepetition/" +
                    to_string(ARRAY_SIZES[i]) + ".txt");
        if (!inFile) {
            cerr << "Unable to open file datafile.txt";
            exit(1);   // call system to stop
        }
        if (i == 0){
            int j = 0;
            while(getline(inFile, line)){
                array_size1000[j] = stoi(line);
                j++;
            }
        }
        else {
            int j = 0;
            while(getline(inFile, line)){
                array_size100000[j] = stoi(line);
                j++;
            }
        }
        inFile.close();
    }
}
/**
 * Load data from disk
 */
void load_data_unordered_reverse(){
    // Declare input file stream
    ifstream inFile;
    string line;
    // Fill arrays with the datasets
    cout << "Filling arrays with the information ..." << endl;
    for (int i = 0; i < 2; i++){
        inFile.open("/home/krampus/CLionProjects/SortingMatricesHomework1/Datasets/UnorderedListsReverse/" +
                    to_string(ARRAY_SIZES[i]) + ".txt");
        if (!inFile) {
            cerr << "Unable to open file datafile.txt";
            exit(1);   // call system to stop
        }
        if (i == 0){
            int j = 0;
            while(getline(inFile, line)){
                array_size1000[j] = stoi(line);
                j++;
            }
        }
        else {
            int j = 0;
            while(getline(inFile, line)){
                array_size100000[j] = stoi(line);
                j++;
            }
        }
        inFile.close();
    }
}
/**
 * Load data from disk
 */
void load_data_partially_ordered(){
    // Declare input file stream
    ifstream inFile;
    string line;
    // Fill arrays with the datasets
    cout << "Filling arrays with the information ..." << endl;
    for (int i = 0; i < 2; i++){
        inFile.open("/home/krampus/CLionProjects/SortingMatricesHomework1/Datasets/PartiallyOrderedLists/" +
                    to_string(ARRAY_SIZES[i]) + ".txt");
        if (!inFile) {
            cerr << "Unable to open file datafile.txt";
            exit(1);   // call system to stop
        }
        if (i == 0){
            int j = 0;
            while(getline(inFile, line)){
                array_size1000[j] = stoi(line);
                j++;
            }
        }
        else {
            int j = 0;
            while(getline(inFile, line)){
                array_size100000[j] = stoi(line);
                j++;
            }
        }
        inFile.close();
    }
}

/**
 * This function test merge sort (measuring time) with different arrays of characteristics and different
 * sizes. Test is performed several times for each dataset
 */
void test_mergesort(){
    cout << "****************Testing MergeSort Algorithm ****************" << endl;
    cout << "****************Testing Unordered lists with repetition****************" << endl;
    load_data_unordered_with_repetition();
    cout << "Testing MergeSort with array size 1000" << endl;
    auto start = std::chrono::system_clock::now();
    merge_sort(array_size1000,0, 1000);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing MergeSort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    merge_sort(array_size100000,0, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Without repetition
    cout << "****************Testing Unordered lists without repetition****************" << endl;
    load_data_unordered_without_repetition();
    cout << "Testing MergeSort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    merge_sort(array_size1000, 0, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing MergeSort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    merge_sort(array_size100000,0, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Reverse Order
    cout << "****************Testing Unordered lists with reverse order (worst case) ****************" << endl;
    load_data_unordered_reverse();
    cout << "Testing MergeSort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    merge_sort(array_size1000, 0, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing MergeSort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    merge_sort(array_size100000,0, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Partially Ordered
    cout << "****************Testing partially ordered (40%) list ****************" << endl;
    load_data_partially_ordered();
    cout << "Testing MergeSort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    merge_sort(array_size1000,0, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing MergeSort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    merge_sort(array_size100000, 0, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
}
/**
 * This function tests insertion sort (measuring time) with different arrays of characteristics and different
 * sizes. Test is performed several times for each dataset
 */
void test_insertionsort(){
    cout << "****************Testing Unordered lists with repetition****************" << endl;
    load_data_unordered_with_repetition();
    cout << "Testing Insertion sort with array size 1000" << endl;
    auto start = std::chrono::system_clock::now();
    insertion_sort(array_size1000, 1000);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing Insertion sort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    insertion_sort(array_size100000, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Without repetition
    cout << "****************Testing Unordered lists without repetition****************" << endl;
    load_data_unordered_without_repetition();
    cout << "Testing Insertion sort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    insertion_sort(array_size1000, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing Insertion sort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    insertion_sort(array_size100000, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Reverse Order
    cout << "****************Testing Unordered lists with reverse order (worst case) ****************" << endl;
    load_data_unordered_reverse();
    cout << "Testing Insertion sort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    insertion_sort(array_size1000, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing Insertion sort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    insertion_sort(array_size100000, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Partially Ordered
    cout << "****************Testing partially ordered (40%) list ****************" << endl;
    load_data_partially_ordered();
    cout << "Testing Insertion sort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    insertion_sort(array_size1000, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing Insertion sort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    insertion_sort(array_size100000, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
}
/**
 * This function tests quick sort (measuring time) with different arrays of characteristics and different
 * sizes. Test is performed several times for each dataset
 */
void test_quicksort(){
    cout << "****************Testing QuickSort Algorithm ****************" << endl;
    cout << "****************Testing Unordered lists with repetition****************" << endl;
    load_data_unordered_with_repetition();
    cout << "Testing QuickSort with array size 1000" << endl;
    auto start = std::chrono::system_clock::now();
    quick_sort(array_size1000,0, 1000);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing QuickSort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    quick_sort(array_size100000,0, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Without repetition
    cout << "****************Testing Unordered lists without repetition****************" << endl;
    load_data_unordered_without_repetition();
    cout << "Testing QuickSort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    quick_sort(array_size1000, 0, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing QuickSort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    quick_sort(array_size100000,0, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Reverse Order
    cout << "****************Testing Unordered lists with reverse order (worst case) ****************" << endl;
    load_data_unordered_reverse();
    cout << "Testing QuickSort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    quick_sort(array_size1000, 0, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing QuickSort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    quick_sort(array_size100000,0, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Partially Ordered
    cout << "****************Testing partially ordered (40%) list ****************" << endl;
    load_data_partially_ordered();
    cout << "Testing QuickSort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    quick_sort(array_size1000,0, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing QuickSort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    quick_sort(array_size100000, 0, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
}
/**
 * This function tests bubble sort (measuring time) with different arrays of characteristics and different
 * sizes. Test is performed several times for each dataset
 */
void test_bubblesort(){
    cout << "****************Testing Bubblesort Algorithm ****************" << endl;
    cout << "****************Testing Unordered lists with repetition****************" << endl;
    load_data_unordered_with_repetition();
    cout << "Testing Bubblesort with array size 1000" << endl;
    auto start = std::chrono::system_clock::now();
    bubblesort(array_size1000, 1000);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing Bubblesort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    bubblesort(array_size100000, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Without repetition
    cout << "****************Testing Unordered lists without repetition****************" << endl;
    load_data_unordered_without_repetition();
    cout << "Testing Bubblesort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    bubblesort(array_size1000, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing Bubblesort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    bubblesort(array_size100000, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Reverse Order
    cout << "****************Testing Unordered lists with reverse order (worst case) ****************" << endl;
    load_data_unordered_reverse();
    cout << "Testing Bubblesort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    bubblesort(array_size1000, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing Bubblesort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    bubblesort(array_size100000, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Partially Ordered
    cout << "****************Testing partially ordered (40%) list ****************" << endl;
    load_data_partially_ordered();
    cout << "Testing Bubblesort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    bubblesort(array_size1000, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing Bubblesort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    bubblesort(array_size100000, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
}
/**
 * This function tests selection sort (measuring time) with different arrays of characteristics and different
 * sizes. Test is performed several times for each dataset
 */
void test_selectionsort(){
    cout << "****************Testing Unordered lists with repetition****************" << endl;
    load_data_unordered_with_repetition();
    cout << "Testing SelectionSort with array size 1000" << endl;
    auto start = std::chrono::system_clock::now();
    selection_sort(array_size1000, 1000);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing SelectionSort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    selection_sort(array_size100000, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Without repetition
    cout << "****************Testing Unordered lists without repetition****************" << endl;
    load_data_unordered_without_repetition();
    cout << "Testing SelectionSort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    selection_sort(array_size1000, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing SelectionSort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    selection_sort(array_size100000, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Reverse Order
    cout << "****************Testing Unordered lists with reverse order (worst case) ****************" << endl;
    load_data_unordered_reverse();
    cout << "Testing SelectionSort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    selection_sort(array_size1000, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing SelectionSort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    selection_sort(array_size100000, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Partially Ordered
    cout << "****************Testing partially ordered (40%) list ****************" << endl;
    load_data_partially_ordered();
    cout << "Testing SelectionSort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    selection_sort(array_size1000, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing SelectionSort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    selection_sort(array_size100000, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
}
/**
 * This function STD sort (measuring time) with different arrays of characteristics and different
 * sizes. Test is performed several times for each dataset
 */
void test_std_sort(){
    cout << "****************Testing Unordered lists with repetition****************" << endl;
    load_data_unordered_with_repetition();
    cout << "Testing STD Sort with array size 1000" << endl;
    auto start = std::chrono::system_clock::now();
    sort(array_size1000, array_size1000 + 1000);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing STD Sort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    sort(array_size100000, array_size100000 + 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Without repetition
    cout << "****************Testing Unordered lists without repetition****************" << endl;
    load_data_unordered_without_repetition();
    cout << "Testing STD Sort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    sort(array_size1000, array_size1000 + 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing STD Sort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    sort(array_size100000, array_size100000 + 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Reverse Order
    cout << "****************Testing Unordered lists with reverse order (worst case) ****************" << endl;
    load_data_unordered_reverse();
    cout << "Testing STD Sort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    sort(array_size1000, array_size1000+ 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing STD Sort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    sort(array_size100000, array_size100000 + 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Partially Ordered
    cout << "****************Testing partially ordered (40%) list ****************" << endl;
    load_data_partially_ordered();
    cout << "Testing STD Sort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    sort(array_size1000, array_size1000 + 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing STD Sort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    sort(array_size100000, array_size100000+ 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
}

/**
 * This function test matrices multiplication algorithm, measuring its execution time. Matrices to be tested
 * are just matrices initialized with initialize_matrix.
 */
void run_test_matrix(){
    cout << "Matrices Test Started" << endl;
    cout << "**************Testing regular matrices multiplication**************" << endl;
    cout << "Testing A[100][100]*B[100][100]" << endl;
    // Initialize number of rows and columns to be tested. Start with square matrices
    int A_rows = 100;
    int A_cols = 100;
    int B_rows = 100;
    int B_cols = 100;
    // Array of pointers
    int** A = new int*[A_rows];
    for (int i = 0; i < A_rows; i++)
    {
        A[i] = new int[A_cols];
    }
    int** B = new int*[B_rows];
    for (int i = 0; i < B_rows; i++)
    {
        B[i] = new int[B_cols];
    }
    initialize_matrix(A, A_rows, A_cols);
    initialize_matrix(B, B_rows, B_cols);
    int** C;
    C = new int*[A_rows];
    for (int i = 0; i < A_rows; i++)
    {
        C[i] = new int [B_cols];
    }
    auto start = std::chrono::system_clock::now();
    regular_multiplication(C, A, B, A_rows, A_cols, B_rows, B_cols);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout.precision(7);
    cout << "The multiplication took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing 1000x1000 size
    cout << "Testing A[1000][1000]*B[1000][1000]" << endl;
    A_rows = 1000;
    A_cols = 1000;
    B_rows = 1000;
    B_cols = 1000;
    // Array of pointers
    A = new int*[A_rows];
    for (int i = 0; i < A_rows; i++)
    {
        A[i] = new int[A_cols];
    }
    B = new int*[B_rows];
    for (int i = 0; i < B_rows; i++)
    {
        B[i] = new int[B_cols];
    }
    initialize_matrix(A, A_rows, A_cols);
    initialize_matrix(B, B_rows, B_cols);
    C = new int*[A_rows];
    for (int i = 0; i < A_rows; i++)
    {
        C[i] = new int [B_cols];
    }
    start = std::chrono::system_clock::now();
    regular_multiplication(C, A, B, A_rows, A_cols, B_rows, B_cols);
    end = std::chrono::system_clock::now();
     elapsed = end - start;
    std::cout.precision(7);
    cout << "The multiplication took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing 1000x1000 size
    cout << "Testing A[2000][500]*B[500][2000]" << endl;
    A_rows = 2000;
    A_cols = 500;
    B_rows = 500;
    B_cols = 2000;
    // Array of pointers
    A = new int*[A_rows];
    for (int i = 0; i < A_rows; i++)
    {
        A[i] = new int[A_cols];
    }
    B = new int*[B_rows];
    for (int i = 0; i < B_rows; i++)
    {
        B[i] = new int[B_cols];
    }
    initialize_matrix(A, A_rows, A_cols);
    initialize_matrix(B, B_rows, B_cols);
    C = new int*[A_rows];
    for (int i = 0; i < A_rows; i++)
    {
        C[i] = new int [B_cols];
    }
    start = std::chrono::system_clock::now();
    regular_multiplication(C, A, B, A_rows, A_cols, B_rows, B_cols);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The multiplication took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    cout << "**************Testing matrix multiplication with space locality **************" << endl;
    cout << "Testing A[100][100]*B[100][100]" << endl;
    // Initialize number of rows and columns to be tested. Start with square matrices
    A_rows = 100;
    A_cols = 100;
    B_rows = 100;
    B_cols = 100;
    // Array of pointers
    A = new int*[A_rows];
    for (int i = 0; i < A_rows; i++)
    {
        A[i] = new int[A_cols];
    }
    B = new int*[B_rows];
    for (int i = 0; i < B_rows; i++)
    {
        B[i] = new int[B_cols];
    }
    initialize_matrix(A, A_rows, A_cols);
    initialize_matrix(B, B_rows, B_cols);
    C = new int*[A_rows];
    for (int i = 0; i < A_rows; i++)
    {
        C[i] = new int [B_cols];
    }
    start = std::chrono::system_clock::now();
    mult_with_space_locality(C, A, B, A_rows, A_cols, B_rows, B_cols);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The multiplication took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing 1000x1000 size
    cout << "Testing A[1000][1000]*B[1000][1000]" << endl;
    A_rows = 1000;
    A_cols = 1000;
    B_rows = 1000;
    B_cols = 1000;
    // Array of pointers
    A = new int*[A_rows];
    for (int i = 0; i < A_rows; i++)
    {
        A[i] = new int[A_cols];
    }
    B = new int*[B_rows];
    for (int i = 0; i < B_rows; i++)
    {
        B[i] = new int[B_cols];
    }
    initialize_matrix(A, A_rows, A_cols);
    initialize_matrix(B, B_rows, B_cols);
    C = new int*[A_rows];
    for (int i = 0; i < A_rows; i++)
    {
        C[i] = new int [B_cols];
    }
    start = std::chrono::system_clock::now();
    mult_with_space_locality(C, A, B, A_rows, A_cols, B_rows, B_cols);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The multiplication took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing 1000x1000 size
    cout << "Testing A[2000][500]*B[500][2000]" << endl;
    A_rows = 2000;
    A_cols = 500;
    B_rows = 500;
    B_cols = 2000;
    // Array of pointers
    A = new int*[A_rows];
    for (int i = 0; i < A_rows; i++)
    {
        A[i] = new int[A_cols];
    }
    B = new int*[B_rows];
    for (int i = 0; i < B_rows; i++)
    {
        B[i] = new int[B_cols];
    }
    initialize_matrix(A, A_rows, A_cols);
    initialize_matrix(B, B_rows, B_cols);
    C = new int*[A_rows];
    for (int i = 0; i < A_rows; i++)
    {
        C[i] = new int [B_cols];
    }
    start = std::chrono::system_clock::now();
    mult_with_space_locality(C, A, B, A_rows, A_cols, B_rows, B_cols);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The multiplication took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
}