#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double p, q = 1;
    double c = 0;
    vector<double> ans;
    vector<int> count;
    for(long long i = 1; i <= 1e6; ++i){
        p = (1.0 / (i * (i + 1)));
        q *= (1 - p);
        ans.push_back(1 - q);
        c += log10(p);
        count.push_back(abs(c));
    }
    int n;
    while(cin >> n){
        cout << fixed << setprecision(6) << ans[n - 1] << " " << count[n - 1] << '\n';
    }
    return 0;
}