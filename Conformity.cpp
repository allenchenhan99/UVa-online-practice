#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while(cin >> n && n){
        map<set<int>, int> freq;
        for(int i = 0; i < n; ++i){
            set<int> comb;
            for(int j = 0; j < 5; ++j){
                int x;
                cin >> x;
                comb.insert(x);
            }
            ++freq[comb];
        }
        int max_freq = 0, ans = 0;
        for(auto f: freq){
            max_freq = max(max_freq, f.second);
        }
        for(auto f: freq){
            if(f.second == max_freq)
                ans += f.second;
        }
        cout << ans << '\n';
    }
    return 0;
}