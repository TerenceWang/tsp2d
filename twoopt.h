//
// Created by Terence on 10/21/16.
//

#ifndef TSP2D_TWOOPT_H
#define TSP2D_TWOOPT_H

#include <vector>
#include <iostream>
#include "Greedy.h"

using namespace std;

class twoopt {
private:
    void initpath();
    void TwoOptSwap( const int& i, const int& k );
    int pointnumber;
    vector<vector<int> >dis,nearnb;

    vector<int> path;
    vector<int> newpath;

public:
    twoopt(int size,vector<vector<int> >distance,vector<vector<int> >nearnb);
    ~twoopt();
    void doTwoOpt(vector<int> *tour, double begin);

};


#endif //TSP2D_TWOOPT_H
