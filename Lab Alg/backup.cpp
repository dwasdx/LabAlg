//
//  backup.cpp
//  Lab Alg
//
//  Created by Андрей Журавлев on 15/09/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//


#include "sortingAlg.cpp"
using namespace std;

void insertionSort(vector<float>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        float temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void timSort(vector<float>& arr, int left, int right) {
    for (int i = 0; i < arr.size(); i += 32)
        insertionSort(arr, i, i + 31 < arr.size() - 1 ? i + 31 : arr.size() - 1);
    
    for (int size = 32; size < arr.size(); size *= 2)
        for (int left = 0; left < arr.size(); left += 2 * size) {
            
            int right = left + 2 * size - 1 < arr.size() - 1 ? left + 2 * size - 1 : arr.size() - 1;
            int medium = (left + right) / 2;
            mergeTim(arr, left, medium, right);
        }
}

void mergeTim(vector<float>& arr, int left, int medium, int right) {
    const int len1 = medium - left + 1,
    //    len2 = abs(right - medium);
    len2 = right - medium;
    vector<float> leftArr(len1), rightArr(len2);
    for (int i = 0; i < len1; i++ )
        leftArr[i] = arr[1 + i];
    for (int i = 0; i < len2; i++)
        rightArr[i] = arr[medium + 1 + i];
    int i = 0, j = 0, k = 1;
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
