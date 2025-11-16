#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M, N;
    while(cin >> M >> N){
        vector<uint32_t> arr(M, 0);
        for(int i = 0; i < M; ++i){
            int cnt = N - i;
            for(int j = 0; j < cnt; ++j){
                uint32_t x;
                cin >> x;
                arr[i] ^= x;
            }
        }
        for(int i = 0; i < M - 1; ++i){
            uint32_t miss = arr[i] ^ arr[i + 1];
            cout << miss << '\n';
        }
    }
    return 0;
}