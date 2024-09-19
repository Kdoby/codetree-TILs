#include <iostream>
#include <vector>
using namespace std;

int N;
int ans;
vector<int> vec;
int dp[1000];

int main() {
    cin>>N;
    for(int i=0;i<N;++i) {
        int num;
        cin>>num;
        vec.push_back(num);
    }
    for(int i=0;i<N;++i) {
        dp[i] = 1;
    }
    for(int i=0; i<N; ++i) {
        for(int j=i+1; j<N; ++j) {
           if(vec[i] < vec[j]) {
                dp[j] = max(dp[j], dp[i] + 1);
           }
        }
    }
    for(int i=0; i<N; ++i) {
        ans = max(ans, dp[i]);
    }
    cout<<ans;
    return 0;
}