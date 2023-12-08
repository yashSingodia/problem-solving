#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int x, y;
    int rightMov, leftMov;
};


int main() {
    int n, m;
    cin >> n >> m;

    int srcX, srcY;
    cin >> srcX >> srcY;

    int maxRMovements, maxLMovements;
    cin >> maxRMovements >> maxLMovements;

    vector<vector<char>> matrix(n, vector<char>(m));
    for(int i = 0; i<n ;i++ ) {
        for(int j = 0; j<m; j++) {
            char x;
            cin >> x;
            matrix[i][j] = x;
        }
    }
    
    // applying bfs
    queue<Node> q;
    Node front;
    

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[srcX][srcY] = true;
    int maximumReachableNodes = 1;

    while(!q.empty()) {
        front = q.front();
        q.pop();


    }
 
    return 0;
}



