#include<bits/stdc++.h>

using namespace std;

class TrieNode {
    public: 

    TrieNode* charArray[26];
    bool isEndOfWord;

    TrieNode() {
        for(int i = 0; i<26; i++) charArray[i] = NULL;
        isEndOfWord = false;
    }

    bool isPresent(char ch) {
        return charArray[ch - 'a'] != NULL;
    }

    TrieNode* getNode(char ch) {
        return charArray[ch - 'a'];
    }

    void setNode(TrieNode* newNode, char ch) {
        charArray[ch - 'a'] = newNode;
    }

};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        
        for(int i = 0; i<word.size(); i++) {
            if(temp->isPresent(word[i]))  {
                temp = temp->getNode(word[i]);
            } else {
                TrieNode* newNode = new TrieNode();
                temp->setNode(newNode, word[i]);
                temp = temp->getNode(word[i]);
            }
        }
        temp->isEndOfWord = true;    
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        
        for(int i = 0; i<word.size(); i++) {
            if(temp->isPresent(word[i])) {
                temp = temp->getNode(word[i]);
            } else {
                return false;
            }
        }
        return temp->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        
        for(int i = 0; i<prefix.size(); i++) {
            if(temp->isPresent(prefix[i])) {
                temp = temp->getNode(prefix[i]);
            } else {
                return false;
            }
        }
        return true; 
    }
};

int main() {
    
}