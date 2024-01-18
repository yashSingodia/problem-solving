#include<bits/stdc++.h>

using namespace std;

// Resource - https://www.youtube.com/watch?v=8B-LfpLxh2U
// https://www.youtube.com/watch?v=7Sm0o5lMmfY
// Ques -  https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii/description/

void fillLps(string text, vector<int> &lpsCache) {
    int i = 1, len = 0;
    lpsCache[0] = 0;
        
    while(i < text.size()) {
        if(text[i] == text[len]) {
            len++;
            lpsCache[i] = len;
            i++;
        } else {
            if(len==0) {
                lpsCache[i] = 0;
                i++;
            }
            else {
                len = lpsCache[len-1];
            }
        }
    }
}

void patternMatch(string text, string pattern) {
    
    // find lps of pattern
    vector<int> lpsCache(pattern.length(), 0);
    fillLps(pattern, lpsCache);
    

    int i = 0; int j = 0;
    int lenText = text.length();
    
    while(i<lenText) {
        if(text[i] == pattern[j]) {
            i++; j++;
            if(j == pattern.length()) {  
                cout << "matched index: " << i - pattern.length() << endl;
                j = lpsCache[j-1];
            }
        } else {
            
            if(j==0) i++;
            else {
                j = lpsCache[j-1];

            }
        }
    }
    
}

int main() {
    string pattern = "ababa", text = "ababcababaad";
    // cin >> text >> pattern;

    patternMatch(text, pattern);
    
    return 0;

}
