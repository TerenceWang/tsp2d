//
// Created by Terence on 10/21/16.
//


#include "SAalg.h"
#include "util.h"
#include "Greedy.h"

SAalg::SAalg(int size, vector<vector<int> > distance,vector<vector<int> > nearnb) {
    pointnumber = size;
    dis = distance;
    nearnb=nearnb;
}
void SAalg::doSA(deque<int> *tour) {
    initpath();
    copypath(pathbest,path);

    double bestevel=evellength(dis,pathbest);

    int bestT = 0;
    double currentevel=bestevel;
    double t0=250.0;
    double T=5;
    double N=5;
    double a=0.98;
    deque<int> pathtemp(0,pointnumber);

    int k = 0; //current sa times
    int n = 0;// iter step
    double t = t0;
    double r = 0.0;
    while(k<T){
        n=0;
        while (n<N){
            exchangefornewpath(pathtemp,path);
            int tempevel=evellength(dis,pathtemp);
            if(tempevel<bestevel){
                copypath(pathbest,pathtemp);
                bestT=k;
                bestevel=tempevel;
            }

            random_device rd;
            uniform_real_distribution<double> dist(0, 1);
            double rr=dist(rd);
            if(tempevel<currentevel||(exp(currentevel-tempevel)/t)>r){
                copypath(path,pathtemp);
                currentevel=tempevel;
            }
            n++;
        }
        t=a*t;
        k++;
    }
    tour[0]=pathbest;
}

void SAalg::exchangefornewpath(deque<int> &newpath,deque<int> &oldpath) {
//    newpath.assign(oldpath.begin(),oldpath.end());
    newpath=oldpath;
    uniform_int_distribution<int> dist(0, pointnumber-1);
    random_device rd;
    int rand1=dist(rd);
    int rand2=dist(rd);
    while(rand1==rand2)
        rand2=dist(rd);

    int temp=newpath[rand1];
    newpath[rand1]=newpath[rand2];
    newpath[rand2]=temp;
}

void SAalg::initpath() {
    for (int i = 0; i < pointnumber; ++i) {
        path.push_back(0);
        pathbest.push_back(0);
    }
//    std::random_device rd;
//    mt19937 g(rd());
//    shuffle(path.begin(),path.end(),g);
    greedynaive(dis,nearnb,&path);
}



void SAalg::copypath(deque<int> &v1, deque<int> &v2){
//    v1.assign(v2.begin(),v2.end());
    v1=v2;
}

