#include<bits/stdc++.h>

using namespace std;

int maxApplicants(vector<int> applicants, vector<int> apartments, int n, int m, int k) {
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int apart = 0;
    int numApplicants = 0;
    int i = 0;
    while(i < n && apart < m) {
        if((applicants[i] - k <= apartments[apart]) && (applicants[i] + k >= apartments[apart])) {
            numApplicants++;
            i++;
            apart++;
        } else if(apartments[apart] > applicants[i]){
            i++;
        } else {
            apart++;
        }
        
    }
    return numApplicants;
}
int main() {
    int n, m, k; cin>>n >> m >> k;
    vector<int> applicants;
    vector<int> apartments;
    
    for(int i = 0; i<n; i++) {
        int x;
        cin >> x;
        applicants.push_back(x);
    }
    for(int i = 0; i<m; i++) {
        int x;
        cin >> x;
        apartments.push_back(x);
    }

    cout << maxApplicants(applicants, apartments, n, m, k);
    return 0;
}
