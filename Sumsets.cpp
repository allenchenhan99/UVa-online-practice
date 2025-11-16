#include <bits/stdc++.h>
using namespace std;

struct SUM_TABLE{
    long long sum;
    int index1, index2;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while(cin >> n && n){
        vector<long long> arr(n);
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr.begin(), arr.end());

        vector<SUM_TABLE> sum_table;
        sum_table.reserve(n * (n - 1) / 2);
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                sum_table.push_back({arr[i] + arr[j], i, j});
        sort(sum_table.begin(), sum_table.end(), [](const SUM_TABLE& x, const SUM_TABLE& y){
            return x.sum < y.sum;
        });
        auto lb = [&](long long t){
            return lower_bound(sum_table.begin(), sum_table.end(), t,
            [](const SUM_TABLE& x, long long v){
                return x.sum < v;
            });
        };
        auto ub = [&](long long t){
            return upper_bound(sum_table.begin(), sum_table.end(), t,
            [](long long v, const SUM_TABLE& x){
                return v < x.sum;
            });
        };
        bool ok = false;
        long long ans = 0;
        for(int d = n - 1; d >= 0 && !ok; --d){
            for(int c = 0; c < n && !ok; ++c){
                if(c == d)  continue;
                long long target = arr[d] - arr[c];
                auto L = lb(target), R = ub(target);
                for(auto it = L; it != R; ++it){
                    int i = it->index1, j = it->index2;
                    if(i != c && j != c && i != d && j != d){
                        ans = arr[d];
                        ok = true;
                        break;
                    }
                }
            }
        }
        cout << (ok ? to_string(ans) : string("no solution")) << '\n';
    }
    return 0;
}