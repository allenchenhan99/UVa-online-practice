#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a0;
    while(cin >> a0 && a0){
        bitset<10000> seen;
        int x = a0;
        int count = 0;
        while(!seen.test(x)){
            seen.set(x);
            ++count;
            int sq = x * x;
            x = ((sq / 100) % 10000);
        }
        cout << count << '\n';
    }
    return 0;
}