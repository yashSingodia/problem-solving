#include<bits/stdc++.h>

using namespace std;

long long countArrays(vector<long long> nums, long long targetDistinct, int n) {
    long long ans = 0;
    long long countUniqueElements = 0;
    
    long long left = 0;
    long long right = 0;
    
    unordered_map<long long, long long> mp;

    while(right < nums.size()) {
        mp[nums[right]]++;

        if(mp[nums[right]] == 1) {
            countUniqueElements++;
        }

        while(left <= right && countUniqueElements > targetDistinct) {
            mp[nums[left]]--;
            if(mp[nums[left]] == 0) {
                countUniqueElements--;
            }
            left++;
        }
        ans += (right - left + 1);
        right++;
    }
    return ans;
}

int main() {
    long long n;
    long long targetSum;
    cin >> n >> targetSum;
    vector<long long> nums; 

    for(long long i = 0; i<n; i++) {
        long long x;
        cin>>x;
        nums.push_back(x);
    }
    cout << countArrays(nums, targetSum, n);

    return 0;
}
