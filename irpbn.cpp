//
// Created by Terence on 10/23/16.
//

#include <list>
#include "irpbn.h"
void pointinsert(list<int> &tour,int point,vector<vector<int> >dis);
void neighborinsertoptimal(vector<vector<int> >dis,vector<vector<int> >nearnb, deque<int> *tourr){

    int size=dis[0].size();

    int used[size];
    list<int> tour;
    memset(used,0,size*sizeof(int));
    uniform_int_distribution<int> dist(0, size-1);
    random_device rd;
    int startpoint=dist(rd);
//    int startpoint = 0;
    tour.push_back(startpoint);
    used[startpoint]=1;
    if(size<4){
        for (int i = 1; i < size; ++i) {
            tourr[0].push_back(nearnb[startpoint][i]);
            used[nearnb[startpoint][i]]=1;
        }
        return;
    } else{
        for (int i = 1; i < 3; ++i) {
            tour.push_back(nearnb[startpoint][i]);
            used[nearnb[startpoint][i]]=1;
        }
    }
    int k=3;

    while (k<size){
//        pointinsert(tour,nearnb[startpoint][k],dis);



        int point=nearnb[startpoint][k];
        int bestdistance=2147483647;
        //auto begin=clock();
        list<int>::iterator bestpoint=tour.begin();
        list<int>::iterator iter;
        list<int>::iterator end=tour.end();
        --end;
        for ( iter=tour.begin(); iter!=end; ++iter) {
            list<int>::iterator temp= iter;
            temp++;
            int distance=dis[*iter][point]+dis[*temp][point]-dis[*iter][*temp];
            if(distance<bestdistance){
                bestdistance=distance;
                bestpoint=iter;
            }
        }

        end=tour.end();
        end--;
        if(bestdistance<(dis[*tour.begin()][point]+dis[*end][point]-dis[*tour.begin()][*end])){
            tour.insert(++bestpoint,point);
        }else{
            tour.insert(tour.end(),point);
        }




        k++;
    }
    tourr[0].clear();
    list<int>::iterator iter;
    for (iter= tour.begin();  iter!=tour.end(); ++iter) {
        tourr[0].push_back(*iter);
    }

}
void pointinsert(list<int> &tour,int point,vector<vector<int> >dis){
    int bestdistance=2147483647;
    //auto begin=clock();
    list<int>::iterator bestpoint=tour.begin();
    list<int>::iterator iter;
    list<int>::iterator end=tour.end();
    --end;
    for ( iter=tour.begin(); iter!=end; ++iter) {
        list<int>::iterator temp= iter;
        temp++;
        int distance=dis[*iter][point]+dis[*temp][point]-dis[*iter][*temp];
        if(distance<bestdistance){
            bestdistance=distance;
            bestpoint=iter;
        }
    }

    end=tour.end();
    end--;
    if(bestdistance<(dis[*tour.begin()][point]+dis[*end][point]-dis[*tour.begin()][*end])){
        tour.insert(++bestpoint,point);
    }else{
        tour.insert(tour.end(),point);
    }
    //cout<<(double)(clock()-begin)/CLOCKS_PER_SEC<<endl;
}