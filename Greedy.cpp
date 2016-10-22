//
// Created by Terence on 10/21/16.
//

#include "Greedy.h"


void greedynaive(vector<vector<int> >dis,vector<vector<int> >nearnb, vector<int> *tour) {

    int size=tour[0].size();
    int used[size];

    memset(used,0,size*sizeof(int));

    tour[0][0]=0;
    used[0]=1;
    for (int i = 1; i < size; ++i) {
        int best=-1;
        double cost=2147483647;
        for (int j = 0; j < size; ++j) {
            if (used[nearnb[tour[0][i-1]][j]]==1||tour[0][i-1]==nearnb[tour[0][i-1]][j])
                continue;
            double distance=dis[tour[0][i-1]][nearnb[tour[0][i-1]][j]];
            if(best==-1||distance<cost){
                best=nearnb[tour[0][i-1]][j];
                cost=distance;
            }
            else if(distance>cost)
                break;
        }
        tour[0][i]=best;
        used[best]=1;
    }
}
