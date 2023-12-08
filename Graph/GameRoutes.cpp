#include<bits/stdc++.h>

using namespace std;


void findGameRoutes(vector<long long> adj[], long long n) {
    vector<long long> topoSort;
    vector<long long> indegree(n+1, 0);
    int mod = 1e9 + 7;
    
    for(long long i = 1; i<=n; i++) {
        for(long long j = 0; j<adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
        
    }
    
    queue<long long> q;
    
    for(long long i = 1; i<=n ; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        long long frontNode = q.front();
        q.pop();
        
        topoSort.push_back(frontNode);

        for(auto neighbour : adj[frontNode]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }

    }
 

    if((long long)topoSort.size() < n) {
        cout << "IMPOSSIBLE" << endl;
        exit(0);
    }


    vector<long long> distance(n+1, 0);
    distance[1] =1;

    for(int i = 0; i<topoSort.size(); i++) {
        int prevNode = topoSort[i];
        for(int j = 0; j<adj[prevNode].size(); j++) {
            
            int node = adj[prevNode][j];
            distance[node] = (distance[node]+distance[prevNode]) % mod;
        }
    }
 
    cout << distance[n] << endl;

}

int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> adj[n+1];
    for(long long i = 0; i<m; i++) {
        long long x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    findGameRoutes(adj, n);
    
    return 0;
}
