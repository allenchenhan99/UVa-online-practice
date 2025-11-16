#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int money[6] = {1, 2, 4, 10, 20, 40};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num[6];
    vector<int> change(101, 0);
    vector<int> give(101, inf);
    double n;

    for(int i = 0; i <= 100; ++i){
        int tmp = i, cnt = 0;
        for(int d = 5; d >= 0; --d){
            int take = tmp / money[d];
            if(take){
                cnt += take;
                tmp -= money[d] * take;
            }
            if(tmp == 0)    break;
        }
        change[i] = cnt;
    }

    while(cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4] >> num[5] >> n){
        if(!num[0] && !num[1] && !num[2] && !num[3] && !num[4] && !num[5])    break;

        int x = int((n + 0.005) * 100.0);
        x /= 5;
        int limit = min(100, x + 40);
        int total = 0;
        for(int i = 0; i < 6; ++i)
            total += num[i] * money[i];
        total = min(total, limit);

        vector<int> give(limit + 1, inf);
        give[0] = 0;
        for(int i = 0; i < 6; ++i){
            for(int j = 1; j <= num[i]; ++j){
                int w = money[i] * j;
                for(int k = total; k >= w; --k){
                    give[k] = min(give[k], give[k - w] + j);
                }
            }
        }
        int ans = give[x];
        for(int i = x + 1; i <= limit; ++i)
            ans = min(ans, give[i] + change[i - x]);
        cout << setw(3) << ans << '\n';
    }
    return 0;
}