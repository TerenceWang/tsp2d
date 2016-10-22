//
// Created by Terence on 10/21/16.
//

#ifndef TSP2D_SAALG_H
#define TSP2D_SAALG_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
using namespace std;


class SAalg {


private:
    int pointnumber;
    vector<vector<int> >dis,nearnb;
    vector<int> path;
    vector<int> pathbest;
    void copypath(vector<int> &v1, vector<int> &v2);
    void exchangefornewpath(vector<int>& newpath, vector<int> &oldpath);

public:

    SAalg(int size,vector<vector<int> >distance,vector<vector<int> > nearnb);
    ~SAalg();
    void doSA(vector<int> *tour);
    void initpath();


};


#endif //TSP2D_SAALG_H
