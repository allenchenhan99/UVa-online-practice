#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long initial, day;
    while(cin >> initial >> day){
        long long ans = initial;
        while(day > initial){
            day -= initial;
            initial++;
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}