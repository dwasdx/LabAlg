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

void printArr(vector<float> arr) {
    for (auto i = arr.begin(); i != arr.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
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

