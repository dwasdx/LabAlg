//
//  benchmarks.hpp
//  Lab Alg
//
//  Created by Андрей Журавлев on 19/09/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#ifndef benchmarks_hpp
#define benchmarks_hpp
#include "sortingAlg.hpp"

using namespace std;

vector<long> selectionBench();
vector<long> mergeBench();
vector<long> bucketBench();
vector<long> quickRandBench();
vector<long> quickWorstBench();
vector<long> timBench();
vector<float> fillArray(int size);

#endif /* benchmarks_hpp */
