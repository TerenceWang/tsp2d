#include "util.h"
#include "Greedy.h"
#include "SAalg.h"
#include "twoopt.h"
using namespace std;


int main() {
    double begin = clock();
    int pointnum;
    cin>>pointnum;
    point s[pointnum];
    for (int i = 0; i < pointnum; ++i) {
        cin>>s[i].x;
        cin>>s[i].y;
    }
    vector<vector<int> > dis,nearnb;
    vector<int> temp=vector<int>(pointnum ,-1);
    dis = vector<vector<int> >(pointnum, vector<int>(pointnum, -1));
    for (int j = 0; j < pointnum; ++j) {
        temp[j]=j;
    }
    for (int k = 0; k < pointnum; ++k) {
        vector<int> tt=temp;
        nearnb.push_back(tt);
    }
    calcdistancem(dis, s,pointnum);
    calcnearneighbor(nearnb,dis);


//    for (int l = 0; l < pointnum; ++l) {
//        cout<<nearnb[8][l]<<" "<<dis[8][nearnb[8][l]]<<endl;
//    }
    vector <int>tour(pointnum, 0);

    //read fin

//    //sa
//    SAalg* sAalg=new SAalg(pointnum,dis,nearnb);
//    sAalg[0].doSA(&tour);

    //greddy
//    greedynaive(dis,nearnb,&tour);

    twoopt * twoopt1=new twoopt(pointnum,dis,nearnb);
    twoopt1->doTwoOptHer(&tour,begin);
    printtour(tour);
    return 0;
}