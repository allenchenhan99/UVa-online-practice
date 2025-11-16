#include <bits/stdc++.h>
using namespace std;

long long big_mod(long long B, long long P, long long M){
    if(P == 0)  return 1;
    else if(P == 1) return B % M;
    else{
        long long ans = big_mod(B, P / 2, M);
        if(P % 2 == 1)
            return ans * ans * B % M;
        else
            return ans * ans % M;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long B, P, M;
    while(cin >> B >> P >> M){
        cout << big_mod(B, P, M) << '\n';
    }
    return 0;
}