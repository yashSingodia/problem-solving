#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        string val;
        Node* next;
        
        Node(string value) {
            val = value;
            next = NULL;
        }
};

class DisjointSet {
    public:
        unordered_map<Node*, Node*> parentOfNode;
        unordered_map<Node*, int> rankOfNode;
        unordered_set<Node*> cycles;
    
    DisjointSet() {
    }

    void setNodeParentToItself(Node* a) {
        parentOfNode[a] = a;
    }

    void setDefaultRank(Node* a) {
        rankOfNode[a] = 0;
    }

    bool nodeExistsInCycle(Node* node) {
        if(cycles.find(node) != cycles.end()) {
            return true;
        }
        return false;
    }

    Node* findByCompression(Node* element) {
        if(parentOfNode[element] == element) {
            return element;
        } 

        return parentOfNode[element] = findByCompression(parentOfNode[element]);
    }

    void unionByRank(Node* a, Node* b) {
        Node* parentA = findByCompression(a);
        Node* parentB = findByCompression(b);

        if(parentA == parentB) {
            cycles.insert(parentA);
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

class Graph {
    public:
        unordered_map<string, Node*> nodes; 
        DisjointSet ds;

        void addEdge(string u, string v) {
            Node* nodeU = getNode(u);
            Node* nodeV = getNode(v);

            nodeU->next = nodeV;
            ds.unionByRank(nodeU, nodeV);
        }

        Node* getNode(string val) {
            if(nodes.find(val) == nodes.end()) {
                nodes[val] = new Node(val);
                // default init
                ds.setNodeParentToItself(nodes[val]);
                ds.setDefaultRank(nodes[val]);
            } 
            return nodes[val];
        }
    
};

int doLinkedListsIntersect(unordered_set<string>startNodes, Graph graph) {
    DisjointSet dis = graph.ds;
    unordered_set<Node*> visitedNodes;

    for(auto startNode : startNodes) {
        Node* parentNode = dis.findByCompression(graph.getNode(startNode););
        if(dis.nodeExistsInCycle(parentNode)) {
            return 2;
        }
        if(visitedNodes.find(parentNode) != visitedNodes.end()) {
            return 0;
        }
        visitedNodes.insert(parentNode);
    }
    return 1;
}

int main() {
    
    string line;
    Graph graph;
  
    string sd("->");

    while (getline(cin, line)) {

        string s = line;
        int pos = s.find(sd);

        if (pos != string::npos) {

            auto arrow_pos = line.find("->");
            string u = line.substr(0, arrow_pos);
            string v = line.substr(arrow_pos + 2);
            graph.addEdge(u, v);

        } else {

            unordered_set<string>startNodes;
            size_t pos = 0;

            while (pos < line.size()) {
                auto comma_pos = line.find(",", pos);
                if (comma_pos == string::npos)
                comma_pos = line.size();

                startNodes.insert(line.substr(pos, comma_pos - pos));
                pos = comma_pos + 1;
            }

            int result = doLinkedListsIntersect(startNodes, graph);

            if (result == 2) {
                cout << "Error Thrown!" << endl;
            } else if (result) {
                cout << "False" << endl;
            } else { 
                cout << "True" << endl;
            }
        }
  }


}