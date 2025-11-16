#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L;
    while(cin >> L && L){
        int n;
        cin >> n;
        vector<int> pos(n + 2);
        pos[0] = 0;
        for(int i = 1; i <= n; ++i)
            cin >> pos[i];
        pos[n + 1] = L;

        int cost;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int len = 2; len <= n + 1; ++len){
            for(int i = 0; i + len <= n + 1; ++i){
                int j = i + len;
                int best = INT_MAX;
                for(int k = i + 1; k <= j - 1; ++k){
                    int cost = dp[i][k] + dp[k][j] + (pos[j] - pos[i]);
                    if(cost < best)
                        best = cost;
                }
                dp[i][j] = best;
            }
        }
        cout << "The minimum cutting is " << dp[0][n + 1] << "." << '\n';
    }
    return 0;
}