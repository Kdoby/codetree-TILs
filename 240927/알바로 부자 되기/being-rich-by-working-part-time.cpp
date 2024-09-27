#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vec;
int pay[1000];
int dp[1000];
int ans;

int main() {
    int N;
    cin>>N;
    for(int i=0; i<N; ++i) {
        int s, e, p;
        cin>>s>>e>>p;
        vec.push_back(make_pair(s, e));
        pay[i] = p;
        dp[i] = p;
    }
    for(int i=0; i<N; ++i) {
        for(int j=i+1; j<N; ++j) {
            if(vec[i].second < vec[j].first) {
                dp[j] = max(dp[j], dp[i] + pay[j]);
                //cout<<dp[j]<<'\n';
            }
        }
    }
    for(int i=0; i<N; ++i) {
        //cout<<dp[i] <<" ";
        ans = max(ans, dp[i]);
    }
    //cout<<'\n';
    cout<<ans;
    return 0;
}