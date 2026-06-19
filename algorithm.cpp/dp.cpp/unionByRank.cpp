//this is the code for union set which is furthur used in :
//-IN KRUSHKAL'S ALGORITHM
// - finding MST

#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
public:
    vector<int> par;
    vector<int> rank;
    int n ;

    DisjointSet(int n ){
        this->n = n;
        for(int i=0 ; i<n ; i++){
            par.push_back(i);
            par.push_back(0);
            
        }
    }

    int find(int x){
        if(par[x] != x){
            par[x] = find(par[x]);
        }
        return par[x];
    }

        void unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return;  // Already in same set

        if(rank[parA] < rank[parB]) {
            par[parA] = parB;
        } else if(rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parB] = parA;
            rank[parA]++;
        }
    }
   
    void getInfo() {
        for(int i = 0; i < n; i++) {
            cout << i << ": Parent = " << par[i] << ", Rank = " << rank[i] << endl;
        }
    }
  
};

int main(){
    DisjointSet dj(6);
    dj.unionByRank(0,2);
    cout << dj.find(2) << endl;
    dj.unionByRank(1,3);
    dj.unionByRank(2,5);
    dj.unionByRank(0,3);
    cout << dj.find(2) << endl;
    dj.unionByRank(0,4);

    dj.getInfo();

    return 0 ;
    
}
