//
// Created by Terence on 10/21/16.
//

#ifndef TSP2D_TWOOPT_H
#define TSP2D_TWOOPT_H

#include <vector>
#include <iostream>
#include <random>
#include "Greedy.h"
#include "grtdm.h"

using namespace std;

class twoopt {
private:
    void initpath();
    void exchangefornewpath();
    void TwoOptSwap( const int& i, const int& k );
    int pointnumber;
    vector<vector<int> >dis,nearnb;
    vector<double > pi;
    deque<int> path,newpath,index;

public:
    twoopt(int size,vector<vector<int> >distance,vector<vector<int> >nearnb,vector<double> pi);
    ~twoopt();
    void doTwoOpt(deque<int> *tour, double begin);
    void doTwoOptHer(deque<int> *tour, double begin);
};


#endif //TSP2D_TWOOPT_H
