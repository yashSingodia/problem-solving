#include<bits/stdc++.h>

using namespace std;

bool solve(vector<int> adj[], int n, int m, vector<int>& color, int src) {
    queue<pair<int,int>> q;
    color[src] = 0;
    q.push({src, 0});
    
    pair<int,int> frontNode; 
    
    while(!q.empty()) {
        frontNode = q.front();
        q.pop();

        for(auto neighbours : adj[frontNode.first]) {
            if(color[neighbours] == frontNode.second) {
                return false;
            } 
            if(color[neighbours] == -1) {
                color[neighbours] = 1 - frontNode.second;
                q.push({neighbours, 1 - frontNode.second});
            }
        }
    }
    return true;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];
    for(int i = 0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> color(n+1, -1);
    for(int i = 1; i<=n; i++) {
        if(color[i] == -1) {
            if(solve(adj, n, m, color, i) == false) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
             }
        }
    }

    for(int i = 1; i<color.size(); i++) {
        cout << color[i] + 1 << " ";
    }
    return 0;
}
