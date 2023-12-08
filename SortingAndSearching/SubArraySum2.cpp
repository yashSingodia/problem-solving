#include<bits/stdc++.h>

using namespace std;

long long countArrays(vector<int> nums, long long targetSum, int n) {
    long long sum = 0;
    long long count = 0;

    int left = 0;
    int right = 0;
    
    unordered_map<long long, long long> mp;

    while(right < nums.size()) {
        sum += nums[right];
        mp[sum]++;
        if(sum == targetSum ) {
            count++;
        }

        if(mp.find(sum - targetSum) != mp.end()) {
            count+=mp[sum-targetSum];
        }
        right++;
    }
    if(targetSum == 0) {
        count = count - n;
    }
    return count;

}

int main() {
    int n;
    long long targetSum;
    cin >> n >> targetSum;
    vector<int> nums; 

    for(int i = 0; i<n; i++) {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    cout << countArrays(nums, targetSum, n);

    return 0;
}
