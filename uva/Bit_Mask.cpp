#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unsigned int N, L, U;
    while(cin >> N >> L >> U){
        unsigned int M = 0;
        for(int i = 31; i >= 0; --i){
            if((M | (1 << i)) > U)    continue;
            if((M | (1 << i)) <= L || (!(N & (1 << i))))
                M |= (1 << i);
        }
        cout << M << '\n';
    }
    return 0;
}