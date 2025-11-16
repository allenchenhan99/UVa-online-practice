#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> solve(const string& s){
    vector<long long> num;
    vector<char> op;
    long long cur = 0;
    bool in = false;
    for(char c: s){
        if(isdigit(c)){
            cur = cur * 10 + (c - '0');
            in = true;
        }
        else{
            if(in){
                num.push_back(cur);
                cur = 0;
                in = false;
            }
            op.push_back(c);
        }
    }
    if(in)  num.push_back(cur);

    int n = num.size();
    vector<vector<long long>> mn(n, vector<long long>(n, LLONG_MAX));
    vector<vector<long long>> mx(n, vector<long long>(n, LLONG_MIN));
    for(int i = 0; i < n; ++i)
        mx[i][i] = mn[i][i] = num[i];
    for(int len = 2; len <= n; ++len){
        for(int l = 0; l + len - 1 < n; ++l){
            int r = l + len - 1;
            for(int k = l; k < r; ++k){
                if(op[k] == '+'){
                    mn[l][r] = min(mn[l][r], mn[l][k] + mn[k + 1][r]);
                    mx[l][r] = max(mx[l][r], mx[l][k] + mx[k + 1][r]);
                }
                else{
                    mn[l][r] = min(mn[l][r], mn[l][k] * mn[k + 1][r]);
                    mx[l][r] = max(mx[l][r], mx[l][k] * mx[k + 1][r]);
                }
            }
        }
    }
    return {mx[0][n - 1], mn[0][n - 1]};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        pair<long long, long long> ans = solve(s);
        cout << "The maximum and minimum are " << ans.first << " and " << ans.second << ".\n";
    }
    return 0;
}