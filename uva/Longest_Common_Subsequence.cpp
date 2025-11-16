// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     string s1, s2;
//     while(getline(cin, A) && getline(cin, B)){
//         int n = s1.size(), m = s2.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//         for(int i = 1; i <= n; ++i){
//             for(int j = 1; j <=  m; ++j){
//                 if(s1[i - 1] == s2[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 else
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//         cout << dp[n][m] << '\n';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s1, s2;
    while(getline(cin, s1) && getline(cin, s2)){
        int n = s1.size(), m = s2.size();
        vector<int> dp(m + 1, 0);
        for(int i = 1; i <= n; ++i){
            int prev = 0;
            for(int j = 1; j <= m; ++j){
                int tmp = dp[j];
                if(s1[i - 1] == s2[j - 1])
                    dp[j] = prev + 1;
                else    dp[j] = max(dp[j], dp[j - 1]);
                prev = temp;
            }
        }
        cout << dp[m] << '\n';
    }
    return 0;
}