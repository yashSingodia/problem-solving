#include<bits/stdc++.h>

using namespace std;


void findOrderOfCourses(vector<int> adj[], int n) {
    vector<int> topoSort;
    vector<bool> visited(n+1, false);
    vector<int> indegree(n+1, 0);
    
    for(int i = 1; i<=n; i++) {
        for(int j = 0; j<adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
        
    }
    
    queue<int> q;
    
    for(int i = 1; i<=n ; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for(auto neighbour : adj[frontNode]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }

    }


    if(topoSort.size() < n) {
        cout << "IMPOSSIBLE" << endl;
        exit(0);
    }

    reverse(topoSort.begin(), topoSort.end());
    
    for(int ele : topoSort) {
        cout << ele << " ";
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

    findOrderOfCourses(adj, n);
    
    return 0;
}
