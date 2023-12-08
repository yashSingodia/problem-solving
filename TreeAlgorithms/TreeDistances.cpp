#include<bits/stdc++.h>

using namespace std;

// int dfs(vector<int> tree[], int parent, int src, int &res) {

//     // if(tree[src].size() == 1) {
//     //     return 0;
//     // }
    
//     int maxHeight = -1;
    
//     vector<int> heightOfChildNodes;
//     for(auto edge : tree[src]) {
//         if(edge!= parent) {
//             int heighOfChild = dfs(tree, src, edge, res);
//             heightOfChildNodes.push_back(heighOfChild);
//             maxHeight = max(maxHeight, heighOfChild);
//         }
//     }
//     int temp = 1 + maxHeight;
//     int ans = temp;
//     if(heightOfChildNodes.size() == 0) {
//         ans = max(temp, 0);
//     } else if(heightOfChildNodes.size() == 1) {
//         ans = max(temp, heightOfChildNodes[0]+1);
//     } else {
//         sort(heightOfChildNodes.begin(), heightOfChildNodes.end());
//         ans = max(temp, 2 + heightOfChildNodes[heightOfChildNodes.size() - 1] + 
//     heightOfChildNodes[heightOfChildNodes.size() - 2]);
//     }

//     res = max(res, ans);
//     return temp;
// }

void calculateHeight(vector<int> tree[], int src, int parent, vector<int>& heights) {
    
    int maxHeight = 0;
    bool isLeaf = 1;
    for(auto edge : tree[src]){
        if(edge != parent) {
            isLeaf = 0;
            calculateHeight(tree, edge, src, heights);
            maxHeight = max(maxHeight, heights[edge]);
        }
    }
    
    if(isLeaf == 1) {
        heights[src] = 0;
    } else {
        heights[src] = maxHeight + 1;    
    }
    
}
int calculateDiameter(vector<int> tree[], int src, int parent, int &res) {


    int maxDia = -1;
    vector<int> childNodesHeight;
    for(auto edge : tree[src]) {
        if(edge != parent) {
            int dia = calculateDiameter(tree, edge, src, res);
            maxDia = max(maxDia, dia);
            childNodesHeight.push_back(dia);
        }
    }

    int temp = 1 + maxDia;
    int ans = temp;

    if(childNodesHeight.size() == 0) {
        ans = max(ans, 0);
    } else if(childNodesHeight.size() == 0) {
        ans = max(ans, 1 + childNodesHeight[0]);
    } else {
        sort(childNodesHeight.begin(), childNodesHeight.end());
        ans = max(ans, 2 + childNodesHeight[childNodesHeight.size() - 1] + childNodesHeight[childNodesHeight.size() - 2]);
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

    vector<int> heights(n+1, 0);
    calculateHeight(tree, 1, -1, heights);

    int dia = 0;
    calculateDiameter(tree, 1, -1, dia);

    for(int i = 1; i<=n ;i++) {
        cout <<  heights[i] << " ";
    }

    for(int i = 1; i<=n ;i++) {
        cout << dia - heights[i] << " ";
    }
 
    return 0;
}





