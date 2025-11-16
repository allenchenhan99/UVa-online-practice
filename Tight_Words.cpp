#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k, n;
    while(cin >> k >> n){
        vector<long double> prob(k + 1, 1.0L / (k + 1));
        for(int len = 2; len <= n; ++len){
            vector<long double> next(k + 1, 0.0L);
            for(int d = 0; d <= k; ++d){
                long double s = prob[d];
                if(d > 0) s += prob[d - 1];
                if(d < k) s += prob[d + 1];
                next[d] = s / (k + 1);
            }
            prob.swap(next);
        }
        long double tight_prob = 0.0L;
        for(int d = 0; d <= k; ++d)
            tight_prob += prob[d];
        cout << fixed << setprecision(5) << (tight_prob * 100.0L) << '\n';
    }
    return 0;
}