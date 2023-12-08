#include<bits/stdc++.h>

using namespace std;

int findWays(int amount, vector<int> coins, int index, vector<vector<int>> &dp) {

    if(amount == 0) {
            return 1;
        } else if(amount < 0) {
            return 0;
        }
        if(index >= coins.size()) {
            return 0;
        }

        if(dp[amount][index] != -1) return dp[amount][index];
        int ways = 0;
        
        ways = findWays(amount - coins[index], coins, index, dp) + findWays(amount, coins, index+1, dp);
        dp[amount][index] = ways;
        return dp[amount][index];
}


int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins; 

    for(int i = 0; i<n; i++) {
        int x;
        cin>>x;
        coins.push_back(x);
    }
    int mod = 1e9 + 7;
    vector<long long> cur(sum+1, 0);
       
    cur[0] = 1;
    vector<long long> prev = cur;

    for(int i = 0; i<n; i++) {
        for(int j = 1; j<=sum; j++) {
            if(i==0) {
                if(j % coins[i] == 0) {
                    cur[j] = 1;
                }
                continue;
            }
            if(coins[i] <= j)
                cur[j] = (cur[j-coins[i]] + prev[j])%mod;
            else 
                cur[j] = prev[j];
        }
        prev = cur;
    }

    cout << prev[sum] << endl;
    return 0;

}
