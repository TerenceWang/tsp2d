//
// Created by Terence on 10/25/16.
//
#include "grtdm.h"

void greedytdm(vector<vector<int> > dis,vector< vector<int> > nearnb, vector<double > pi,deque<int>* tour) {
    vector<edge> heap;
    int size=dis[0].size();
    int edgestore[size][2];
    int used[size];
    int degree[size];
    int tail[size];
    for (int i = 0; i < size; ++i) {
        used[i]=0;
        edgestore[i][0]=-1;
        edgestore[i][1]=-1;
        degree[i]=0;
        tail[i]=-1;
        edge temp;
        temp.i=i;
        temp.j=nearnb[i][1];
        temp.index=1;
        temp.length=dis[i][nearnb[i][1]]-pi[temp.i]-pi[temp.j];
        heap.push_back(temp);
    }
    make_heap(heap.begin(),heap.end(),[](const edge &a, const edge &b)->bool{
        return a.length>=b.length;
    });
    int edgesize=0;
    while(edgesize<size-1) {
        edge e = heap.front();
        pop_heap(heap.begin(), heap.end(), [](const edge &a, const edge &b) -> bool {
            return a.length >= b.length;
        });

//        cout << " 111 " << e.i << " " << e.j << endl;
//        cout<<heap.size()<<endl;
        heap.pop_back();
//        cout<<heap.size()<<endl;
        if (degree[e.i] == 2||degree[e.j]==2||tail[e.i]==e.j || tail[e.j] == e.i) {
            if(degree[e.i]==2)
                continue;
             else if (degree[e.j] == 2 || tail[e.i] == e.j || tail[e.j] == e.i) {
                edge temp;
                temp.i = e.i;
                temp.index = e.index + 1;
//                while(degree[nearnb[temp.i][temp.index]]==2 || tail[e.i] == e.j || tail[e.j] == e.i){
//                    temp.index++;
//                }

                temp.j = nearnb[temp.i][temp.index];
                temp.length = dis[temp.i][temp.j] - pi[temp.i] - pi[temp.j];
//                for(vector<edge>::iterator it = heap.begin(); it != heap.end(); it++)
//                    cout << it->i << " " << it->j << " " << it->length << endl;
                heap.push_back(temp);
//                cout << " temp " << temp.i << " " << temp.j << endl;
                push_heap(heap.begin(), heap.end(), [](const edge &a, const edge &b) -> bool {
                    return a.length >= b.length;
                });
//                for(vector<edge>::iterator it = heap.begin(); it != heap.end(); it++)
//                    cout << it->i << " " << it->j << " " << it->length << endl;
                continue;
            }
        }else{
//            cout << "ADD " << e.i << " " << e.j << endl;
            edgesize++;
            if(edgestore[e.i][0]==-1){
                edgestore[e.i][0]=e.j;
            }else{
                if(edgestore[e.i][1]!=-1){
                    cout<<"errr";
                }
                edgestore[e.i][1]=e.j;

            }
            if(edgestore[e.j][0]==-1){
                edgestore[e.j][0]=e.i;
            } else{
                edgestore[e.j][1]=e.i;
            }
            degree[e.i]+=1;
            degree[e.j]+=1;
            int tailx=tail[e.i];
            int taily=tail[e.j];
            if(tailx==-1&&taily==-1){
                tail[e.j]=e.i;
                tail[e.i]=e.j;
            }else if(tailx==-1&&taily!=-1){
                tail[taily]=e.i;
                tail[e.i]=taily;
                tail[e.j]=-1;
            } else if(tailx!=-1 &&taily==-1){
                tail[tailx]=e.j;
                tail[e.j]=tailx;
                tail[e.i]=-1;
            }else{
                tail[tailx]=taily;
                tail[taily]=tailx;
                tail[e.i]=-1;
                tail[e.j]=-1;
            }
//            cout << "TAIL " << tail[e.i] << " " << tail[e.j] << endl;
            if(edgesize<size-1){
                if(degree[e.i]==2)
                    continue;
                else{
                    edge temp;
                    temp.i = e.i;
                    temp.index = e.index + 1;
//                    while(degree[nearnb[temp.i][temp.index]]==2 || tail[e.i] == e.j || tail[e.j] == e.i){
//                        temp.index++;
//                    }
                    temp.j = nearnb[temp.i][temp.index];
                    temp.length = dis[temp.i][temp.j] - pi[temp.i] - pi[temp.j];
                    heap.push_back(temp);
                    push_heap(heap.begin(), heap.end(), [](const edge &a, const edge &b) -> bool {
                        return a.length >= b.length;
                    });

                    continue;
                }
            }else{
                continue;
            }
        }
    }

    int startpoint=0;
    for (int j = 0; j < size; ++j) {
        if(edgestore[j][0]==-1||edgestore[j][1]==-1) {
            startpoint = j;
            break;
        }
    }
//    tour[0].clear();
    deque<int> tourr(size,0);
    used[startpoint]=1;
//    tour[0].push_back(startpoint);
    tourr[0]=startpoint;
    int lastpoint=startpoint;
    for (int k = 1; k < size; ++k) {
        if(edgestore[lastpoint][0]!=-1) {
            if (used[edgestore[lastpoint][0]] == 0) {
                tourr[k]=edgestore[lastpoint][0];
//                tour[0].push_back(edgestore[lastpoint][0]);
                lastpoint = edgestore[lastpoint][0];
                used[lastpoint] = 1;
            }
            else {
                if(edgestore[lastpoint][1]!=-1){
                    if (used[edgestore[lastpoint][1]] == 0) {
//                        tour[0].push_back(edgestore[lastpoint][1]);
                        tourr[k]=edgestore[lastpoint][1];
                        lastpoint = edgestore[lastpoint][1];
                        used[lastpoint] = 1;
                    }
                }
            }
        }
    }
    tour[0]=tourr;
//    vector<edge>::iterator iter;
//    for (int j = 0; j < size; ++j) {
//        pop_heap(heap.begin(),heap.end(),[](const edge &a, const edge &b)->bool{
//                return a.length>b.length;
//        });
//        edge e=heap.front();
//
//        heap.pop_back();
//
//        for (iter = heap.begin(); iter !=heap.end() ; ++iter) {
//            cout<<(*iter).length<<" ";
//        }
//        cout<<endl;
//    }


}

