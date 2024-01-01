#include<bits/stdc++.h>
using namespace std;

vector<int> findAns(vector<int> trucks, vector<int> items) {
    set<int> s;
    unordered_map<int, set<int>> mp;

    for(int i = 0; i<trucks.size(); i++) {
        mp[trucks[i]].insert(i);
        s.insert(trucks[i]);
    }
    vector<int> ans;

    for(int i = 0; i<items.size(); i++) {
        
        if(s.size() == 0 || items[i] >= *(s.rbegin())) {
            ans.push_back(-1);
            continue;
        }

        int ub = *s.upper_bound(items[i]);
        
        set<int> tempSet = mp[ub];
        int idx = *(tempSet.begin());
        
        // remove comment if the trucks have to be removed once the item is loaded in the truck

        // tempSet.erase(idx);
        // mp[ub] = tempSet;
        
        // if(tempSet.size() == 0) {
        //     s.erase(ub);
        // }
        ans.push_back(idx);
    }
    
    return ans;
}

int main() {
    vector<int> trucks = {2, 4, 2, 5, 1, 5, 23, 5, 2, 54, 6, 6};
    vector<int> items = {1, 1, 2, 4, 2, 5, 3, 3, 10, 33};

    vector<int> ans = findAns(trucks, items);
    for(auto i : ans) cout << i << " ";
    cout << endl;

}