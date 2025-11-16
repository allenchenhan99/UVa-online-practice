#include <bits/stdc++.h>
using namespace std;

vector<int> table = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while(cin >> n){
        int base = table[n / 2];
        int limit = table[n];
        for(int i = 0; i < limit; ++i){
            int a = i / base;
            int b = i % base;
            int target = (a + b);
            if((target * target) == i)
                cout << setw(n) << setfill('0') << i << '\n';
        }
    }
    return 0;
}