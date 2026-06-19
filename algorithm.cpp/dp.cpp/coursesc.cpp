//problem -203  course selection 1 
class Solution {
    bool isCycle(int src , vector<bool> &vis ,vector<bool>,vector<vector<int>>& graph ){
        vis[src] = true;
        rec[src] = true;
        
        for(int i=0;i<graph.size();i++){
            int u = graph[i][1];
            int v = graph[i][0];
            if(u == src){
                if(!vis[v]){
                     if(isCycle(v,vis,rec,graph)){
                    return true;
                }else{
                    if(rec[v]){
                        return true;
                    }

                }
               
                
            }
        }


    }

    bool camFinish(int numCourses, vector<vector<int>>& graph ){
        int V = numCourses;
        vector<bool> vis(V,false);
        vector<bool> rec(V, false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycle(i,vis,rec)){
                    return false;
                }
            }
        }
    }
    return false;
}

//course selection 2 

class solution {
    public:
    vector<int> findOrder (int numCourses, vector<vector<int>> & graph )
    }
}