#include<bits/stdc++.h>

using namespace std;

bool isPossible(vector<long long> machineTime, long long productsCount, long long allowedTime) {
    long long createdProducts = 0;
    for(long long i = 0; i<machineTime.size(); i++) {
        createdProducts += allowedTime / machineTime[i];
    }
    
    return createdProducts >= productsCount;
}

long long solve(vector<long long> machineTime, long long productsCount, long long minTime, long long maxTime) {
    long long left = minTime;
    long long right = maxTime * productsCount;
    long long minTimeNeeded = right;
    long long mid;
    
    while(left <= right) {
        mid = left + (right - left ) / 2;
        
        
        if(isPossible(machineTime, productsCount, mid)) {
            minTimeNeeded = min(minTimeNeeded, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return minTimeNeeded;
}

int main() {
    long long machinesCount, productsCount;
    cin >> machinesCount >>  productsCount;
    vector<long long> machineTime; 
    long long minTime, maxTime;

    for(long long i = 0; i<machinesCount; i++) {
        long long x;
        cin>>x;
        minTime = min(minTime, x);
        maxTime = max(maxTime, x);
        machineTime.push_back(x);
    }

    cout << solve(machineTime, productsCount, minTime, maxTime);

    return 0;
}
