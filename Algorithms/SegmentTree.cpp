#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> segTree;

    public:
        SegmentTree(int capacity) {
            segTree.resize(4 * capacity + 1);
        }

    // O(N)
    void build(int index, int low, int high, vector<int> arr) {
        if(low == high) {
            segTree[index] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid+1, high, arr);

        segTree[index] = min(segTree[2*index+1], segTree[2*index+2]);
    }

    // O(logN)
    int query(int index, int low, int high, vector<int> arr, int leftRange, int rightRange) {
        // no overlap
        // (low, high) [leftRange, rightRange]
        // [leftRange, rightRange] (low, high)
        if(high < leftRange || low > rightRange) {
            return INT_MAX;
        }


        // Complete Overlap
        // [leftRange (low, high) rightRange]
        if(low >= leftRange && high <= rightRange) {
            return segTree[index];
        }

        // partial overlap
        int mid = low + (high - low) / 2;
        int left = query(2*index+1, low, mid, arr, leftRange, rightRange);
        int right = query(2*index+2, mid+1, high, arr, leftRange, rightRange);
        return min(left, right);
    }

    // O(logN)
    void update(int index, int low, int high, vector<int> arr, int i, int value) {
        if(low == high) {
            segTree[index] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if(i<=mid) {
            update(2*index+1, low, mid, arr, i, value);
        } else {
            update(2*index+2, mid+1, high, arr, i, value);
        }

        segTree[index] = min(segTree[2*index+1], segTree[2*index+2]);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0); 

    for(int i = 0; i<n; i++) {
        int x;
        cin>>x;
        arr[i] = x;
    }

    
    SegmentTree segTree(n);

    return 0;
}
