#include<bits/stdc++.h>
using namespace std;

void DFS(int source, vector<bool> &visited, vector<vector<int>> &graph){
    cout << source << " ";
    visited[source] = true;

    for(auto neighbour : graph[source]){
        if(visited[neighbour] == false)
            DFS(neighbour, visited, graph);
    }
}

int main(){
    int vertex, edges;
    cout << "Enter number of vertex and edges: ";
    cin >> vertex >> edges;
    vector<vector<int>> graph(vertex + 1);
    
    cout << "Enter all edges: ";
    for(int i=0; i<edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<bool>visited(vertex + 1, false);

    for(int i=1; i<=vertex; i++){
        if(visited[i] == false){
            DFS(i, visited, graph);
        }
    }
    return 0;
}