#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m, n, t;
    while(cin >> m >> n >> t){
        vector<int> dp(t + 1, -1);
        dp[0] = 0;
        for(int i = 0; i < t; ++i){
            if(dp[i] == -1) continue;
            if(i + m <= t)
                dp[i + m] = max(dp[i + m], dp[i] + 1);
            if(i + n <= t)
                dp[i + n] = max(dp[i + n], dp[i] + 1);
        }
        if(dp[t] != -1)
            cout << dp[t] << '\n';
        else{
            for(int i = t - 1; i >= 0; --i){
                if(dp[i] != -1){
                    cout << dp[i] << ' ' << (t - i) << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}