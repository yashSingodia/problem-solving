#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> nums) {
        vector<int> lengthLis; 
        lengthLis.push_back(nums[0]);

        for(int i = 1; i<nums.size(); i++) {
            if(nums[i] > lengthLis.back()) {
                lengthLis.push_back(nums[i]);
            } else {
                int lowerIndex = lower_bound(lengthLis.begin(), lengthLis.end(), nums[i]) - lengthLis.begin();
                lengthLis[lowerIndex] = nums[i];
            }
        }

        return lengthLis.size();
    }

int main() {
    int n, m;
    cin >> n;
    vector<int> numbers;
    for(int i = 0; i<n; i++) {
        int x;
        cin >> x;
        numbers.push_back(x);
    }
    cout << lengthOfLIS(numbers) << endl;

}