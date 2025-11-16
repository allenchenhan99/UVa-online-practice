#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const int MAXN = 20;
    vector<long long> fact(MAXN + 1, 1);
    for(int i = 1; i <= MAXN; ++i)
        fact[i] = fact[i - 1] * i;
    
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        string s;
        long long k;
        cin >> s >> k;
        int n = s.size();

        long long x = k - 1;
        vector<int> d(n, 0);
        for(int i = 0; i < n; ++i){
            long long f = fact[n - 1 - i];
            d[i] = x / f;
            x %= f;
        }
        string order;
        order.reserve(n);
        for(int i = n - 1; i >= 0; --i){
            int pos = d[i];
            order.insert(order.begin() + pos, s[i]);
        }
        cout << "Case " << t << ": " << order << '\n';
    }
    return 0;
}