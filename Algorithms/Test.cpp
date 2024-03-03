#include<bits/stdc++.h>

using namespace std;

int searchChar(vector<vector<char>> &grid, int x, int y, string s, int idx) {
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};
    int count = 0;
    if(idx == s.length()) {
        return 0;
    }
    char nextChar = s[idx];

    queue<pair<int,pair<int,int>> q;
    q.push({0, {x, y}});
    pair<int,pair<int,int> front;

    while(!q.empty()) {
        front = q.front();
        q.pop();
        int x = front.second.first;
        int y = front.second.second;

        if(grid[x][y] == nextChar) {
            return front.first;
        }

        for(int i = 0; i<4; i++) {
            for(int j = 0; j<4; j++) {
                int nextx = x + dx[i];
                int nexty = y + dy[i];

                if(nextx < 0 || nexty < 0 || nextx > rows || nexty > cols) {
                    continue;
                }
                q.push({front.first, {nextx, nexty}});
        }
    }
    }

    return -1;
    
}
bool findChar(string s, vector<vector<char>> &grid, int idx, int &ans) {
    if(idx == s.length()) {
        return;
    }
    int z = searchChar(grid, i, j, s, idx);
    if(z==-1) {
        return false;
    }`
    ans += z;
    findChar(s, grid, idx+1, ans);
}

int findMinMoves(string s, vector<vector<char>> &grid) {
    int m = grid.size();
  int n = grid[0].size();

  // Initialize dp table with infinity
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, numeric_limits<int>::max()));
  dp[0][0] = 0; // Base case: reconstructing an empty string requires no moves

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      char currentChar = grid[i - 1][j - 1];

      // Check if current character can be used to reconstruct current character in S
      if (currentChar != '.' &&
          (currentChar == S[i - 1] || tolower(currentChar) == tolower(S[i - 1]))) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
      }

      // Check if character above can be used to reconstruct current character in S
      if (i > 1 && grid[i - 2][j - 1] != '.' &&
          (grid[i - 2][j - 1] == S[i - 1] || tolower(grid[i - 2][j - 1]) == tolower(S[i - 1]))) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
      }

      // Check if character to the left can be used to reconstruct current character in S
      if (j > 1 && grid[i - 1][j - 2] != '.' &&
          (grid[i - 1][j - 2] == S[i - 1] || tolower(grid[i - 1][j - 2]) == tolower(S[i - 1]))) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }

  return (dp[m][n] == numeric_limits<int>::max()) ? -1 : dp[m][n] - 1;
}

int main() {

}