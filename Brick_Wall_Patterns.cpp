#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> dp(51);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 1; i < 50; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int n;
    while(cin >> n && n){
        cout << dp[n] << '\n';
    }
    return 0;
}