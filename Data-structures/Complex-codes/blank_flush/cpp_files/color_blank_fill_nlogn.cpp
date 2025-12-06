//
// Created by sahil on 6/10/25.
//
#include <iostream>
using namespace std;

// Merge Sort Implementation
void merge(char* colors, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    char* leftArr = new char[n1];
    char* rightArr = new char[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = colors[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = colors[mid + 1 + j];

    // Merge the temp arrays back
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] == '-') {
            colors[k] = leftArr[i];
            i++;
        } else {
            colors[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1) {
        colors[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        colors[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(char* colors, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(colors, left, mid);
        mergeSort(colors, mid + 1, right);
        merge(colors, left, mid, right);
    }
}

// Quick Sort Implementation
/*int partition(char* colors, int low, int high) {
    char pivot = colors[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (colors[j] <= pivot) {
            i++;
            swap(colors[i], colors[j]);
        }
    }
    swap(colors[i + 1], colors[high]);
    return i + 1;
}

void quickSort(int colors[], int low, int high) {
    if (low < high) {
        int pi = partition(colors, low, high);

        quickSort(colors, low, pi - 1);
        quickSort(colors, pi + 1, high);
    }
}

// Print array function
void printArray(int colors[], int size) {
    for (int i = 0; i < size; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;
}*/
/*int main() {
    int size = 8;
    int colors[] = {64, 34, 25, 12, 22, 11, 90, 5};

    cout << "Original array: ";
    printArray(colors, size);

    // Test Merge Sort
    int colorsCopy1[8];
    for (int i = 0; i < size; i++) {
        colorsCopy1[i] = colors[i];
    }

    mergeSort(colorsCopy1, 0, size - 1);
    cout << "Merge Sort result: ";
    printArray(colorsCopy1, size);

    // Test Quick Sort
    int colorsCopy2[8];
    for (int i = 0; i < size; i++) {
        colorsCopy2[i] = colors[i];
    }

    quickSort(colorsCopy2, 0, size - 1);
    cout << "Quick Sort result: ";
    printArray(colorsCopy2, size);

    return 0;
}*/