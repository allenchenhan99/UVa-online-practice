#include <bits/stdc++.h>
using namespace std;

int preIdx;
vector<char> preorder, inorder;
unordered_map<char, int> pos;

void dfs(int L, int R, bool &first){
    if(L > R)   return;
    char root = pre[preIdx++];
    int k = pos[root];
    dfs(L, k - 1, first);
    dfs(k + 1, R, first);
    if(!first)   cout << ' ';
    cout << root;
    first = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        pre.assign(m, 0);
        inorder.assign(m, 0);
        for(int i = 0; i < m; ++i)
            cin >> preorder[i];
        for(int i = 0; i < m; ++i)
            cin >> inorder[i];

        pos.clear();
        pos.reserve(m);
        for(int i = 0; i < m; ++i)
            pos[inorder[i]] = i;
        preIdx = 0;
        bool first = true;
        dfs(0, n - 1, first);
        cout << '\n';
    }
    return 0;
}