#include <bits/stdc++.h>
using namespace std;

static vector<int> LIS(const vector<int>& arr){
    int n = arr.size();
    vector<int> L(n);
    vector<int> tails;
    for(int i = 0; i < n; ++i){
        auto it = lower_bound(tails.begin(), tails.end(), arr[i]);
        int pos = it - tails.begin();
        if(it == tails.end())
            tails.push_back(arr[i]);
        else
            *it = arr[i];
        L[i] = pos + 1;
    }
    return L;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while(cin >> n){
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        
        vector<int> L = LIS(arr);
        vector<int> rev = arr;
        reverse(rev.begin(), rev.end());
        vector<int> rev_tmp = LIS(rev);

        vector<int> R(n);
        for(int i = 0; i < n; ++i)
            R[i] = rev_tmp[n - 1 - i];

        int ans = 1;
        for(int i = 0; i < n; ++i)
            ans = max(ans, 2 * min(L[i], R[i]) - 1);
        cout << ans << '\n';
    }
    return 0;
}