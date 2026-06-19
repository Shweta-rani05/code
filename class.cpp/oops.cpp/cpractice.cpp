//code practice 

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class CircularQueue{
    public:
    int size;
    queue<pair<int,vector<int>>> q;//stores node and path 
    CircularQueue(int s):size(s){} //constructor 
    
    void enqueue(int node,vector<int>path){
        if(q.size() <size){
            q.push({node,path});
        }else{
            q.pop(); //maintain circular behavior
            q.push({node,path});

        }

    }
    pair<int , vector<int>> dequeue(){
        if(!q.empty()){
            pair<int , vector<int>> front = q.front();
            q.pop();
            return front;
        }
        return {-1,{}};
    }
    bool isEmpty(){
        return q.empty();
    }
};

void bfs(vector<vector<int>>& adjMatrix,int source,int destination){
    int n = adjMatrix.size();
    vector<bool> visited(n,false);
    CircularQueue circularQueue(n);
    circularQueue.enqueue(source,{source});
    visited[source] = true;

}

