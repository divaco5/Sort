//
// Created by hisumi on 2018/04/28.
//
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

#ifndef SORT_SORT_H
#define SORT_SORT_H

void heapify(vector<int> &input_arr, int arr_size, int i);
void heapSort(vector<int> &input_arr, int arr_size);

void quickSort(vector<int> &input_arr, int first, int last);
void margeSort(vector<int> &input_arr, int first, int last);

void printArray(vector<int> &input_arr, int arr_size);

#endif //SORT_SORT_H
