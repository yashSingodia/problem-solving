#include<bits/stdc++.h>

using namespace std;

int dfs(vector<int> tree[], int parent, int src, int &res) {

    // if(tree[src].size() == 1) {
    //     return 0;
    // }
    
    int maxHeight = -1;
    
    vector<int> heightOfChildNodes;
    for(auto edge : tree[src]) {
        if(edge!= parent) {
            int heighOfChild = dfs(tree, src, edge, res);
            heightOfChildNodes.push_back(heighOfChild);
            maxHeight = max(maxHeight, heighOfChild);
        }
    }
    int temp = 1 + maxHeight;
    int ans = temp;
    if(heightOfChildNodes.size() == 0) {
        ans = max(temp, 0);
    } else if(heightOfChildNodes.size() == 1) {
        ans = max(temp, heightOfChildNodes[0]+1);
    } else {
        sort(heightOfChildNodes.begin(), heightOfChildNodes.end());
        ans = max(temp, 2 + heightOfChildNodes[heightOfChildNodes.size() - 1] + 
    heightOfChildNodes[heightOfChildNodes.size() - 2]);
    }

    res = max(res, ans);
    return temp;
}

int main() {
    int n;
    cin >> n;
    vector<int> tree[n+1];

    for(int i = 0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    int ans = 0;

    dfs(tree, -1, 1, ans);

    cout << ans << endl;
 
    return 0;
}



