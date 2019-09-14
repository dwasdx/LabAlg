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

vector<float> selectionSort(vector<float> arr);
vector<float> bucketSort(vector<float> arr);
void mergeSort(vector<float>& arr);
vector<float> quickSort(vector<float> arr);
vector<float> timSort(vector<float> arr, int left, int right);

void printArr(vector<float> arr);
float searchMin(vector<float> arr);
float searchMax(vector<float> arr);
void merge(vector<float>& arr, int left, int medium, int right);



#endif /* sortingAlg_hpp */
