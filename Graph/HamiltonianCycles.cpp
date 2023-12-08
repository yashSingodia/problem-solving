#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void dfs(vector<int> flights[], int n, int src, int parent, vector<int> &nodesInPath, int &cnt) {
    
    
    int mod = 1e9 + 7;
    nodesInPath.push_back(src);
    if(src == n) {
        
        if(nodesInPath.size() == n) {
            cnt = (cnt + 1) % mod;
        }
    }
 
    for(auto adj : flights[src]) {
        if(adj != parent) {
             dfs(flights, n, adj, src, nodesInPath, cnt);
        }
    }
    nodesInPath.pop_back();

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> flights[n+1]; 
    for(int i = 0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        
        flights[x].push_back(y);
    }
    vector<int> nodesInPath;
    int cnt = 0;
    dfs(flights, n, 1, -1, nodesInPath, cnt);
    cout << cnt << endl;
    return 0;
}