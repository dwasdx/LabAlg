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
//#include "serviceFunc.cpp"

using namespace std;


int main(int argc, const char * argv[]) {
    srand(time(NULL));
    vector<float> arr;
    for (int i = 0; i < 10; i++)
        arr.push_back((static_cast<float>(rand() / static_cast<float>(RAND_MAX))) * 10);
    printArr(arr);
//    mergeSort(arr);
    mergeSort(arr);
    printArr(arr);
    
}
