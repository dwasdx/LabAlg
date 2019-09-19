//
//  sortingAlg.cpp
//  Lab Alg
//
//  Created by Андрей Журавлев on 14/09/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include "sortingAlg.hpp"
#include <iostream>
#include <random>
#include <algorithm>
using namespace std;
int RUN = 32;

void selectionSort(vector<float>& arr) {
    if (arr.size() == 0)
        return;
    
    for (int i = 0; i < arr.size() - 1; i++) {
        int indexOfMin = i;
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[j] < arr[indexOfMin])
                indexOfMin = j;
        float temp = arr[indexOfMin];
        arr[indexOfMin] = arr[i];
        arr[i] = temp;
    }
//    return arr;
}

void bucketSort(vector<float>& arr) {
//    int range = (int)(searchMax(arr) - searchMin(arr)) + 1;
    vector<float> bucket[arr.size()];
    float maxElem = searchMax(arr);
    
    for (int i = 0; i < arr.size(); i++) {
//        int a = (int)(arr.size() * arr[i] / maxElem - 1);
        bucket[int(arr.size() * arr[i] / maxElem - 1)].push_back(arr[i]);
        
    }
    
    for (int i = 0; i < arr.size(); i++)
        selectionSort(bucket[i]);
    
    int index = 0;
    for (int i = 0; i < arr.size(); i++) {
        while (!bucket[i].empty()) {
            arr[index++] = *(bucket[i].begin());
            bucket[i].erase(bucket[i].begin());
        }
    }
    return;
}

void mergeSort(vector<float>& arr, int left, int right) {
    if (left + 1 >= right)
        return;
    int medium = (left + right) / 2;
    mergeSort(arr, left, medium);
    mergeSort(arr, medium, right);
    merge(arr, left, medium, right);
}

void merge(vector<float>& arr, int left, int medium, int right) {
    int iterationLeft = 0, iterationRight = 0;
    vector<float> result(right - left);
    
    while (left + iterationLeft < medium && medium + iterationRight < right) {
        if (arr[left + iterationLeft] < arr[medium + iterationRight]) {
            result[iterationLeft + iterationRight] = arr[left + iterationLeft];
            iterationLeft++;
        } else {
            result[iterationLeft + iterationRight] = arr[medium + iterationRight];
            iterationRight++;
        }
    }
    
    while (left + iterationLeft < medium) {
            result[iterationLeft + iterationRight] = arr[left + iterationLeft];
            iterationLeft++;
    }
    
    while (medium + iterationRight < right) {
            result[iterationLeft + iterationRight] = arr[medium + iterationRight];
            iterationRight++;
    }
    
    for (int i = 0; i < iterationLeft + iterationRight; i++) {
        arr[left + i] = result[i];
    }
}

void quickSortRandom(vector<float>& arr, int left, int right) {
    if (left < right) {
        int partitionIndex = quickSortPartitionRandom(arr, left, right);
        quickSortRandom(arr, left, partitionIndex - 1);
        quickSortRandom(arr, partitionIndex + 1, right);
    }
}

void quickSortWorst(vector<float>& arr, int left, int right) {
    if (left < right) {
        int partitionIndex = quickSortPartitionWorst(arr, left, right);
        quickSortWorst(arr, left, partitionIndex - 1);
        quickSortWorst(arr, partitionIndex + 1, right);
    }
}

int quickSortPartitionRandom(vector<float>& arr, int left, int right) {
    float pivot = arr[left];
    int leftmark = left + 1;
    int rightmark = right;
    bool flag = false;
    while (!flag) {
        while (arr[leftmark] <= pivot && leftmark <= rightmark)
            leftmark++;
        while (pivot <= arr[rightmark] && leftmark <= rightmark)
            rightmark--;
        if (rightmark < leftmark) {
            flag = true;
        } else {
            float temp = arr[leftmark];
            arr[leftmark] = arr[rightmark];
            arr[rightmark] = temp;
        }
    }
    float temp = arr[left];
    arr[left] = arr[rightmark];
    arr[rightmark] = temp;
    return rightmark;
}

