#include<bits/stdc++.h>

using namespace std;

int findMaxPages(int n, int maxPrice, vector<int> price, vector<int> pages) {
    vector<vector<int>> dp(n+1, vector<int>(maxPrice + 1, 0));
    
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<= maxPrice; j++) {
            if(price[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], pages[i-1] + dp[i-1][j-price[i-1]]);
            }
        }
    }
    
    return dp[n][maxPrice];
}

int main() {
    int n, totalPrice;
    cin >> n >> totalPrice;
    vector<int> price; 
    vector<int> pages; 

    for(int i = 0; i<n; i++) {
        int x;
        cin>>x;
        price.push_back(x);
    }
    for(int i = 0; i<n; i++) {
        int x;
        cin>>x;
        pages.push_back(x);
    }

    cout << findMaxPages(n, totalPrice, price, pages);
    
    return 0;

}
