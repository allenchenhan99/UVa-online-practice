#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while(cin >> n){
        vector<int> arr(n);
        for(int i = 0; i < n; ++i){
            int num;
            cin >> num;
            arr[i] = num;
        }
        sort(arr.begin(), arr.end());
        int A;
        if(n % 2 == 1){
            A = arr[n / 2];
            int count_odd = 0;
            for(int i = 0; i < n; ++i){
                if(arr[i] == A)
                    count_odd++;
            }
            cout << A << ' ' << count_odd << ' ' << 1 <<'\n';
        }
        else{
            int L = arr[n / 2 - 1];
            int R = arr[n / 2];
            int count_even = upper_bound(arr.begin(), arr.end(), R) - lower_bound(arr.begin(), arr.end(), L);
            int ways = R - L + 1;
            cout << L << ' ' << count_even << ' ' << ways << '\n';
        }
    }
    return 0;
}