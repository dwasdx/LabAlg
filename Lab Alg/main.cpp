//
//  main.cpp
//  Lab Alg
//
//  Created by Андрей Журавлев on 14/09/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include <iostream>
#include "sortingAlg.hpp"
#include <random>
#include <ctime>
//#include "serviceFunc.cpp"

using namespace std;


int main(int argc, const char * argv[]) {
    srand(time(NULL));
    vector<float> arr, arr2;
    for (int i = 0; i < 1000; i++)
        arr.push_back((static_cast<float>(rand() / static_cast<float>(RAND_MAX))) * 100);
    for (int i = 0; i < 4; i++)
        arr2.push_back((static_cast<float>(rand() / static_cast<float>(RAND_MAX))) * 10);
    cout << "Unserted array 1" << endl;
//    printArr(arr);
//    cout << "Unsorted array 2" << endl;
//    printArr(arr2);
    auto timeBegin = clock();
    timSort(arr);
//    selectionSort(arr);
    auto timeEnd = clock();
    cout << "Sorted array 1" << endl;
    printArr(arr);
    cout << "For " << timeEnd - timeBegin << endl;
    
    
}
