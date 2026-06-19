//bellamnford algorithm for calculating the shortest path or distance in directed weighted graph for negative weighted graph 



class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

//time complexity : O(V.E)
void bellmanFord(int src, vector<vector<Edge>> graph , int V ){
   
    vector<int> dist(V,INT_MAX);
    dist[src] = 0;
      
    for ( int i=0 ;i< V-1;i++ ){ //v times
        for(int u=0;u<V;u++){ // e times
            for(Edge e: graph[u] ){
                if(dist[e.v] > dist[u] +e.wt){
                    dist[e.v] = dist[u]+e.wt;
                }
            }
        }
        
    }

    for(int i = 0; i<V; i++){
        cout <<dist[i]<<" ";
    }
    cout <<endl;
}

int main(){
    int v  = 5;
    vector<vector<Edge>> graph(v);
    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,-4));

    graph[2].push_back(Edge(3,2));

    graph[3].push_back(Edge(4,4));

    graph[4].push_back(Edge(1,-1));
    
    bellmanFord( 4,graph , v);
    return 0;
}