#include<bits/stdc++.h>

using namespace std;

class DisjointSet {
    private:
        unordered_map<string, string> parent;
        unordered_map<string, int> rank;
    
    public:
        DisjointSet() {}

        void initializeParent(string ele) {
            if(parent.find(ele) == parent.end()) {
                parent[ele] = ele;
            }
        }

        string findByPathCompression(string ele) {
            if(parent[ele] == ele) {
                return ele;
            }
            return parent[ele] = findByPathCompression(parent[ele]);
        }

        void unionByRank(string a, string b) {
            string parent_a = findByPathCompression(a);
            string parent_b = findByPathCompression(b);

            if(parent_a == parent_b) {
                return;
            }

            if(rank[parent_a] > rank[parent_b]) {
                parent[parent_b] = parent_a;
            } else if (rank[parent_a] < rank[parent_b]) {
                parent[parent_a] = parent_b;
            } else {
                parent[parent_b] = parent_a;
                rank[parent_b]++;
            }
        }
};

unordered_set<string> reducedQueries(vector<vector<string>> synonyms, vector<string> queries, DisjointSet* ds) {
    vector<string> result;
    unordered_set<string> uniqueStrings;
    string curResult = "";

    for(int i = 0; i<queries.size(); i++) {
        string q = queries[i];
        curResult = "";
        
        int pos;
        string token;

        while(1) {
            pos = q.find(" ");
            if(pos == string::npos) break;

            token = q.substr(0, pos);
            curResult = "";

            curResult += ds->findByPathCompression(token);
            curResult += " ";

            q.erase(0, pos + 1);
        }

        curResult += ds->findByPathCompression(q);

        uniqueStrings.insert(curResult);
    }
    
    return uniqueStrings;
}


int main() {
    // Given a list of string pairs of synonyms, and a list of string queries(containing multiple words per query).
    //  Reduce the number of queries to the minimum.

    // Example: synonyms: ["get", "bring"], ["water", "liquid"],
    // query: ["get water", "bring water"]
    // reduced_queries : ["get water"]
    // Here, we can replace "bring" with "get" or "get" with "bring". Then, the queries list will have only one unique query.

    vector<vector<string>> synonyms;
    synonyms.push_back({"get", "bring"});
    synonyms.push_back({"water", "liquid"});


    DisjointSet* ds = new DisjointSet();
    for(int i = 0; i<synonyms.size(); i++) {
        string a = synonyms[i][0];
        string b = synonyms[i][1];

        ds->initializeParent(a);
        ds->initializeParent(b);

        ds->unionByRank(a, b);
    }
    
    
    vector<string> queries;
    queries.push_back("get water");
    queries.push_back("bring water");

    unordered_set<string> redQueries = reducedQueries(synonyms, queries, ds);
    for(auto s : redQueries) cout << s << endl;
    
    return 0;

}