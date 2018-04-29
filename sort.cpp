//
// Created by hisumi on 2018/04/28.
//
#include "sort.h"

//配列input_arrのheap条件を保持する
//heap条件：1_接点の値はその親の値以下, 2_ヒープの最大要素は根に格納される
void heapify(vector<int> &input_arr, int arr_size, int i)
{
    int largest = i;
    int left    = 2 * i + 1;
    int right   = 2 * i + 2;


    if(left < arr_size && input_arr[left] > input_arr[largest])
        largest = left;

    if(right < arr_size && input_arr[right] > input_arr[largest])
        largest = right;

    //largestより大きい値が見つかったら入れ替える
    if(largest != i)
    {
        swap(input_arr[i], input_arr[largest]);
        heapify(input_arr, arr_size, largest);
    }
}


//配列input_arrをHeapSortする
//HeapSort:リストの並べ替えを二分ヒープ木を用いて行うソートのアルゴリズム
void heapSort(vector<int> &input_arr, int arr_size)
{
    int top_node = arr_size / 2 - 1;

    for(int i = top_node; i >= 0; i--)
        heapify(input_arr, arr_size, i);

    for(int i = arr_size-1; i>=0; i--){
        swap(input_arr[0], input_arr[i]);
        heapify(input_arr, i, 0);
    }
}


//配列input_arrをQuickSortする
//QuickSort:リストにおいてピボットと呼ぶ要素を軸に分割を繰り返して整列を行うアルゴリズム
void quickSort(vector<int> &input_arr, int first, int last)
{
    if (last - first <= 1) return;

    //pivotの設定
    int pivot_index = (first + last) / 2;
    int pivot = input_arr[pivot_index];

    //pivotと右端を入れ替える
    swap(input_arr[pivot_index], input_arr[last - 1]);

    //target < pivot:入れ替え、　target > pivot:何もしない
    int i_first = first;
    for (int j_first = first; j_first < last - 1; ++j_first) {
        if (input_arr[j_first] < pivot) {
            swap(input_arr[i_first++], input_arr[j_first]);
        }
    }

    //pivotの値をinput_arr[i_first]に戻す
    swap(input_arr[i_first], input_arr[last - 1]);

    //再帰的に解いていく
    quickSort(input_arr, first, i_first);
    quickSort(input_arr, i_first + 1, last);
    return;
}


//配列　input_arrをMargeSortする
//margeSort:あらかじめ整列してある2つの配列を合体させて、新しい、整列された配列を得るアルゴリズム
void margeSort(vector<int> &input_arr, int first, int last)
{
    if (last - first == 1) return;

    int middle = (first + last) / 2; //配列の中央を求める

    //左半分[left,middle)をソートする
    margeSort(input_arr, first, middle);
    //右半分(middle,right)をソートする
    margeSort(input_arr, middle, last);

    vector<int> marge_arr;
    //左半分はそのまま
    for (int i_first = first; i_first < middle; i_first++)
        marge_arr.push_back(input_arr[i_first]);

    //右半分は反転する
    for (int i_last = last - 1; i_last >= middle; --i_last)
        marge_arr.push_back(input_arr[i_last]);

    //マージする
    int i_first = 0;
    int i_last = (int)marge_arr.size() - 1;

    for (int i_marge = first; i_marge < last; ++i_marge) {
        //左側採用
        if (marge_arr[i_first] <= marge_arr[i_last])
            input_arr[i_marge] = marge_arr[i_first++];
        //右側採用
        else
            input_arr[i_marge] = marge_arr[i_last--];
    }

    return;
}


void printArray(vector<int> &input_arr, int arr_size)
{
    for(int i = 0; i < arr_size; i++)
        cout << input_arr[i] << " ";
    cout << std::endl;

}