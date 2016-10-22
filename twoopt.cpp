//
// Created by Terence on 10/21/16.
//

#include "twoopt.h"
#include "util.h"
#define TIME_LIMIT 1.8
twoopt::twoopt(int size, vector<vector<int> > distance,vector<vector<int> > nearnb) {
    pointnumber=size;
    dis=distance;
    nearnb=nearnb;
}
void twoopt::doTwoOpt(vector<int> *tour, double begin)
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
    for (int i = 0; i < pointnumber; ++i) {
        path.push_back(0);
        newpath.push_back(0);
    }
//    std::random_device rd;
//    mt19937 g(rd());
//    shuffle(path.begin(),path.end(),g);
    greedynaive(dis,nearnb,&path);
}
