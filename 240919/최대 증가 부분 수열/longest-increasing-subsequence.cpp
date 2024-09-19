#include <iostream>
#include <vector>
using namespace std;

int N;
int ans;
vector<int> vec;
int dp[1001];

int main() {
    cin>>N;
    for(int i=0;i<N;++i) {
        int num;
        cin>>num;
        vec.push_back(num);
    }
    for(int i=1;i<=N;++i) {
        dp[i] = 1;
    }
    for(int i=0; i<N; ++i) {
        int tmp = vec[i];
        int len = 1;
        for(int j=i+1; j<N; ++j) {
            if(tmp < vec[j]) {
                ++len;
                tmp = vec[j];
                dp[j] = max(dp[j], len);
            }
            else {
                continue;
            }
        }
    }
    for(int i=1; i<=N; ++i) {
        ans = max(ans, dp[i]);
    }
    cout<<ans;
    return 0;
}