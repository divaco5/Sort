#include <iostream>
#include<algorithm>
#include<vector>
#include "sort.h"
using namespace std;

int main() {
    std::cout << "this is Sort algorithm" << std::endl;
    vector<int> arr         = { 28, 43, 1, -32, 5, -77, 10, 5, 37, 88, 1000, 22, 15, 6, 79 };
    vector<int> input_arr   = arr;

    int arr_size    = arr.size();
    int arr_first   = 0;
    int arr_last    = arr_size;

    cout << "array is";
    printArray(input_arr,arr_size);

    heapSort(input_arr,arr_size);
    cout << "HeapSort:Sorted array is";
    printArray(input_arr,arr_size);

    input_arr = arr;
    quickSort(input_arr,arr_first, arr_last);
    cout << "HeapSort:Sorted array is";
    printArray(input_arr,arr_size);

    input_arr = arr;
    margeSort(input_arr,arr_first, arr_last);
    cout << "HeapSort:Sorted array is";
    printArray(input_arr,arr_size);

    return 0;
}