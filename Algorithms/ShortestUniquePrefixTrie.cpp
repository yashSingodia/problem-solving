#include<bits/stdc++.h>

class TrieNode {
    public: 
        TrieNode* charArray[26];
        int charCount[26];
            TrieNode() {
                for(int index = 0 ;index < 26; index++) {
                    charArray[index] = NULL;
                    charCount[index] = 0;
                }
            }
    
};

class Trie {
    TrieNode* root;
    public:
        Trie() {
            root = new TrieNode();
        }
        
        void insertString(string str) {
            TrieNode* currentNode = root;
            for(int i = 0; i<str.size(); i++) {
                int index = str[i] - 'a';
                
                if(currentNode->charArray[index] == NULL) {
                    // create new node  
                    TrieNode* newTrieNode = new TrieNode();
                    newTrieNode->charCount[index]++;
                    currentNode->charArray[index] = newTrieNode;
                    currentNode = currentNode->charArray[index];
                    
                } else {
                    currentNode = currentNode->charArray[index];
                    currentNode->charCount[index]++;
                }
            }
        }
        
        string findShortestPrefix(string str) {
            TrieNode* currentNode = root;
            string shortestPrefix = "";
            for(int i = 0; i<str.size(); i++) {
                int index = str[i] - 'a';
                // if(currentNode->charArray[index] == NULL ) return shortestPrefix;
                
                currentNode = currentNode->charArray[index];
                
                if(currentNode->charCount[index] == 1) {
                    shortestPrefix += str[i];
                    return shortestPrefix;
                } else {
                    shortestPrefix += str[i];
                }
                
            }
            
            return shortestPrefix;
            
        }
};

vector<string> prefix(vector<string> &A) {
    
    vector<string> solve;
    Trie* trie = new Trie();
    
    for(int i = 0; i<A.size(); i++) {
        trie->insertString(A[i]);
    }
    
    for(int i = 0; i<A.size(); i++) {
        solve.push_back(trie->findShortestPrefix(A[i]));
    }
    return solve;
}

int main() {

}