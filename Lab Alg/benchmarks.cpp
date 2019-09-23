//
//  benchmarks.cpp
//  Lab Alg
//
//  Created by Андрей Журавлев on 19/09/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include "benchmarks.hpp"
//#include "sortingAlg.hpp"
#include <random>
#include <ctime>
#include <iostream>

using namespace std;
vector<int> sizes = {10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000};

vector<long> selectionBench() {
    vector<long> averageTime;
    for (int size : sizes) {
        long long timeAll = 0;
        for (int i = 0; i < 50; i++) {
            vector<float> arr = fillArray(size);
            auto timeBegin = clock();
            selectionSort(arr);
            timeAll += clock() - timeBegin;
        }
        averageTime.push_back(timeAll / 50);
        cout << "Selection size " << size << " complete" << endl;
    }
    
    return averageTime;
}

vector<long> mergeBench() {
    vector<long> averageTime;
    for (int size : sizes) {
        long long timeAll = 0;
        for (int i = 0; i < 50; i++) {
            vector<float> arr = fillArray(size);
            auto timeBegin = clock();
            mergeSort(arr);
            timeAll += clock() - timeBegin;
        }
        averageTime.push_back(timeAll / 50);
        cout << "Merge sort size " << size << " complete" << endl;
    }
    
    return averageTime;
}

vector<long> bucketBench() {
    vector<long> averageTime;
    for (int size : sizes) {
        long long timeAll = 0;
        for (int i = 0; i < 50; i++) {
            vector<float> arr = fillArray(size);
            auto timeBegin = clock();
            bucketSort(arr);
            timeAll += clock() - timeBegin;
        }
        averageTime.push_back(timeAll / 50);
        cout << "Bucket sort size " << size << " complete" << endl;
    }
    
    return averageTime;
}

vector<long> quickRandBench() {
    vector<long> averageTime;
    for (int size : sizes) {
        long long timeAll = 0;
        for (int i = 0; i < 50; i++) {
            vector<float> arr = fillArray(size);
            auto timeBegin = clock();
            quickSortRandom(arr);
            timeAll += clock() - timeBegin;
        }
        averageTime.push_back(timeAll / 50);
        cout << "Quick sort random size " << size << " complete" << endl;
    }
    
    return averageTime;
}

vector<long> quickWorstBench() {
    vector<long> averageTime;
    for (int size : sizes) {
        long long timeAll = 0;
        for (int i = 0; i < 50; i++) {
            vector<float> arr = fillArray(size);
            auto timeBegin = clock();
            quickSortWorst(arr);
            timeAll += clock() - timeBegin;
        }
        averageTime.push_back(timeAll / 50);
        cout << "Quick sort worst size " << size << " complete" << endl;
    }
    
    return averageTime;
}

vector<long> timBench() {
    vector<long> averageTime;
    for (int size : sizes) {
        long long timeAll = 0;
        for (int i = 0; i < 50; i++) {
            vector<float> arr = fillArray(size);
            auto timeBegin = clock();
            timSort(arr);
            timeAll += clock() - timeBegin;
        }
        averageTime.push_back(timeAll / 50);
        cout << "TIm sort size " << size << " complete" << endl;
    }
    
    return averageTime;
}

vector<float> fillArray(int size) {
    vector<float> arr;
    for (int i = 0; i < size; i++)
        arr.push_back((static_cast<float>(rand() / static_cast<float>(RAND_MAX))) * 100);
    return arr;
}
