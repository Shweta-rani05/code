#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<climits>
using namespace std;

class Graph {
    int V;
    list<pair<int,int>> * l; // int,int : neighbour + wt
    bool isUndir;
public:
    Graph(int V, bool isUndir = true){
        this->V = V;
        l = new list<pair<int,int>> [V];
        this-> isUndir = isUndir;
    }

    void addEdge(int u ,int v , int wt){ // for weighted undirected graph 
        l[u].push_back(make_pair(v,wt));
        if(isUndir){
            l[v].push_back(make_pair(u,wt));
        }
    }

    void primsAlgo(int src ){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //(wt,u) -> minHeap

        vector<bool>mst(V,false);
        pq.push(make_pair(0,src));
        int ans = 0;

        while(pq.size() > 0){
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(!mst[u]){
                mst[u] = true;
                ans += wt;
                list<pair<int,int>> neighbours = l[u];
                for(pair<int,int> n : neighbours){
                    int v = n.first;
                    int current = n.second;
                    pq.push(make_pair(current,v));

                }
            }
        }
        cout << "final cost of MST =" <<ans<< endl;
    }
    
};

int main(){
    // prims algorithm graph 
    Graph graph(4);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2,15);
    graph.addEdge(0,3,30);

    graph.addEdge(1,3,40);

    graph.addEdge(2,3,50);

    graph.primsAlgo(0);
    return 0 ;
}


//problem - 1584 min cost to connect all points 

class Solution {
public:
    int minCostConnectPoints(vector<vector<int,int>>& points){
        int V = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>>,greater<pair<int,int>>> pq;
        //(wt,u)
        vector<bool>mst(V,false);
        pq.push(make_pair(0,src));
        int minCost = 0;

        while(pq.size()> 0){
            int u = pq.top().second;
            int cost = pq.top().first;

            if(!mst[u] =true){
                mst[u] = true;
                minCost += cost;

                for(int v=0;v<V; v++){
                    if(u != v){
                        int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                        pq.push_back(make_pair(wt,v));
                    }
                }
            }
        }
        return minCost;
    }
}