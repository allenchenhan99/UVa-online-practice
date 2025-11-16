#include <bits/stdc++.h>
using namespace std;

vector<int> pre;

void build(int l, int r){
    if(l > r)   return;
    int root = pre[l];
    int idx = l + 1;
    while(idx <= r && pre[idx] < root)  idx++;
    build(l + 1, idx - 1);
    build(idx, r);
    cout << root << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    while(cin >> x){
        pre.push_back(x);
    }
    build(0, pre.size() - 1);
    return 0;
}