#include<bits/stdc++.h>

using namespace std;


int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins; 

    for(int i = 0; i<n; i++) {
        int x;
        cin>>x;
        coins.push_back(x);
    }

    vector<long long> dp(sum + 1, 0);
    dp[0] = 0;

    for(int i = 1; i<=sum; i++) {
        dp[i] = INT_MAX;
        for(int j = 0; j<coins.size(); j++) {
            if(i >= coins[j])
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        }
    }
    if(dp[sum] == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[sum] << endl;
    return 0;
}
