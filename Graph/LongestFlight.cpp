#include<bits/stdc++.h>

using namespace std;

void findLongestFlightDFS(vector<int> adj[], int n, vector<bool> &visited, vector<int> &distance, int src, vector<int>& parent) {
    visited[src] = true;
    // distance[src] = 0;

    for(auto v : adj[src]) {
        if(!visited[v]) {
            findLongestFlightDFS(adj, n, visited, distance, v, parent);
        }
        // remember to check for distance[v] != -1 while relaxing
        if(distance[v] != -1 && 1 + distance[v] > distance[src]) {
            parent[src] = v;
            distance[src] = 1 + distance[v];
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];
    for(int i = 0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<bool> visited(n+1, false);
    vector<int> distance(n+1, -1);
    vector<int> parent(n+1, 0);

    distance[n] = 1;
    

    // first find toposort, and then try to apply dp as it is gauranteed that node u has been visited before node v
    findLongestFlightDFS(adj, n, visited, distance, 1, parent);
    if(distance[1] == -1) {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    cout << distance[1] << endl;

    int node = 1;
    
    while(node) {
        cout << node << " ";
        node = parent[node];
    }
    
    
    return 0;
}
