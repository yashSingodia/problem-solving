#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class DisjointSet {
    public:
        vector<int> parentOfNode;
        vector<int> rankOfNode;
        int capacity;
    
    DisjointSet(int capacity) {
        capacity = capacity;
        parentOfNode = vector<int>(capacity, -1);
        rankOfNode = vector<int>(capacity, 0);
    }

    int findByCompression(int element) {
        if(parentOfNode[element] == -1) {
            return element;
        } 
        return parentOfNode[element] = findByCompression(parentOfNode[element]);
    }

    void unionByRank(int a, int b) {
        int parentA = findByCompression(a);
        int parentB = findByCompression(b);

        if(parentA == parentB) {
            return;
        }
        if(rankOfNode[parentA] < rankOfNode[parentB]) {
            parentOfNode[parentA] = parentB;
        } else if(rankOfNode[parentA] > rankOfNode[parentB]) {
            parentOfNode[parentB] = parentA;
        } else {
            parentOfNode[parentB] = parentA;
            rankOfNode[parentA]++;
        }
    }

};

int findMinimumRoads(vector<pair<int,int>> roads, int n, int m, vector<pair<int,int>> &ans)
 {
    DisjointSet ds(n);
    for(auto road : roads) {
        ds.unionByRank(road.first, road.second);
    }

    int currentCity = -1;
    int disconnectedComponents = 0;
    for(int i = 0; i<n; i++) {
        if(ds.parentOfNode[i] == -1) {

            if(currentCity == -1) {
                currentCity = i;
            } else {    
                ans.push_back({currentCity+1, i+1});
                ds.unionByRank(currentCity, i);
                currentCity = i;
            }

            disconnectedComponents++;
        }
    }
    return disconnectedComponents - 1;
 }

// or can be done by dfs

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> roads; 
    for(int i = 0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        roads.push_back({x, y});
    }
    vector<pair<int,int>> ans; 
    int disconnectedComponents = findMinimumRoads(roads, n, m, ans);
    cout << disconnectedComponents << endl;
    for(auto i : ans) {
        cout << i.first << " " << i.second << endl;
    }
}