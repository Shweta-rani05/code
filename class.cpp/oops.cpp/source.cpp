//write a C++ code for square adjacency matrix where source node is connected to destination by different path .condtions -1.bfs apply  2.circular queue needed 3.identify the node is visited or not

#include <iostream>
#include "adjacentMAT.cpp"
#include <vector>
#include <queue>
using namespace std;

class CircularQueue {
public:
    int size;
    queue<pair<int, vector<int>>> q; // Stores node & path
    
    CircularQueue(int s) : size(s) {}

    void enqueue(int node, vector<int> path) {
        if (q.size() < size) {
            q.push({node, path});
        } else {
            q.pop(); // Maintain circular queue behavior
            q.push({node, path});
        }
    }

    pair<int, vector<int>> dequeue() {
        if (!q.empty()) {
            pair<int, vector<int>> front = q.front();
            q.pop();
            return front;
        }
        return {-1, {}}; // Empty indicator
    }

    bool isEmpty() {
        return q.empty();
    }
};

void bfs(vector<vector<int>>& adjMatrix, int source, int destination) {
    int n = adjMatrix.size();
    vector<bool> visited(n, false);
    CircularQueue circularQueue(n);

    circularQueue.enqueue(source, {source});
    visited[source] = true;

    while (!circularQueue.isEmpty()) {
        auto [node , path] = circularQueue.dequeue();
        
        if (node == destination) {
            cout << "Path Found: ";
            for (int p : path) cout << p << " ";
            cout << endl;
        }

        for (int neighbor = 0; neighbor < n; ++neighbor) {
            if (adjMatrix[node][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                vector<int> newPath = path;
                newPath.push_back(neighbor);
                circularQueue.enqueue(neighbor, newPath);
            }
        }
    }
}

int main() {
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    int source = 0, destination = 3;
    bfs(adjMatrix, source, destination);
    
    return 0;
}