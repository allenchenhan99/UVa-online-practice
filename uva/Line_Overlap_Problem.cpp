#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string tok, tok2;
    long long ans = 0;
    vector<pair<int, int>> interval;
    while(cin >> tok){
        if(tok == ".")    break;
        cin >> tok2;
        int L = stoi(tok);
        int R = stoi(tok2);
        if(L > R)   swap(L, R);
        if(L == R)  continue;
        interval.emplace_back(L, 1);
        interval.emplace_back(R, -1);

        if(interval.empty()){
            cout << 0 << '\n';
            return 0;
        }

        sort(interval.begin(), interval.end(), [](const auto& a, const auto& b){
            if(a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        });

        long long cnt = 0;
        long long prev = interval[0].first;
        int i = 0, n = interval.size();
        while(i < n){
            int x = interval[i].first;
            long long dx = (long long)x - prev;
            if(dx > 0 && cnt >= 2){
                ans += (cnt * (cnt - 1) / 2) * dx;
            }
            prev = x;
            long long delta = 0;
            while(i < n && interval[i].first == x){
                delta += interval[i].second;
            }
            cnt += delta;
        }
    }
    cout << ans << '\n';
    return 0;
}