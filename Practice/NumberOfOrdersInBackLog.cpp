#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<vector<int>>bpq;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>spq;
        
        int M = 1e9 + 7;
        for(int i=0;i<orders.size();i++)
        {
            vector<int>order=orders[i];
            if(order[2]==0)
            {
                while(!spq.empty() && spq.top()[0]<=order[0])
                {
                    vector<int>sellingBatch=spq.top();spq.pop();
                    if(sellingBatch[1]>=order[1])
                    {
                        sellingBatch[1]-=order[1];
                        order[1]=0;
                        if(sellingBatch[1]>0)
                            spq.push(sellingBatch);
                        break;
                    }
                    else
                    {
                        order[1]-=sellingBatch[1];
                    }
                }
                if(order[1]>0)
                    bpq.push(order);
                    
            }
            else
            {
                while(!bpq.empty() && bpq.top()[0]>=order[0])
                {
                    vector<int>buyingBatch=bpq.top();bpq.pop();
                    if(buyingBatch[1]>=order[1])
                    {
                        buyingBatch[1]-=order[1];
                        order[1]=0;
                        if(buyingBatch[1]>0)
                            bpq.push(buyingBatch);
                        break;
                    }
                    else
                    {
                        order[1]-=buyingBatch[1];
                    }
                }
                if(order[1]>0)
                    spq.push(order);
                    
            }
        }
        int res=0;
        while(!bpq.empty())
        {
            res=(res%M + bpq.top()[1]%M)%M;
            bpq.pop();
        }
        
        while(!spq.empty())
        {
            res=(res%M + spq.top()[1]%M)%M;
            spq.pop();
        }
        return res;
    }
};