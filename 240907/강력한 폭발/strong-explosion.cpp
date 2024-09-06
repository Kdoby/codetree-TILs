#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[20][20];
int xpos[3][4] = {
                {0, 0, 0, 0},
                {0, 0, -1, 1},
                {-1, 1, -1, 1}
                };
int ypos[3][4] = {
                {-1, -2, 1, 2},
                {-1, 1, 0, 0},
                {-1, -1, 1, 1}
                };
int ans;
vector<pair<int, int>> vec;

void Backtracking (int idx, int param[][20], int cnt) {
    if(idx >= vec.size()) {
        ans = max(ans, cnt);
        return;
    }
    ++cnt;
    for(int i=0; i<3; ++i) {
        int tmp=0;
        vector<pair<int, int>> tmpV;
        for(int j=0; j<4; ++j) {
            int yy = vec[idx].first + ypos[i][j];
            int xx = vec[idx].second + xpos[i][j];
            if(0<=yy && yy<n && 0<=xx && xx<n){
                if(param[yy][xx]==0) {
                    param[yy][xx]=-1;
                    tmpV.push_back(make_pair(yy, xx));
                    ++cnt;
                    ++tmp;
                }
            }
        }
        Backtracking(idx + 1, param, cnt);
        cnt -= tmp;
        for(int k=0; k<tmpV.size(); ++k){
            param[tmpV[k].first][tmpV[k].second] = 0;
        }
    }
}

int main() {
    cin>>n;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin>>arr[i][j];
            if(arr[i][j] == 1) {
                vec.push_back(make_pair(i, j));
            }
        }
    }    
    Backtracking(0, arr, 0);
    cout<<ans;
    return 0;
}