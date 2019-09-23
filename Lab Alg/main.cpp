//
//  main.cpp
//  Lab Alg
//
//  Created by Андрей Журавлев on 14/09/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include <iostream>
#include <random>
#include "benchmarks.hpp"

//#include "serviceFunc.cpp"

using namespace std;



int main(int argc, const char * argv[]) {
    srand(time(NULL));
//    vector<long> timesSel = selectionBench();
//    vector<long> timesMerge = mergeBench();
//    vector<long> timesBucket = bucketBench();
//    vector<long> timesQuickRand = quickRandBench();
//    vector<long> timesQuickWorst = quickWorstBench();
//    vector<long> timesTim = timBench();
    vector<float> arr = fillArray(10);
    printArr(arr);
    quickSortRandom(arr, 0, arr.size() - 1);
    printArr(arr);
    return 0;
//    getTimeSort(arr);
//    auto time = clock();
//    quickSortRandom(arr, 0, arr.size() - 1);
//    cout << clock() - time << endl;
//    printArr(arr);
    
}
