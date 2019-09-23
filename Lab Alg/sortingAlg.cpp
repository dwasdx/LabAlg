//
//  sortingAlg.cpp
//  Lab Alg
//
//  Created by Андрей Журавлев on 14/09/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include "sortingAlg.hpp"
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;
//int RUN = 32;
//Selection Sort
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

//Bucket Sort
void bucketSort(vector<float>& arr) {
//    int range = (int)(searchMax(arr) - searchMin(arr)) + 1;
    vector<float> bucket[arr.size()];
    auto maxElem = max_element(arr.begin(), arr.end());
    
    for (int i = 0; i < arr.size(); i++)
        bucket[int(arr.size() * arr[i] / *maxElem - 1)].push_back(arr[i]);
    
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

//Merge Sort
void mergeSort(vector<float>& arr) {
    mergeSortAction(arr, 0, (int)arr.size());
}

void mergeSortAction(vector<float>& arr, int left, int right) {
    if (left + 1 >= right)
        return;
    int medium = (left + right) / 2;
    mergeSortAction(arr, left, medium);
    mergeSortAction(arr, medium, right);
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

//Quick Sort
void quickSortRandom(vector<float>& arr) {
    quickSortRandomAction(arr, 0, (int)arr.size() - 1);
}

void quickSortWorst(vector<float>& arr) {
    quickSortWorstAction(arr, 0, (int)arr.size() - 1);
}

void quickSortRandomAction(vector<float>& arr, int left, int right) {
    if (left < right) {
        int partitionIndex = quickSortPartitionRandom(arr, left, right);
        quickSortRandomAction(arr, left, partitionIndex - 1);
        quickSortRandomAction(arr, partitionIndex + 1, right);
    }
}

void quickSortWorstAction(vector<float>& arr, int left, int right) {
    if (left < right) {
        int partitionIndex = quickSortPartitionWorst(arr, left, right);
        quickSortWorstAction(arr, left, partitionIndex - 1);
        quickSortWorstAction(arr, partitionIndex + 1, right);
    }
}

int quickSortPartitionRandom(vector<float>& arr, int left, int right) {
    int randIndex = (rand() % (right - left + 1)) + left;
    swap(arr[left], arr[randIndex]);
    float pivot = arr[left];
    int leftmark = left + 1;
    int rightmark = right;
    bool flag = false;
    while (!flag) {
        while (arr[leftmark] <= pivot && leftmark <= rightmark)
            leftmark++;
        while (pivot <= arr[rightmark] && leftmark <= rightmark)
            rightmark--;
        if (rightmark < leftmark)
            flag = true;
        else
            swap(arr[leftmark], arr[rightmark]);
    }
    swap(arr[left], arr[rightmark]);
    return rightmark;
}

int quickSortPartitionWorst(vector<float>& arr, int left, int right) {
//    float minInd = searchMinForSort(arr, left, right);
//    swap(arr[left], arr[minInd]);
    auto minInd = min_element(arr.begin() + left, arr.begin() + right);
    swap(*(arr.begin() + left), *minInd);
    float pivot = arr[left];
    int leftmark = left + 1;
    int rightmark = right;
    bool flag = false;
    while (!flag) {
        while (arr[leftmark] <= pivot && leftmark <= rightmark)
            leftmark++;
        while (pivot <= arr[rightmark] && leftmark <= rightmark)
            rightmark--;
        if (rightmark < leftmark)
            flag = true;
        else
            swap(arr[leftmark], arr[rightmark]);
    }
    swap(arr[left], arr[rightmark]);
    return rightmark;
}

//Tim Sort
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

void timSort(vector<float>& arr) {
    for (int i = 0; i < arr.size(); i += 32)
        insertionSort(arr, i, min(i + 31, (int)arr.size() - 1));

    for (int size = 32; size < arr.size(); size *= 2)
        for (int left = 0; left < arr.size(); left += 2 * size) {
            int medium = min(left + size - 1, int(arr.size()) - 1);
            int right = min(left + 2 * size - 1, (int)arr.size() - 1);
            mergeTim(arr, left, medium, right);
        }
}

void mergeTim(vector<float>& arr, int left, int medium, int right) {
    int len1 = medium - left + 1,
    len2 = right - medium;
    vector<float> leftArr(len1), rightArr(len2);
    for (int i = 0; i < len1; i++ )
        leftArr[i] = arr[left + i];
    for (int i = 0; i < len2; i++)
        rightArr[i] = arr[medium + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < len2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}



//=============================================

void printArr(vector<float> arr) {
    for (auto i = arr.begin(); i != arr.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void printArr(vector<long> arr) {
    for (auto i = arr.begin(); i != arr.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void getTimeSort(vector<float>& arr) {
    vector<float> arrCopy = arr;
    cout << "Selection sort for ";
    auto timeBegin = clock();
    selectionSort(arrCopy);
    cout << clock() - timeBegin << endl;
    
    arrCopy = arr;
    cout << "Merge sort for ";
    timeBegin = clock();
    mergeSort(arrCopy);
    cout << clock() - timeBegin << endl;
    
    arrCopy = arr;
    cout << "Bucket sort for ";
    timeBegin = clock();
    bucketSort(arr);
    cout << clock() - timeBegin << endl;
    
    arrCopy = arr;
    cout << "Quick sort random for ";
    timeBegin = clock();
    quickSortRandom(arrCopy);
    cout << clock() - timeBegin << endl;
    
    arrCopy = arr;
    cout << "Quick sort worst for ";
    timeBegin = clock();
    quickSortWorst(arrCopy);
    cout << clock() - timeBegin << endl;
    
    arrCopy = arr;
    cout << "Tim sort for ";
    timeBegin = clock();
    timSort(arr);
    cout << clock() - timeBegin << endl;
}


