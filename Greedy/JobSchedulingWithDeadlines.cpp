#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
// https://www.interviewbit.com/blog/job-sequencing-with-deadlines/

class Solution 
{
    public:
    bool static comp(Job j1, Job j2) {
        return j1.profit > j2.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        
        // sort by decreasing profit
        sort(arr, arr+n, comp);
        
        // set in the decreasing order of elements
        set<int, greater<int>> s;
        
        int maxDeadline = -1;
        for(int i = 0; i<n; i++) maxDeadline = max(maxDeadline, arr[i].dead);
        

        // insert all the deadlines from maxDeadline to 1 
        for(int i = maxDeadline; i>0; i--) {
            s.insert(i);
        }
        
        int maxProfit = 0;
        int jobCount = 0; 
        
        for(int i = 0; i<n; i++) {
            
            // if set size is 0 OR curDeadline is less than minimumDeadline in the set 
            if(s.size() == 0 || arr[i].dead < *s.rbegin()) continue;
            
            // here lower_bound will return a number equalTo or lessThan the number passed as the set is decreasing
            int availableSlot = *s.lower_bound(arr[i].dead);
            maxProfit += arr[i].profit;
            jobCount++;
            
            // remove this deadline slot
            s.erase(availableSlot);
        }
        
        return {jobCount, maxProfit};
    } 
};

int main() {

}