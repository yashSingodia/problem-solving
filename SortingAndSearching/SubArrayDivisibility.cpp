#include<bits/stdc++.h>

using namespace std;

long long countArrays(vector<long long> nums, long long k) {
    long long ans = 0;
    long long sumTillNow = 0;

    
    unordered_map<long long, long long> elementToFrequencyMap;

    elementToFrequencyMap[0] = 1;

    for(int i = 0; i<nums.size(); i++) {
        sumTillNow += nums[i];     
        long long mod = sumTillNow % k;
        if(mod < 0) mod = mod + k;

        if(elementToFrequencyMap.find(mod) != elementToFrequencyMap.end()) {
            ans += elementToFrequencyMap[mod];
        }
        elementToFrequencyMap[mod]++;
        
    }
    return ans;
}

int main() {
    long long n;
    cin >> n ;
    vector<long long> nums; 

    for(long long i = 0; i<n; i++) {
        long long x;
        cin>>x;
        nums.push_back(x);
    }
    cout << countArrays(nums, n);

    return 0;
}
