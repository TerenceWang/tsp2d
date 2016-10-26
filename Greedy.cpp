//
// Created by Terence on 10/21/16.
//

#include "Greedy.h"


void greedynaive(vector<vector<int> >dis,vector<vector<int> >nearnb, deque<int> *tour) {

    int size=tour[0].size();
    int used[size];

    memset(used,0,size*sizeof(int));
    uniform_int_distribution<int> dist(0, size-1);
    random_device rd;
//    int startpoint=dist(rd);
    int startpoint = 0;
    tour[0][0]=startpoint;
    used[startpoint]=1;

    for (int i = 1; i < size; ++i) {
        int best=-1;
        int cost=2147483647;
        for (int j = 0; j < size; ++j) {
            if (used[nearnb[tour[0][i-1]][j]]==1||tour[0][i-1]==nearnb[tour[0][i-1]][j])
                continue;
            int distance=dis[tour[0][i-1]][nearnb[tour[0][i-1]][j]];
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
