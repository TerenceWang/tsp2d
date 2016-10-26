//
// Created by Terence on 10/21/16.
//

#ifndef TSP2D_SAALG_H
#define TSP2D_SAALG_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <deque>
using namespace std;


class SAalg {


private:
    int pointnumber;
    vector<vector<int> >dis,nearnb;
    deque<int> path;
    deque<int> pathbest;
    void copypath(deque<int> &v1, deque<int> &v2);
    void exchangefornewpath(deque<int>& newpath, deque<int> &oldpath);

public:

    SAalg(int size,vector<vector<int> >distance,vector<vector<int> > nearnb);
    ~SAalg();
    void doSA(deque<int> *tour);
    void initpath();


};


#endif //TSP2D_SAALG_H
