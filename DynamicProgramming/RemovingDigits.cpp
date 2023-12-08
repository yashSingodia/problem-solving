#include<bits/stdc++.h>

using namespace std;

vector <int> convertToVector(int n) {
    
    vector<int> numbers;
    
    while(n>0) {
        int mod = n%10;
    
        numbers.push_back(mod);
        n = n / 10;
    }
    return numbers;
}

int findWays(int n, vector<int> &dp) {

    if(n==0) {
        return 1;
    } else if(n<0) {
        return 0;
    }

    if(dp[n] != -1) return dp[n];

    vector<int> numbers = convertToVector(n);
    int minSteps = INT_MAX;

    for(int i = 0; i<numbers.size(); i++) {
        
        if(numbers[i] == 0) continue;

        minSteps = min(1 + findWays(n - numbers[i], dp), minSteps);

    }

    return dp[n]=minSteps;

}


int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1, -1);
    
    cout << findWays(n, dp) - 1;


    return 0;
}
