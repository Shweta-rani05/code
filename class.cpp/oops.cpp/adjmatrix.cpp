#include <iostream>
using namespace std;

class AdjMatrix{
    
    int vert;
    int **mat;

    public:
    AdjMatrix(int v){
        vert= v;

        mat = new int*[vert];
        for(int i=0;i<vert;i++){
            mat[i]= new int[vert];
            for(int j=0;j<vert;j++){
                mat[i][j]=0;
            }
        }
    }

    void insertEdge(int u,int v){
        if(u<0 && v<0 && u>=vert && v>=vert){
            cout<<"Invalid edges"<<endl;
            return ;
        }
        else{

             mat[u][v]=1;
             mat[v][u]=1; 
        }   
    }

    void delEdge(int u, int v){
        if(u<0 && v<0 && u>=vert && v>=vert){
            cout<<"Invalid edges"<<endl;
            return;
        }else{
            mat[u][v]=0;
            mat[v][u]=0;

        }
    }

    void printMatrix(int v){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int vertex,edges;
    cout<<"enter the no.of vertex"<<endl;
    cin>>vertex;

    edges=vertex-1;
    
    AdjMatrix m1(vertex);
    cout<<"Enter the edges(u,v) to be inserted "<<endl;
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        m1.insertEdge(u,v);
    }
    
    cout<<"the adjacency matrix for the tree is "<<endl;
    m1.printMatrix(vertex);

    int u,v;    
    cout<<"enter the edge to be deleted"<<endl;
    cin>>u>>v;
    m1.delEdge(u,v);
    cout<<"the adjacency matrix after deletion of ("<<u<<v<<") is "<<endl;

    m1.printMatrix(vertex);
}