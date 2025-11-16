#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int MAXL = 26;
    int MAXS = 351;

    vector<vector<int>> dp(MAXL + 1, vector<int>(MAXS + 1, 0));
    dp[0][0] = 1;
    for(int v = 1; v <= 26; ++v){
        for(int l = MAXL; l >= 1; --l){
            for(int s = v; s <= MAXS; ++s)
                dp[l][s] += dp[l - 1][s - v];
        }
    }
    int L, S, tc = 1;
    while(cin >> L >> S && L && S){
        int ans = 0;
        int minSum = L * (L + 1) / 2;
        int maxSum = (53 - L) * L / 2;
        if(S >= minSum && S <= maxSum){
            if(S <= MAXS)
                ans = dp[L][S];
            else    ans = 0;
        }
        cout << "Case " << tc++ << ": " << ans << '\n';
    }
    return 0;
}