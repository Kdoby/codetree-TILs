#include <iostream>
#include <cmath>

using namespace std;

int n, m;
int grid[20][20];
int max_gold = 0;

// 마름모 넓이
int GetArea(int k) {
    return k * k + (k + 1) * (k + 1);
}

// row, col = 중심점
int GetNumOfGold(int row, int col, int k) {
    int num_gold = 0;

    for(int i = 0; i < n; ++i) {
       for(int j = 0; j < n; ++j) {
        if((abs(i - row) + abs(j - col) <= k) && grid[i][j]) {
            num_gold++;
        }
       } 
    }

    return num_gold;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 전체를 커버하는 데에 필요한 k = 2 *( n - 1)
            for(int k = 0; k <= 2 * (n - 1); k++) {
                int num_gold = GetNumOfGold(i, j, k);
                if(num_gold * m >= GetArea(k)) {
                    max_gold = max(max_gold, num_gold);
                } 
            }
        }
    }

    cout << max_gold;

    return 0;
}
