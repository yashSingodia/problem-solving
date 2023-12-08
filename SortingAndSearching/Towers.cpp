#include<bits/stdc++.h>

using namespace std;

long long bs(vector<long long> towerCubes, long long index, long long prevIndex, vector<vector<long long>>& dp) {

    if(index==towerCubes.size()) {
        return 0;
    }

    if(dp[index][prevIndex+1] != -1)return dp[index][prevIndex+1];

    long long len = 0 +  bs(towerCubes, index + 1, prevIndex, dp);
    if(prevIndex == -1 || towerCubes[index] >= towerCubes[prevIndex]) {
        len = max(len, 1 + bs(towerCubes, index + 1, index, dp));
    }

    return dp[index][prevIndex+1] = len;
    
}

int main() {
    long long n;
    cin >> n;
    vector<long long> towerCubes; 

    for(int i = 0; i<n; i++) {
        long long x;
        cin>>x;
        towerCubes.push_back(x);
    }

    vector<vector<long long>> dp(n, vector<long long>(n+1, -1));

    cout << bs(towerCubes, 0, -1, dp);

    return 0;
}
