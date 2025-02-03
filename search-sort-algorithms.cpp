/*
Linear Search – A simple search algorithm that checks each element one by one until the target element is found or the array ends.

Binary Search – An efficient search algorithm that works on sorted arrays by repeatedly dividing the search interval in half.

Bubble Sort – A sorting algorithm that repeatedly swaps adjacent elements if they are in the wrong order until the array is sorted.

Selection Sort – A sorting algorithm that repeatedly finds the smallest element from the unsorted part and swaps it with the first unsorted element.

Insertion Sort – A sorting algorithm that builds a sorted array by inserting each new element into its correct position.



 */


#include <iostream>
using namespace std;

// Linear Search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search (works on sorted arrays)
int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Helper function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, size);
    
    // Sorting example
    selectionSort(arr, size);
    cout << "Sorted array (Selection Sort): ";
    printArray(arr, size);
    
    // Searching example
    int key = 22;
    int result = binarySearch(arr, size, key);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;
    
    return 0;
}
