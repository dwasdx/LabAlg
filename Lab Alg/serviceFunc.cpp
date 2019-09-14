//
//  _serviceFunc.cpp
//  Lab Alg
//
//  Created by Андрей Журавлев on 14/09/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include "serviceFunc.hpp"

#include <iostream>
using namespace std;


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
