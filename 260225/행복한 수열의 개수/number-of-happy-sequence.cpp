#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
int ans_row[100][100];
int ans_col[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    // init
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans_row[i][j] = 1;
            ans_col[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(j != 0 && (grid[i][j] == grid[i][j - 1])) {
                ans_row[i][j] = ans_row[i][j - 1] + 1;                
            } 
            if(i != 0 && (grid[i][j] == grid[i - 1][j])) {
                ans_col[i][j] = ans_col[i - 1][j] + 1;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(ans_row[i][j] >= m) {
                ans++;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(ans_col[j][i] >= m) {
                ans++;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
