#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    while(cin >> n && n){
        long long tmp = sqrtl(n);
        if(tmp * tmp == n)
            cout << "yes" << '\n';
        else    cout << "no" <<'\n';
    }
    return 0;
}