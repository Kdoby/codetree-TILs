#include <iostream>
#include <vector>
using namespace std;

int n,m;
int arr[51][51];
int dp[51][51];
int ans;

void solve(int y, int x) {
    for(int i=y+1; i<=n; ++i) {
        for(int j=x+1; j<=m; ++j) {
            if(arr[i][j] > arr[y][x]) {
                dp[i][j] = max(dp[i][j], dp[y][x] + 1);
                solve(i, j);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            cin>>arr[i][j];
            dp[i][j] = 1;
        }
    }
    solve(1, 1);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}