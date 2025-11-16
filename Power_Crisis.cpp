#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    const int target = 11;
    while(cin >> n && n){
        n--;
        int m = 1;
        while(1){
            int turnoff = 0;
            for(int i = 2; i <= n; ++j){
                turnoff = (turnoff + m) % j;
            }
            if(turnoff == target){
                cout << 'm\n';
                break;
            }
            ++m;
        }
    }
    return 0;
}