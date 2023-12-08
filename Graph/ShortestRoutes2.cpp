#include<bits/stdc++.h>

using namespace std;

void findShortestDistance(vector<pair<int,int>> adj[], int n, vector<long long> &distance) {
    distance[1] = 0;

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, 1});

    pair<long long,int> topNode;
    while(!pq.empty()) {
        topNode = pq.top();
        pq.pop();

        int graphNode = topNode.second;
        if(distance[graphNode] < topNode.first) continue;

        for(auto v : adj[graphNode]) {
            long long neighbourNode = v.first;
            long long edgeWeight =  v.second;

            if(topNode.first + edgeWeight < distance[neighbourNode]) {
                distance[neighbourNode] = topNode.first + edgeWeight;
                pq.push({distance[neighbourNode], neighbourNode});
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> adj(n+1, vector<long long>(n+1, LONG_LONG_MAX));
    for(int i = 0; i<m; i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        adj[x][y] = z;
        adj[y][x] = z;
    }
    
    findShortestDistance(adj, n, distance);

    for(int i = 0; i<q; i++) {
        int x, y;
        cin >> x >> y;
        if(distance[x][y] == LONG_LONG_MAX) {
            cout << "-1" << endl; 
        } else {
            cout << distance[x][y] << endl;
        }
    }

    return 0;
}
