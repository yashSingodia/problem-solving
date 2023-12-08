#include<bits/stdc++.h>

using namespace std;

// void dfs(vector<int>& parent, vector<int> &visited, vector<int> adj[], int src, int pu=-1) {

//     visited[src] = true;
//     parent[src] = pu;
     
//     for(auto ad : adj[src]) {

//         if(parent[src] == ad) continue;
//         if(visited[ad]) {
//             // cout << "src " << src << " " << ad << endl;
//             int temp = src;
//             while(parent[src] != -1) {
//                 roundTrip.push_back(src);
//                 src = parent[src];
//             }
//             roundTrip.push_back(ad);
//             roundTrip.push_back(temp);

//             cout << roundTrip.size() << endl;
//             for(int i = 0; i<roundTrip.size(); i++) {
//                 cout << roundTrip[i] << " ";
//             }
//             exit(0);
//         } else {
//             dfs(parent, visited, adj, ad, src);
//         }
 
//     }
    
// }
int sv, ev;
bool dfs(vector<int>adj[], vector<bool>&visited, int src, vector<int> &par, int parent) {
    visited[src] = true;
    par[src] = parent;

    for(auto edge : adj[src]) {
        
        if(edge==parent) continue;
        
        if(visited[edge]) {
            sv = edge;
            ev = src;
            return true;
        } else {
            if(dfs(adj, visited, edge, par, src))
                return true;
        }
    }
    return false;

}
int main() {
    int n, m;
    cin >> n >> m;
    sv = 0, ev = 0;

    vector<int> adj[n+1];
    for(int i = 0; i<m; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<bool> visited(n+1, false);
    vector<int> parent(n+1, -1);
    bool cycleFound = false;
        for(int i = 1; i<=n; i++) {
            if(!visited[i])
                if(dfs(adj, visited, i, parent, -1))
                    cycleFound = true;
        }

        if(!cycleFound)
            cout << "IMPOSSIBLE";
        else {
            int tv = ev;
            for(int i =1 ; i<=parent.size(); i++) {
                cout << "p " << parent[i] << " ";
            }
            cout << endl;
            vector<int> ans;
            ans.push_back(tv);
            while(tv != sv) {
                cout << tv << endl;
                ans.push_back(parent[tv]);
                tv = parent[tv];
            }
            ans.push_back(ev);
            cout << ans.size() << endl;
            for(int i = 0; i<ans.size(); i++) cout << ans[i] << " "; 
        }
        
        
    return 0;
}



