#include <iostream>
#include <vector>
using namespace std;

void backTracking(vector<int> v, int k, int n) {
    if(v.size() == n) {
        for(int i=0; i<v.size(); ++i){
            cout<<v[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=k;++i) {
        v.push_back(i);
        backTracking(v, k, n);
        v.pop_back();
    }
}

int main() {
    int n, k;
    cin>>k>>n;
    for(int i=1;i<=k;++i){
        vector<int> vec;
        vec.push_back(i);
        backTracking(vec, k , n);
    }
    return 0;
}