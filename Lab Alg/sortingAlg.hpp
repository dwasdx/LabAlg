//
//  sortingAlg.hpp
//  Lab Alg
//
//  Created by Андрей Журавлев on 14/09/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#ifndef sortingAlg_hpp
#define sortingAlg_hpp
//#include "serviceFunc.cpp"
#include <vector>
using namespace std;

void selectionSort(vector<float>& arr);
void bucketSort(vector<float>& arr);
void mergeSort(vector<float>& arr);
void mergeSortAction(vector<float>& arr, int left, int right);
void merge(vector<float>& arr, int left, int medium, int right);
void quickSortRandom(vector<float>& arr);
void quickSortWorst(vector<float>& arr);
void quickSortRandomAction(vector<float>& arr, int left, int right);
void quickSortWorstAction(vector<float>& arr, int left, int right);
int quickSortPartitionRandom(vector<float>& arr, int left, int right);
int quickSortPartitionWorst(vector<float>& arr, int left, int right);
void timSort(vector<float>& arr);
void insertionSort(vector<float>& arr, int left, int right);
void mergeTim(vector<float>& arr, int l, int m, int r);


void printArr(vector<float> arr);
void printArr(vector<long> arr);
void getTimeSort(vector<float>& arr);



#endif /* sortingAlg_hpp */
