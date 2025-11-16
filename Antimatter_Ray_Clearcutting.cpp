#include <bits/stdc++.h>
using namespace std;

struct P{
    int x, y;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc = 1;
    int T, n, m;
    cin >> T;
    while(T--){
        cin >> n >> m;
        vector<P> arr(n);
        for(int i = 0; i < n; ++i)
            cin >> arr[i].x >> arr[i].y;
        
        vector<int> masks;
        masks.reserve(n * (n + 1) / 2);
        for(int i = 0; i < n; ++i)
            masks.push_back(1 << i);
        
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int dx = arr[j].x - arr[i].x;
                int dy = arr[j].y - arr[i].y;
                int mask = 0;
                for(int k = 0; k < n; ++k){
                    int dxk = arr[k].x - arr[i].x;
                    int dyk = arr[k].y - arr[i].y;
                    if(dx * dyk - dy * dxk == 0)
                        mask |= (1 << k);
                }
                masks.push_back(mask);
            }
        }
        sort(masks.begin(), masks.end());
        masks.erase(unique(masks.begin(), masks.end()), masks.end());

        int FULL = 1 << n, INF = 1e9;
        vector<int> dp(FULL, 1e9);
        dp[0] = 0;

        for(int mask = 0; mask < FULL; ++mask){
            if(dp[mask] == INF) continue;
            for(int L : masks){
                int nxt = mask | L;
                dp[nxt] = min(dp[nxt], dp[mask] + 1);
            }
        }
        int ans = INF;
        for(int mask = 0; mask < FULL; ++mask){
            if(__builtin_popcount(mask) >= m)
                ans = min(ans, dp[mask]);
        }
        cout << "Case #" << tc++ << ":\n" << ans << "\n";
        if (T) cout << "\n";
    }
    return 0;
}