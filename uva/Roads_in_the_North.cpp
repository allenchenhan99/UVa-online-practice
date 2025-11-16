#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
vector<pair<int, int>> vp[MAXN];
int ans = 0;

int dfs(int start, int end){
    int diameter = 0;
    for(int i = 0; i < vp[start].size(); ++i){
        int next = vp[start][i].first;
        int weight = vp[start][i].second;
        if(next == end)   continue;
        int tmp = dfs(next, start) + weight;
        ans = max(ans, diameter + tmp);
        diameter = max(diameter, tmp);
    }
    return diameter;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int u, v, w;
    int root = -1;
    while(cin >> u >> v >> w){
        vp[u].push_back({v, w});
        vp[v].push_back({u, w});
        if(root == -1)
            root = u;
    }
    dfs(root, 0);
    cout << ans << '\n';
    return 0;
}