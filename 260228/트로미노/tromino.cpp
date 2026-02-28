#include <iostream>

using namespace std;

int n, m;
int grid[200][200];
int ans = 0;

void calculate_block1(int row, int col) {
    int cur = grid[row][col];
    int sum = cur;
    if(row + 1 < n && col + 1 < m) {
        sum = cur + grid[row + 1][col] + grid[row + 1][col + 1];
        ans = max(ans, sum);
        sum = cur + grid[row][col + 1] + grid[row + 1][col];
        ans = max(ans, sum);
    }
    if(row + 1 < n && col - 1 > 0) {
        sum = cur + grid[row + 1][col] + grid[row][col - 1];
        ans = max(ans, sum);
        sum = cur + grid[row + 1][col] + grid[row + 1][col - 1];
        ans = max(ans, sum);
    }
}

void calculate_block2(int row, int col) {
    int cur = grid[row][col];
    int sum = cur;
    if(col - 1 > 0 && col + 1 < m) {
        sum = cur + grid[row][col - 1] + grid[row][col + 1];
        ans = max(ans, sum);
    }
    if(row - 1 > 0 && row + 1 < n) {
        sum = cur + grid[row - 1][col] + grid[row + 1][col];
        ans = max(ans, sum);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            calculate_block1(i, j);
            calculate_block2(i, j);
        }
    }
    cout << ans;
    return 0;
}
