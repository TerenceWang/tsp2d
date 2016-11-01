#include "Greedy.h"
#include "SAalg.h"
#include "twoopt.h"
#include "irpbn.h"
#include "grtdm.h"
#include "time.h"
using namespace std;


int main() {
    double begin = clock();
    int pointnum;
    cin>>pointnum;
    point s[pointnum];
    point avg;
    for (int i = 0; i < pointnum; ++i) {
        cin>>s[i].x;
        avg.x+=s[i].x;
        cin>>s[i].y;
        avg.y+=s[i].y;
    }
    avg.x/=pointnum;
    avg.y/=pointnum;
    vector <double >pi(pointnum);
    vector <double >lengthtopi(pointnum);
    double avglength=0.0;
    for (int l = 0; l < pointnum; ++l) {
        lengthtopi[l]=dist(s[l],avg);
        avglength+=lengthtopi[l];
    }
    avglength/=pointnum;
    for (int i = 0; i < pointnum; ++i) {
        pi[i]=0.7*(lengthtopi[i]-avglength);
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
    deque <int>tour(pointnum);
//    greedytdm(dis,nearnb,pi,&tour);

    //read fin

//    //sa
//    SAalg* sAalg=new SAalg(pointnum,dis,nearnb);
//    sAalg[0].doSA(&tour);

    //greddy
//    greedynaive(dis,nearnb,&tour);
//    cout<<evellength(dis,tour)<<endl;

//    neighborinsertoptimal(dis,nearnb,&tour);
//
    twoopt * twoopt1=new twoopt(pointnum,dis,nearnb,pi);
    twoopt1->doTwoHalfOptHer(&tour,begin);

//    deque<int> tmp;
//    tmp=tour;
//    sort(tmp.begin(),tmp.end());
//    bool flag= false;
//    for (int i = 0; i < pointnum; ++i) {
//        if(tmp[i]!=i) {
//            flag = true;
//            break;
//        }
//    }
//    if(flag) {
//        cout<<"errr"<<endl;
//    }
    printtour(tour);
//    cout<<evellength(dis,tour)<<endl;

}
