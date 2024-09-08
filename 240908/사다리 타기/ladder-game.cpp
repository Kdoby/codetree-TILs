#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n,m;
int arr[16][12];
vector<pair<int, int>> vec;
int result[12];
int ans;

bool search (int param[][12], int start) {
    int s = start;
    int i = 1;
    while (i != 15) {
        if(param[i][s] == 1) {
            ++s;
        }
        else if(param[i][s] == 2) {
            --s;
        }
        ++i;
    }
    if(result[s] == 0) {
        result[s] = start;
        return true;
    }
    else if(result[s] != start) {
        return false;
    }
    else if(result[s] == start) {
        return true;
    }

}

void Backtracking(int p[][12], int idx1, int idx2, int now, int cnt) {
    bool is_fit = true;
    for(int i=1; i<=n; ++i) {
        if(!search(p, i)) {
            is_fit = false;
            break;
        }
    }
    if(is_fit) 
        ans = min(ans, cnt);
    p[idx1][idx2] = 1;
    p[idx1][idx2 + 1] = 2;
    ++cnt;
    for(int i=now + 1; i<vec.size(); ++i) {
        Backtracking(p, vec[i].second, vec[i].first, i, cnt);
        p[vec[i].second][vec[i].first] = 0;
        p[vec[i].second][vec[i].first + 1] = 0;
    }
}

int main() {
    cin>>n>>m;
    ans = m;
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        arr[b][a] = 1;
        arr[b][a+1] = 2;
        vec.push_back(make_pair(a, b));
    }
    for(int i=1; i<=n; ++i) {
        search(arr, i);
    }
    for(int i=0; i<vec.size(); ++i) {
        int p[16][12] = {0, };
        Backtracking(p, vec[i].second, vec[i].first, i, 0);
    }
    cout<<ans;
    return 0;
}