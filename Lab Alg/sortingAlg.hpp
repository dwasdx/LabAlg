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
void quickSort(vector<float>& arr);
void timSort(vector<float>& arr, int left, int right);

void printArr(vector<float> arr);
float searchMin(vector<float> arr);
float searchMax(vector<float> arr);
void merge(vector<float>& arr, int left, int medium, int right);



#endif /* sortingAlg_hpp */
