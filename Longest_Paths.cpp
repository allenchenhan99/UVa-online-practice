#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<vector<int>> adj;     // 有向圖鄰接串列
vector<int> dpLen;           // 從節點 u 出發的最長路徑長度（邊數）
vector<int> bestEnd;         // 從節點 u 出發的最長路徑「終點」(若同長度取編號較小)
vector<char> vis;            // 記憶化的拜訪標記

// 回傳：從 u 出發的 (最長路徑長度, 最佳終點編號)
pair<int,int> dfs(int u){
    if(vis[u])
        return {dpLen[u], bestEnd[u]};
    vis[u] = 1;

    int bestLenHere = 0;      // 沒有出邊時，長度為 0（只在 u 停下）
    int bestEndHere = u;      // 終點就是自己

    for (int v : adj[u]) {
        auto [lenV, endV] = dfs(v);
        int candLen = 1 + lenV;   // 走到 v 的最長 + 這條邊
        int candEnd = endV;

        if (candLen > bestLenHere) {
            bestLenHere = candLen;
            bestEndHere = candEnd;
        } else if (candLen == bestLenHere && candEnd < bestEndHere) {
            bestEndHere = candEnd; // 長度相同，終點取較小編號
        }
    }

    dpLen[u]  = bestLenHere;
    bestEnd[u]= bestEndHere;
    return {dpLen[u], bestEnd[u]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    while (cin >> n && n) {
        cin >> s;

        adj.assign(n + 1, {});
        while(1){
            int p, q;
            cin >> p >> q;
            if(p == 0 && q == 0) break;
            adj[p].push_back(q);
        }

        dpLen.assign(n + 1, 0);
        bestEnd.assign(n + 1, 0);
        vis.assign(n + 1, 0);

        auto [L, t] = dfs(s);

        cout << "Case " << tc++ << ": The longest path from " << s
             << " has length " << L << ", finishing at " << t << ".\n";
        cout << "\n";
    }
    return 0;
}
