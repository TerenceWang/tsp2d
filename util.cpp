//
// Created by Terence on 10/21/16.
//
#include "util.h"
using namespace std;


int dist(point a1,point a2){
    int result=0;
    result=round(sqrt(pow(a1.x-a2.x,2)+pow(a1.y-a2.y,2)));
    return result;
}

void calcdistancem(vector<vector<int> > &dis,point s[], int size){

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(i==j)
                dis[i][j]=0;
            else {
                if(dis[i][j]<0) {
                    dis[i][j] = dist(s[i], s[j]);
                    dis[j][i] = dis[i][j];
                }
            }
        }
    }
}

void calcnearneighbor(vector<vector<int> > &nearneibor, vector<vector<int> > &dis){
    int size=dis[0].size();
    for (int i = 0; i < size; ++i) {
        sort(nearneibor[i].begin(),nearneibor[i].end(),[&i,&dis](const int &a, const int &b)->bool{
            return dis[i][a] < dis[i][b];
        });

    }
}

int evellength(vector<vector<int> > dis,deque<int> tour){
    int result=0;
    int size=tour.size();
    for (int i = 0; i < size-1; ++i) {
        result+=dis[tour[i]][tour[i+1]];
    }
    result+=dis[tour[size-1]][tour[0]];

    return result;
}
void printtour(deque<int> tour){
        for (auto i : tour) {
            cout << i << endl;
        }
}