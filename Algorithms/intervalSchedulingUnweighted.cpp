#include<bits/stdc++.h>


// creating an interval schedule in which no intervals overlap
class Solution {
public:
    
    static bool comp(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), comp);
        
        int endTime = INT_MIN;
        int nonOverlapping = 0;
        vector<pair<int,int>> nonOverlappingSubset;

        for(int i = 0; i<intervals.size(); i++) {
            if(intervals[i][0] >= endTime) {
                nonOverlapping++;
                nonOverlappingSubset.push_back({intervals[i][0], intervals[i][1]});
                endTime = intervals[i][1];
            }
        }
        return intervals.size() - nonOverlapping;

    }
};