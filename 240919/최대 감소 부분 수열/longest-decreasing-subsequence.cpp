#include <iostream>
#include <vector>
using namespace std;

int N;
int dp[1000];
vector<int> vec;
int ans;

int main() {
    cin >> N;
    for(int i=0; i<N; ++i) {
        dp[i] = 1;
    }
    for(int i=0; i<N; ++i) {
        int n;
        cin>>n;
        vec.push_back(n);
    }
    for(int i=0; i<N; ++i) {
        for(int j=i+1; j<N; ++j) {
            if(vec[j] < vec[i]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    for(int i=0; i<N; i++) {
        ans = max(ans, dp[i]);
    }
    cout<<ans;
    return 0;
}