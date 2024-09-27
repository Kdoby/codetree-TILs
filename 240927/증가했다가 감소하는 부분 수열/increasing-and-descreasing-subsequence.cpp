#include <iostream>
#include <vector>
using namespace std;

int N;
int up[1000];
int down[1000];
vector<int> vec;
int ans;

int main() {
    cin >> N;
    for(int i=0; i<N; ++i) {
        int num;
        cin>>num;
        vec.push_back(num);
        up[i] = down[i] = 1;
    }
    for(int i=0; i<vec.size(); ++i) {
        for(int j=i+1; j<vec.size(); ++j) {
            if(vec[i] > vec[j]) {
                int t = max(up[i] + 1, down[i] + 1);
                down[j] = max(down[j], t);
            }   
            else if(vec[i] < vec[j]) {
                up[j] = max(up[j], up[i] + 1);
            }
        }
    }
    for(int i=0; i<N; ++i) {
        int m = max(up[i], down[i]);
        ans = max(ans, m);
    }
    cout<<ans;
    return 0;
}