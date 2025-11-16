#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while(cin >> n){
        vector<int> num(n);
        for(int i = 0; i < n; ++i)
            cin >> num[i];
        vector<int> dp;
        for(int x: num){
            auto pos = lower_bound(dp.begin(), dp.end(), x);
            if(pos == dp.end())
                dp.push_back(x);
            else    *pos = x;
        }
        cout << dp.size() << '\n';
    }
    return 0;
}