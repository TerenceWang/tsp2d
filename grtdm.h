//
// Created by Terence on 10/25/16.
//

#ifndef TSP2D_GRTDM_H
#define TSP2D_GRTDM_H

#include "util.h"
using namespace std;

void greedytdm(vector<vector<int> > dis,vector<vector<int> > nearnb, vector<double > pi,deque<int>* tour);
#endif //TSP2D_GRTDM_H
