#include <bits/stdc++.h>
using namespace std;

static bool cmp(const string a, const string b){
    return a + b > b + a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while(cin >> n && n){
        vector<string> num(n);
        for(int i = 0; i < n; ++i)
            cin >> num[i];
        sort(num.begin(), num.end(), cmp);
        string ans = "";
        for(int i = 0; i < n; ++i)
            ans += num[i];
        cout << ans << '\n';
    }
    return 0;
}