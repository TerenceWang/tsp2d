//
// Created by Terence on 10/21/16.
//

#ifndef TSP2D_GREEDY_H
#define TSP2D_GREEDY_H

#include <iostream>
#include <cmath>

#include <cstring>
#include <vector>
#include <random>
#include <deque>
#include <algorithm>
using namespace std;

void greedynaive(vector<vector<int> > dis,vector<vector<int> > nearnb, deque<int>* tour);


#endif //TSP2D_GREEDY_H
