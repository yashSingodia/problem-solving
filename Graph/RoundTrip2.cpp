#include<bits/stdc++.h>

using namespace std;


bool dfs(vector<int>adj[], vector<bool>&visited, int src, vector<int> &par, int parent, vector<bool>&pathVisited, int &startVertex, int &endVertex) {
    
    visited[src] = true;
    par[src] = parent;
    pathVisited[src] = true;

    for(auto edge : adj[src]) {
        
        if(visited[edge] && pathVisited[edge]) {
            startVertex = src;
            endVertex = edge;
            return true;
        } else if(!visited[edge]) {
            
            if(dfs(adj, visited, edge, par, src, pathVisited, startVertex, endVertex))
                return true;
        }
    }
    pathVisited[src] = false;
    return false;

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
    vector<int> parent(n+1, -1);
    vector<bool> pathVisited(n+1, false);

    int startVertex, endVertex;
    bool cycleFound = false;
        for(int i = 1; i<=n; i++) {
            if(!visited[i])
                if(dfs(adj, visited, i, parent, -1, pathVisited, startVertex, endVertex))
                    cycleFound = true;
        }

        if(!cycleFound)
            cout << "IMPOSSIBLE";
        else {
            int tempVertex = startVertex;
        
            vector<int> ans;
            ans.push_back(tempVertex);
            while(tempVertex != endVertex) {
                // cout << tempVertex << endl;
                ans.push_back(parent[tempVertex]);
                tempVertex = parent[tempVertex];
            }
        
            ans.push_back(startVertex);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for(int i = 0; i<ans.size(); i++) cout << ans[i] << " "; 
        }
        
        
    return 0;
}



