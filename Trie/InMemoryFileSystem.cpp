#include<bits/stdc++.h>
using namespace std;


class TrieNode {
    public:

    string name;
    unordered_map<string, TrieNode*> child;
    bool isFile; 
    string content;

    TrieNode() {
        this->name = "";
        this->child = {};
        this->isFile = false;
        this->content = "";
    }

    TrieNode(string name) {
        this->name = name;
        this->child = {};
        this->isFile = false;
        this->content = {};
    }

    bool isPresent(string path) {
        return child.find(path) != child.end();
    }

    TrieNode* getNode(string path) {
        return child[path];
    }

    void createNode(string path) {
        child[path] = new TrieNode(path);
    }

};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode();
        }

        TrieNode* addPath(vector<string> dirs) {
            TrieNode* temp = root;
            for(auto dir : dirs) {

                if(temp->isPresent(dir)) {
                    temp = temp->getNode(dir);
                    continue;
                }

                temp->createNode(dir);
                temp = temp->child[dir];
            }

            return temp;
        }

        void addContent(vector<string> dirs, string content) {
            
            TrieNode* curNode = addPath(dirs);
            curNode->isFile = true;
            curNode->content += content;
        }
        
        string readContent(vector<string> dirs) {
            
            TrieNode* curNode = getLastNode(dirs);
            if(curNode == NULL || curNode == root) return "";

            if(curNode->isFile) {
                return curNode->content;
            }
            return "";
        }

        TrieNode* getLastNode(vector<string> paths) {
            TrieNode* curNode = root;
            
            for(auto path : paths) {
                if(curNode->isPresent(path)) {
                    curNode = curNode->getNode(path);
                } else {
                    return NULL;
                }
            }
            return curNode;
        }

        vector<string> getDirPaths(vector<string>paths) {
            vector<string> fileNames;
            
            TrieNode* curNode = getLastNode(paths);
            
            if(curNode == root || curNode == NULL) {
                return fileNames;
            }

            if(curNode->isFile) {
                return {curNode->name};
            }
            for(auto it = curNode->child.begin(); it!= curNode->child.end(); it++) {
                fileNames.push_back(it->first);
            }

            sort(fileNames.begin(), fileNames.end());
            return fileNames;
        }

        vector<string> getRootPaths() {
            vector<string> res;
            for(auto it = root->child.begin(); it!=root->child.end(); it++) {
                res.push_back(it->first);
            }
            sort(res.begin(), res.end());
            return res;
        }
};

class FileSystem {
public:
    Trie* trie; 
    
    FileSystem() {
        trie = new Trie();
    }
    
    vector<string> ls(string path) {
        
        if(path.size() == 1) {
            return trie->getRootPaths();
        }
        vector<string> dirs = splitPath(path);
        return trie->getDirPaths(dirs);
    }

    vector<string> splitPath(string path) {
        string token;
        int pos;
        string tempPath = path;
        vector<string> dirs;

        if(path.size() == 1) {
            return dirs;
        }
        
        tempPath.erase(0, 1);
        while(1) {
            pos = tempPath.find("/");
            if(pos == string::npos) break;

            token = tempPath.substr(0, pos);
            
            dirs.push_back(token);
            tempPath.erase(0, pos + 1);
        }
        if(tempPath.length() > 0)
            dirs.push_back(tempPath);
        return dirs;
    }
    
    void mkdir(string path) {
        vector<string> dirs = splitPath(path);
        trie->addPath(dirs);
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> dirs = splitPath(filePath);
        trie->addContent(dirs, content);
    }
    
    string readContentFromFile(string filePath) {
        vector<string> dirs = splitPath(filePath);
        return trie->readContent(dirs);
    }
};
// https://leetcode.com/problems/design-search-autocomplete-system/description/

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */