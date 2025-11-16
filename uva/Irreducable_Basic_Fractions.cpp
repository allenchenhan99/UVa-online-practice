#include <bits/stdc++.h>
using namespace std;

int Euler(int n){
    int ans = 1;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            n /= i;
            ans *= (i - 1);
            while(n % i == 0){
                n /= i;
                ans *= i;
            }
        }
    }
    if(n > 1)
        ans *= n - 1;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while(cin >> n && n){
        cout << Euler(n) << '\n';
    }
    return 0;
}