#include<bits/stdc++.h>

using namespace std;


long findMaxSubarray(vector<int> &nums) {
    long sum = 0;
    long maxi = LONG_MIN;
    for(int i =0 ; i<nums.size(); i++) {
        sum += nums[i];
        
        maxi = max(maxi, sum);
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}

int main() {
    int n; cin>>n;
    vector<int> nums(n);
    
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    cout << findMaxSubarray(nums);
    return 0;
}
