#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include "sorting_algorithms.h"

using namespace std;
int ARRAY_SIZES[3] = {1000, 100000};
// Arrays where to store information numbers
int *array_size1000 = new int[1000];
int *array_size100000 = new int[100000];


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
        cout << "Currently testing array size: " + to_string(ARRAY_SIZES[i]) << endl;
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
        cout << "Currently testing array size: " + to_string(ARRAY_SIZES[i]) << endl;
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
        cout << "Currently testing array size: " + to_string(ARRAY_SIZES[i]) << endl;
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
        cout << "Currently testing array size: " + to_string(ARRAY_SIZES[i]) << endl;
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


void test_mergesort(){
}

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

void test_quicksort(){

}

void test_bubblesort(){
    cout << "****************Testing Bubblesort Algorithm ****************" << endl;
    cout << "****************Testing Unordered lists with repetition****************" << endl;
    load_data_unordered_with_repetition();
    cout << "Testing Insertion sort with array size 1000" << endl;
    auto start = std::chrono::system_clock::now();
    bubblesort(array_size1000, 1000);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing Insertion sort with array size 100000" << endl;
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
    cout << "Testing Insertion sort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    bubblesort(array_size1000, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing Insertion sort with array size 100000" << endl;
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
    cout << "Testing Insertion sort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    bubblesort(array_size1000, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing Insertion sort with array size 100000" << endl;
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
    cout << "Testing Insertion sort with array size 1000" << endl;
    start = std::chrono::system_clock::now();
    bubblesort(array_size1000, 1000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
    // Testing array size 100000
    cout << "Testing Insertion sort with array size 100000" << endl;
    start = std::chrono::system_clock::now();
    bubblesort(array_size100000, 100000);
    end = std::chrono::system_clock::now();
    elapsed = end - start;
    std::cout.precision(7);
    cout << "The algorithm took: ";
    std::cout << std::fixed <<elapsed.count();
    cout << " seconds" << endl;
}

void test_selectionsort(){
}

void run_test_matrix(string algorithm){

}