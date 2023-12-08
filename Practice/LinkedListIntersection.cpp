#include<unordered_map>
#include<unordered_set>
#include<iostream>

using namespace std;

class Node {
  public: string val;
  Node * next;
  Node(string value): val(value),
  next(nullptr) {}

};

class Graph {
  public: unordered_map < string,
  Node * > nodes;
  void addEdge(string u, string v) {
    Node * node_u = getNode(u);
    Node * node_v = getNode(v);
    node_u -> next = node_v;

  }

  Node * getNode(string val) {
    if (nodes.find(val) == nodes.end()) {
      nodes[val] = new Node(val);
    }

    return nodes[val];
  }

};

Node * detectCycle(Node * node) {
  Node * slow = node;
  Node * fast = node;

  while (fast && fast -> next) {
    slow = slow -> next;
    fast = fast -> next -> next;

    if (fast == slow)
      return slow;
  }

  return nullptr;
}

int traverseSLL(Node * node, unordered_set & visited) {

  Node * intersection = detectCycle(node);
  if (intersection)
    return 2;

  while (node) {
    if (visited.find(node -> val) != visited.end())
      return 0;
    visited.insert(node -> val);
    node = node -> next;
  }

  return 1;
}

int DoLinkedListsIntersect(unordered_set & startNodes, Graph & graph) {
  unordered_set visited;

  for (auto & startNode: startNodes) {
    Node * node = graph.getNode(startNode);
    int val = traverseSLL(node, visited);
    if (val == 2) return 2;
    if (val == 0) return 0;
  }
  return 1;
}

int main() {
  string line;
  Graph graph;
  unordered_set startNodes;
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
      unordered_set < string > startNodes;
      size_t pos = 0;

      while (pos < line.size()) {
        auto comma_pos = line.find(",", pos);
        if (comma_pos == string::npos)
          comma_pos = line.size();

        startNodes.insert(line.substr(pos, comma_pos - pos));
        pos = comma_pos + 1;
      }

      int result = DoLinkedListsIntersect(startNodes, graph);

      if (result == 2) {
        cout << "Error Thrown!" << endl;
      } else if (result) {
        cout << "False" << endl;
      } else
        cout << "True" << endl;
    }
  }
}