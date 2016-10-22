//
// Created by Terence on 10/21/16.
//

#ifndef TSP2D_UTIL_H
#define TSP2D_UTIL_H

#endif //TSP2D_UTIL_H
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
struct point {
    double x;
    double y;
};
double dist(point a1,point a2);
void calcdistancem(vector<vector<int> > &dis,point s[], int size);
void calcnearneighbor(vector<vector<int> > &nearneibor, vector<vector<int> > &dis);
double evellength(vector<vector<int> > dis,vector<int> tour);
void printtour(vector<int> tour);
