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

    int mod = 1e9 + 7;

    vector<long long> dp(sum + 1, 0);
    dp[0] = 1;

    for(int i = 1; i<=sum; i++) {
        for(int j = 0; j<coins.size(); j++) {
            if(i >= coins[j])
                dp[i] = (dp[i] + dp[i-coins[j]]) % mod;
        }
    }

    cout << dp[sum] << endl;
    return 0;
}
