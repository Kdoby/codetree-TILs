#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vec;
bool compare (pair<int, int> lhs, pair<int, int> rhs) {
    return lhs.second < rhs.second;
}

int ans;
void Backtracking(vector<pair<int, int>> v, int now, int cnt) {
    ans = max(ans, cnt);
    if(now + 1 == vec.size()) {
        return;
    }
    for(int i=now+1; i<vec.size(); ++i) {
        // 겹치지 않으면 push
        if(vec[now].second < vec[i].first) {
            v.push_back(make_pair(vec[i].first, vec[i].second));
            Backtracking(v, i, v.size());
            v.pop_back();
        }
    }   
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x1, x2; 
        cin>>x1>>x2;
        vec.push_back(make_pair(x1, x2));
    }
    sort(vec.begin(), vec.end(), compare);
    for(int i=0; i<n; ++i) {
        vector<pair<int, int>> v;
        v.push_back(make_pair(vec[i].first, vec[i].second));
        Backtracking(v, i, 1);
    }
    cout<<ans;
    return 0;
}