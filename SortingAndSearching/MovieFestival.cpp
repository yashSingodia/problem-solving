#include<bits/stdc++.h>

using namespace std;

bool comparator(pair<int,int> a, pair<int,int> b) {
    return b.second > a.second;
}
int maxMovies(vector<pair<int, int>> movies) {
    sort(movies.begin(), movies.end(), comparator);

    int moviesCnt = 1;
    int endTime = movies[0].second;
    for(int i = 1; i<movies.size(); i++) {
        if(movies[i].first >= endTime) {
            endTime = movies[i].second;
            moviesCnt++;
        }
    }
    return moviesCnt;
}

int main() {
    int n; cin>>n;
    vector<pair<int, int>> movies(n);
    for(int i = 0; i<n; i++) {
        int x, y;
        cin >> movies[i].first >> movies[i].second;
    }
    cout << maxMovies(movies);
    return 0;
}
