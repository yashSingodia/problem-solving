#include<bits/stdc++.h>

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

int main() {
    
}