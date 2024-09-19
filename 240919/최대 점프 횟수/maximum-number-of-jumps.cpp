#include <iostream>
#include <vector>
using namespace std;

int n;
int dp[1000];
vector<pair<int, bool>> vec;
int ans;

int main() {
    cin>>n;
    for(int i=0; i<n; i++) {
        int num;
        cin>>num;
        vec.push_back(make_pair(num, false));
    }

    vec[0].second = true;
    for(int i=0; i<n; ++i) {
        if(vec[i].second) {
            for(int j=1; j<=vec[i].first; j++) {
                if(i + j < vec.size()) {
                    vec[i + j].second = true;
                    dp[i + j] = max(dp[i + j], dp[i] + 1);
                }
            }
        }
    }
    for(int i=0; i<n; ++i) {
        ans = max(ans, dp[i]);
    }
    cout<<ans;
    return 0;
}