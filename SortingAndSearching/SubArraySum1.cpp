#include<bits/stdc++.h>

using namespace std;

int countArrays(vector<int> nums, long long targetSum, int n) {
    long long sum = 0;
    int count = 0;
    if(targetSum == sum) count++;
    int left = 0;
    int right = 0;
    
    while(right < nums.size()) {
        sum += nums[right];

        if(sum < targetSum) {
            right++;
        } else if(sum == targetSum) {
            count++;
            sum = sum - nums[left];
            left++;
            right++;
        } else {
            while(sum > targetSum && left <= right) {
                sum = sum - nums[left];
                left++;
            }
            if(sum == targetSum) {
                count++;
                sum = sum - nums[left];
                left++;
            }
            right++;
        }
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