int quickSortPartitionWorst(vector<float>& arr, int left, int right) {
    float pivot = searchMinForSort(arr, left, right);
    int leftmark = left + 1;
    int rightmark = right;
    bool flag = false;
    while (!flag) {
        while (arr[leftmark] <= pivot && leftmark <= rightmark)
            leftmark++;
        while (pivot <= arr[rightmark] && leftmark <= rightmark)
            rightmark--;
        if (rightmark < leftmark) {
            flag = true;
        } else {
            float temp = arr[leftmark];
            arr[leftmark] = arr[rightmark];
            arr[rightmark] = temp;
        }
    }
    float temp = arr[left];
    arr[left] = arr[rightmark];
    arr[rightmark] = temp;
    return rightmark;
}

void insertionSort(vector<float>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        float temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

//void timSort(vector<float>& arr) {
//    for (int i = 0; i < arr.size(); i += 32)
//        insertionSort(arr, i, min(i + 31, (int)arr.size() - 1));
//
//    for (int size = 32; size < arr.size(); size *= 2)
//        for (int left = 0; left < arr.size(); left += 2 * size) {
//            int right = min(left + 2 * size - 1, (int)arr.size() - 1);
//            int medium = min(left + size - 1, int(arr.size()) - 1);
//            mergeTim(arr, left, medium, right);
//        }
//}
//
//void mergeTim(vector<float>& arr, int left, int medium, int right) {
//    int len1 = medium - left + 1,
//    len2 = right - medium;
//    vector<float> leftArr(len1), rightArr(len2);
//    for (int i = 0; i < len1; i++ )
//        leftArr[i] = arr[left + i];
//    for (int i = 0; i < len2; i++)
//        rightArr[i] = arr[medium + 1 + i];
//
//    int i = 0, j = 0, k = left;
//
//    while (i < len1 && j < len2) {
//        if (leftArr[i] < rightArr[j]) {
//            arr[k] = leftArr[i];
//            i++;
//        } else if (leftArr[i] > rightArr[j]) {
//            arr[k] = rightArr[j];
//            j++;
//        } else {
//            arr[k] = leftArr[i];
//            i++;
//            k++;
//            arr[k] = rightArr[j];
//            k++;
//            j++;
//        }
//        k++;
//    }
//    while (i < len1) {
//        arr[k] = leftArr[i];
//        i++;
//        k++;
//    }
//    while (j < len2) {
//        arr[k] = rightArr[j];
//        j++;
//        k++;
//    }
//}


void mergeTim(std::vector<float>& arr, long long l, long long m, long long r)
{
    // original array is broken in two parts
    // left and right array
    long long len1 = m - l + 1, len2 = r - m;
    std::vector<float> left(len1), right(len2);
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
    long long i = 0;
    long long j = 0;
    long long k = l;
    // after comparing, we merge those two array
    // in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    // copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}
// iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void timSort(std::vector<float>& arr)
{
    //                                                      goto zaloopa;
    // Sort individual subarrays of size RUN
    long long n=arr.size();
    for (long long i = 0; i < n; i+=RUN)
        insertionSort(arr, i, std::min((i+31), (n-1)));
    // start merging from size RUN (or 32). It will merge
    // to form size 64, then 128, 256 and so on ....
    for (long long size = RUN; size < n; size = 2*size)
    {
        // pick starting point of left sub array. We
        // are going to merge arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we increase left by 2*size
        for (long long left = 0; left < n; left += 2*size)
        {
            // find ending point of left sub array
            // mid+1 is starting point of right sub array
            long long mid = std::min((left + size - 1), (n-1));
            long long right = std::min((left + 2*size - 1), (n-1));
            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            mergeTim(arr, left, mid, right);
        }
    }
}


//=============================================

void printArr(vector<float> arr) {
    for (auto i = arr.begin(); i != arr.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

float searchMaxForSort(vector<float> arr, int left, int right) {
    float max = arr[left];
    for (int i = left + 1; i < right; i++)
        max = arr[i] > max ? arr[i] : max;
    return max;
}

float searchMinForSort(vector<float> arr, int left, int right) {
    float min = arr[left];
    for (int i = left + 1; i < right; i++)
        min = arr[i] < min ? arr[i] : min;
    return min;
}

float searchMin(vector<float> arr) {
    float min = arr[0];
    for (auto i = arr.begin() + 1; i != arr.end(); i++)
        min = *i < min ? *i : min;
    return min;
}

float searchMax(vector<float> arr) {
    float max = arr[0];
    for (auto i = arr.begin() + 1; i != arr.end(); i++)
        max = *i > max ? *i : max;
    return max;
}

int getMinrun(int n) {
    int r = 0;
    while (n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return r + n;
}


