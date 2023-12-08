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
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n+1];
    for(int i = 0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    
    // for(int i = 1; i<=n; i++) {
    //     cout << i << " "; 
    //     for(auto edge : adj[i]) {
    //         cout << edge.first << " " << edge.second << endl;
    //     }
    // }
    
    vector<long long> distance(n+1, LONG_LONG_MAX);
    
    findShortestDistance(adj, n, distance);

    for(int i =1 ; i<=n ; i++) cout << distance[i] << " ";

    return 0;
}
