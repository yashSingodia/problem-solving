#include<bits/stdc++.h>

using namespace std;

class TrieNode {
    public:

    unordered_map<string, TrieNode*> dirMap;
    int childCount;
    bool filePresent;

    TrieNode() {
        dirMap = {};
        childCount = 0;
        filePresent = false;
    }

    bool isPresent(string pathObject) {
        return dirMap.find(pathObject) != dirMap.end();
    }

    void createNode(string field) {
        dirMap[field] = new TrieNode();
    }

    TrieNode* getNode( string field) {
        return dirMap[field];
    }
};

class Trie {
    public:

    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }

    vector<string> splitField(string s) {
        vector<string> splitFields;
        int pos;
        string token;
        
        while(pos = s.find("/") != string::npos) {
            token = s.substr(0, pos);
            splitFields.push_back(token);
            s.erase(0, pos + 1);
        }
        splitFields.push_back(s);
        
        return splitFields;
    }

    void insert(vector<string> words) {
        TrieNode* curNode = root;

        for(auto word : words) {
            curNode->childCount++;
            if(curNode->isPresent(word)) {
                curNode = curNode->getNode(word);
            } else {
                curNode->createNode(word);
                curNode = curNode->getNode(word);
            }
        }
        curNode->filePresent = true;
    }

    void decrement(vector<string> words) {
        TrieNode* curNode = root;

        for(auto word : words) {
            
            if(!curNode->isPresent(word)) {
                return;
            } 
            curNode->childCount--;
            curNode = curNode->getNode(word);    
        }
        
    }

    string getPath(vector<string> words) {
        TrieNode* curNode = root;
        string str;

        for(auto word : words) {
            if(!curNode->isPresent(word)) {
                return "";
            }
            curNode = curNode->getNode(word);
            if(curNode->childCount == 0 || curNode->filePresent == true) {
                str+= word;
                return str;
            }
            str = str+ word + "/";
        }
        return "";
    }

};

vector<string> findSolution(vector<string> allFields, vector<string> selectedFiles) {
    vector<string> ans;
    Trie* trie = new Trie();

    // create the trie from all the directories
    for(string str : allFields) {
        vector<string> words = trie->splitField(str);
        trie->insert(words);
    }

    // remove the paths that are selected
    for(string str : selectedFiles) {
        vector<string> words = trie->splitField(str);
        trie->decrement(words);
    }
    
    string path;
    unordered_set<string> uniquePaths;
    
    // traverse the trie to find paths
    for(string str : selectedFiles) {
        vector<string> words = trie->splitField(str);
        path = trie->getPath(words);
        if(path.size() != 0) {
            uniquePaths.insert(path);
        }
    }
    for(auto it : uniquePaths) {
        ans.push_back(it);
    }

    return ans;
}

int main() {

    vector<string> allFiles;
    allFiles.push_back("a/b.txt");
    allFiles.push_back("b/c.txt");
    allFiles.push_back("b/d.txt");
    allFiles.push_back("c/e.txt");
    allFiles.push_back("c/f/a.txt");
    allFiles.push_back("c/f/b.txt");
    allFiles.push_back("c/g.txt");
    allFiles.push_back("d/a/b.txt");

    vector<string> selectedFiles;
    selectedFiles.push_back("b/c.txt");
    selectedFiles.push_back("b/d.txt");
    selectedFiles.push_back("c/e.txt");
    selectedFiles.push_back("c/f/a.txt");
    selectedFiles.push_back("c/f/b.txt");
    selectedFiles.push_back("d/a/b.txt");

    vector<string> result = findSolution(allFiles, selectedFiles);

    for(int i = 0; i<result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}