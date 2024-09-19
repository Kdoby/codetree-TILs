#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int dp[1000];
vector<pair<int, int>> vec;
int ans;

int main() {
    cin >> n;
    for(int i=0; i<n; ++i) {
        dp[i] = 1;
    }
    for(int i=0; i<n; ++i) {
        int a, b;
        cin>>a>>b;
        vec.push_back(make_pair(a, b));
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<n; ++i) {
        for(int j=i + 1; j<n; ++j) {
            if(vec[i].second < vec[j].first) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    for(int i=0; i<n; ++i) {
        ans = max(ans, dp[i]);
    }
    cout<<ans;
    return 0;
}