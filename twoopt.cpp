//
// Created by Terence on 10/21/16.
//

#include "twoopt.h"
#include "irpbn.h"

#define TIME_LIMIT 1.98
#define MAXNB 20
twoopt::twoopt(int size, vector<vector<int> > distance,vector<vector<int> > nearn,vector<double > pii) {
    pointnumber=size;
    dis=distance;
    nearnb=nearn;
    pi=pii;
}
void twoopt::doTwoOptHer(deque<int> *tour, double begin){

    initpath();

    int size = path.size();
    index=deque<int>(size);
    for (int i = 0; i < size; ++i) {
        index[path[i]]=i;
    }

    int best_distance=evellength(dis,path);
    newpath=path;
    int count=0;
    int minsize=min(size, MAXNB);

    while (double(clock()-begin)/CLOCKS_PER_SEC < TIME_LIMIT){
        if(count>0) {
            exchangefornewpath();
        }
        count++;
        bool change= true;

        while (change) {
            change=false;
            for (int i = 0; i < size - 1; ++i) {
                for (int j = 0; j < minsize; ++j) {
                    int currentpoint = path[i];
                    int currentpointnext = path[i + 1];
                    int testpoint = nearnb[currentpoint][j];
                    int testpointnext = path[(index[nearnb[currentpoint][j]] + 1) % size];
                    if(currentpointnext==testpoint||currentpointnext==testpointnext)
                        continue;
                    if (dis[currentpoint][testpoint] + dis[currentpointnext][testpointnext] <
                        dis[testpoint][testpointnext] + dis[currentpoint][currentpointnext]) {
                        change=true;
                        int indexdis = 0;
                        int start = i + 1;
                        int end = index[nearnb[currentpoint][j]];
                        if (start < end)
                            indexdis = end - start;
                        else
                            indexdis = end - start + size + 1;
                        indexdis = (indexdis + 1) / 2;
                        while (indexdis-- > 0) {
                            start %= size;
                            end = end == -1 ? size - 1 : end;
                            swap(path[start], path[end]);
                            start++;
                            end--;
                        }
                        for (int k = 0; k < size; ++k) index[path[k]] = k;
                    }
                }
            }
        }
        int distance=evellength(dis,path);
        if(distance<best_distance){
            best_distance=distance;
            newpath=path;
        }
    }
//    cout<<count<<endl;
//    cout<<"fin: "<< ((clock()-begin)/CLOCKS_PER_SEC)<<endl;
    tour[0]=newpath;

}
void twoopt::exchangefornewpath() {

    int size=path.size();
    if (size<8)
        return;
    static uniform_int_distribution<int> dist(2, size-3);
    static random_device rd;
    for (int i = 0; i < size/10; ++i) {
        int pointid=dist(rd);
        int a1=(pointid + 1)>=size?0:(pointid+1);
        int a2=(pointid - 1)<0?size-1:(pointid-1);
        swap(path[a1],path[a2]);
        index[a1]=a1;
        index[a2]=a2;
    }

}
void twoopt::doTwoOpt(deque<int> *tour, double begin)
{
    initpath();
    // Get tour size
    int size = path.size();

    // repeat until no improvement is made
    int improve = 0;
    while ( improve < 20 && (clock()-begin)/CLOCKS_PER_SEC < TIME_LIMIT)
    {

        double best_distance = evellength(dis,path);

        for ( int i = 0; i < size - 1 && (clock()-begin)/CLOCKS_PER_SEC < TIME_LIMIT; i++ )
        {
            for ( int k = i + 1; k < size && (clock()-begin)/CLOCKS_PER_SEC < TIME_LIMIT; k++)
            {

                TwoOptSwap( i, k );

                double new_distance = evellength(dis,newpath);

                if ( new_distance < best_distance )
                {
                    // Improvement found so reset
                    improve = 0;
                    path = newpath;
                    best_distance = new_distance;
                }
            }
        }
        improve ++;
    }
    tour[0]=path;
}

void twoopt::TwoOptSwap( const int& i, const int& k ) {
    int size = path.size();

    // 1. take route[0] to route[i-1] and add them in order to new_route
    for ( int c = 0; c <= i - 1; ++c )
    {
        newpath[c]=path[c];
//        new_tour.SetCity( c, tour.GetCity( c ) );
    }

    // 2. take route[i] to route[k] and add them in reverse order to new_route
    int dec = 0;
    for ( int c = i; c <= k; ++c )
    {
        newpath[c]=path[k-dec];
//        new_tour.SetCity( c, tour.GetCity( k - dec ) );
        dec++;
    }

    // 3. take route[k+1] to end and add them in order to new_route
    for ( int c = k + 1; c < size; ++c )
    {
        newpath[c]=path[c];
//        new_tour.SetCity( c, tour.GetCity( c ) );
    }
}

void twoopt::initpath() {
//    for (int i = 0; i < pointnumber; ++i) {
//        path.push_back(0);
//        newpath.push_back(0);
//    }
    path=deque<int>(pointnumber,0);

    deque<int> temp;
    newpath=deque<int>(pointnumber,0);

//    std::random_device rd;
//    mt19937 g(rd());
//    shuffle(path.begin(),path.end(),g);
//    neighborinsertoptimal(dis,nearnb,&path);
    greedytdm(dis,nearnb,pi,&path);
//    temp=path;
//    sort(temp.begin(),temp.end());
//    bool flag= false;
//    for (int i = 0; i < pointnumber; ++i) {
//        if(temp[i]!=i) {
//            flag = true;
//            break;
//        }
//    }
//    if(flag) {
//        deque<int> s=deque<int>(pointnumber,0);
//        greedynaive(dis, nearnb, &s);
//        path=s;
//    }
//    greedynaive(dis,nearnb,&path);
}
