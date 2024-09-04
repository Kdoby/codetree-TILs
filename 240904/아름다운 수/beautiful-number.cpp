#include <iostream>
#include <vector>
using namespace std;

int ans;

void backTracking(vector<int> v, int cnt[], int n) {
    if(v.size() == n) {
        for(int i=1;i<=4;++i) {
            if(cnt[i] % i !=0)
                return;
        }
        ++ans;
        return;
    }
    for(int i=1;i<=4;++i){
        if(v.back()==i || cnt[i] % i == 0) {
            cnt[i]++;
            v.push_back(i);
            backTracking(v, cnt, n);
            v.pop_back();
            cnt[i]--;
        }
    }  
}

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=4;++i) {
        int cnt[5] = {0,};
        vector<int> vec;
        vec.push_back(i);
        cnt[i]++;
        backTracking(vec, cnt, n);
    }
    cout<<ans;
    return 0;
}