#include <iostream>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int ans = 0;
    
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i + 3 > N || j + 3 > N) continue;

            int t = 0;
            for(int k = i; k < i + 3; ++k) {
                for(int l = j; l < j + 3; ++l) {
                    t += grid[k][l];
                }
            }
            ans = max(ans, t);
        }
    }

    cout << ans;
    return 0;
}
