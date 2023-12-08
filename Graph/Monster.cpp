#include<bits/stdc++.h>

using namespace std;

struct node {
 
    int x;
    int y;
    int time;
}

bool hasWon(int x, int y, int rows, int cols) {
    return x==0 || y==0 || x==rows-1 || y==cols-1;
}

bool isValid(int x, int y, int rows, int cols) {
    return x>=0 && x < rows && y>=0 && y<cols;
}

bool solve(vector<char> matrix[], int rows, int cols, int x, int y) {
    vector<char> copyMatrix[] = matrix;
    queue<node> q;
    q.push({x, y, 0})
    copyMatrix[x][y] = '0';

    // traverse the character
    node n;
    bool canReach = false;
    while(!q.empty()) {
        n = q.front();
        q.pop();

        copyMatrix[x][y] = to_string(n.time);

        if(hasWon(n.x, n.y, rows, cols)) {
            canReach = true;
        }

        for(int dx = 0; dx < 4; dx++) {
            int nextX = n.x + ddx[dx];
            int nextY = n.y + ddy[dx];

            if(isValid(nextX, nextY, rows, cols))  {

                if(matrix[nextX][nextY] == '#') continue;
                else {
                    q.push({next, nextY, n.time + 1});
                }

            }

        }
    }

    if(canReach == false) {
        return false;
    }

    q.clear();

    for(int i = 0; i<rows; i++) {
        for(int j = 0; j<cols; j++) {
            if(matrix[i][j] == 'M') {
                if(copyMatrix[i][j] == '0') {
                    return false;
                }
                q.push({i, j, 0});
            }
        }
    }

    while(!q.empty()) {
        n = q.front();
        q.pop();

        if(stoi(copyMatrix[n.x][n.y]) == n.time) {
            return false;
        }

        for(int dx = 0; dx < 4; dx++) {
            int nextX = n.x + ddx[dx];
            int nextY = n.y + ddy[dx];

            if(isValid(nextX, nextY, rows, cols))  {

                if(matrix[nextX][nextY] == '#') continue;
                else {
                    q.push({next, nextY, n.time + 1});
                }

            }

        }
    }


}


// void findOrderOfCourses(vector<int> adj[], int n) {
//     vector<int> topoSort;
//     vector<bool> visited(n+1, false);
//     vector<int> indegree(n+1, 0);
    
//     for(int i = 1; i<=n; i++) {
//         for(int j = 0; j<adj[i].size(); j++) {
//             indegree[adj[i][j]]++;
//         }
        
//     }
    
//     queue<int> q;
    
//     for(int i = 1; i<=n ; i++) {
//         if(indegree[i] == 0) {
//             q.push(i);
//         }
//     }

//     while(!q.empty()) {
//         int frontNode = q.front();
//         q.pop();

//         for(auto neighbour : adj[frontNode]) {
//             indegree[neighbour]--;
//             if(indegree[neighbour] == 0) {
//                 q.push(neighbour);
//             }
//         }

//     }


//     if(topoSort.size() < n) {
//         cout << "IMPOSSIBLE" << endl;
//         exit(0);
//     }

//     reverse(topoSort.begin(), topoSort.end());
    
//     for(int ele : topoSort) {
//         cout << ele << " ";
//     }

// }

int main() {
    int n, m;
    cin >> n >> m;

    vector<char> matrix[n];
    for(int i = 0; i<n ;i++ ) {
        for(int j = 0; j<m; j++) {
            char x;
            cin >> x;
            matrix[i].push_back(x);
        }
    }
    for(int i = 0; i<n; i++) 
        for(int j = 0; j<m; j++)
             solve(matrix, n, m, i, j);
 
 
    return 0;
}



