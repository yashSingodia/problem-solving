#include<bits/stdc++.h>

using namespace std;

// long findMaxSumWithFixedLengthSubarray(vector<int> &nums, int k) {
//     int left = 0; int right = 0;
//     long sum = 0;
//     long maxSum = LONG_MIN;
//     while(right < nums.size()) {
//         sum += nums[right];
//         if(right - left + 1 < k) {
//             right++;
//         } else {
//             maxSum = max(maxSum, sum);
//             sum = sum - nums[left];
//             left++;
//             right++;
//         }
        
//     }
//     return maxSum;
// }

// long findMaxSubarray(vector<int> &nums, int a, int b) {
    
//     long maxSum = LONG_MIN;
//     for(int len = a; len<=b; len++) {
//         maxSum = max(maxSum, findMaxSumWithFixedLengthSubarray(nums, len));
//     }
//     return maxSum;
// }

int findMaxSubarrayOptimised(vector<int> &nums, int a, int b) {
    long maxSum = LONG_MIN;




    return maxSum;
}

int main() {
    int n, a, b; cin>>n >> a >> b;
    vector<int> nums(n);
    
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    // GAVE TLE for some cases
    // cout << findMaxSubarray(nums, a, b);

    cout << findMaxSubarrayOptimised(nums, a, b);
    return 0;
}
