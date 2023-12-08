#include<bits/stdc++.h>

using namespace std;

int uniqueSongs(vector<int> playlist) {
    unordered_map<int,int> mp;
    int left = 0;
    int right = 0;
    int maxi = 0;

    while(right < playlist.size()) {
        if(mp.find(playlist[right]) == mp.end()) {
            mp[playlist[right]] = right;
            right++;
        } else {
            maxi = max(maxi, right - left);
            if(mp[playlist[right]]+1 > left)
                left = mp[playlist[right]]+1;
            mp[playlist[right]] = right;
            right++;
        }
    }
    maxi = max(maxi, right-left);
    return maxi;

}

int main() {
    int n;
    cin >> n;
    vector<int> playlist; 

    for(int i = 0; i<n; i++) {
        int x;
        cin>>x;
        playlist.push_back(x);
    }
    cout << uniqueSongs(playlist);

    return 0;
}
