#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        unordered_map<string, TrieNode*> child;
        bool isFile;
        string content;

        TrieNode() {
            child = {};
            isFile = false;
            content = "";
        }
        bool isPresent(string path) {
            return child.find(path) != child.end();
        }
        TrieNode* getNode(string path) {
            return child[path];
        } 
        void createNode(string path) {
            child[path] = new TrieNode();
        } 

};
class Trie{
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }

        void addDirectory(vector<string> pathDir) {
            TrieNode* curNode = root;
            for(string path : pathDir) {
                if(curNode->isPresent(path)) {
                    curNode = curNode->getNode(path);
                    continue;
                } else {
                    curNode->createNode(path);
                    curNode = curNode->getNode(path);
                }
            }
        }

        void addContent(vector<string> pathDir, string content) {
            TrieNode* curNode = root;

            for(int i = 0; i<pathDir.size(); i++) {
                string path = pathDir[i];
                if(i==pathDir.size() - 1) {
                    // if file is already present
                    if(curNode->isPresent(path)) {
                        
                        curNode = curNode->getNode(path);
                        if(curNode->isFile) {
                            curNode->content += content;
                        }
                        continue;
                    }

                    // if file is not present
                    curNode->createNode(path);
                    curNode = curNode->getNode(path);
                    curNode->isFile = true;
                    curNode->content = content;
                    continue;
                    
                }

                if(curNode->isPresent(path)) {
                    curNode = curNode->getNode(path);
                } else {
                    return;
                }
            }
         
        }

        string getContent(vector<string> pathDir) {
            TrieNode* curNode = root;
            
            for(int i = 0; i<pathDir.size(); i++) {
                string path = pathDir[i];
                
                // last dir
                if(i==pathDir.size() - 1) {
                    
                    if(curNode->isPresent(path)) {
                        curNode = curNode->getNode(path);
                        if(curNode->isFile) {
                            return curNode->content;
                        }
                   } else {
                        return "";
                   }
                }
                if(curNode->isPresent(path)) {
                    curNode = curNode->getNode(path);
                } else {
                    // no file found
                    return "";
                }
            }
        }
};
class FileSystem {
private:
    vector<string> splitPath(string path) {
        string token;
        int pos;
        string tempPath = path;
        vector<string> dirs;
        
        if(path.size() == 1)  {
            return dirs;
        }
        tempPath.erase(0, 1);

        while(1) {
            pos = tempPath.find("/");
            if(pos == string::npos) break;
            token = tempPath.substr(0, pos);
            dirs.push_back(token);
            tempPath.erase(0, pos+1);
        }
        if(tempPath.length() > 0) dirs.push_back(tempPath);
        return dirs;
    }
public:
    Trie* trie;
    FileSystem() {
        trie = new Trie();
    }
    
    void mkdir(string path) {
        vector<string> pathDir = splitPath(path);
        trie->addDirectory(pathDir);
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> pathDir = splitPath(filePath);
        trie->addContent(pathDir, content);
    }
    
    string readContentFromFile(string filePath) {
        vector<string> pathDir = splitPath(filePath);
        return trie->getContent(pathDir);
    }
};


int main() {
    FileSystem* obj = new FileSystem();

    
    obj->mkdir("/a/b/c");
    obj->addContentToFile("/a/b/c/d", "hello");
    string output = obj->readContentFromFile("/a/b/c/d");
    cout << "output " << output << endl;
}