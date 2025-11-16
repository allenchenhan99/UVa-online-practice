#include <bits/stdc++.h>
using namespace std;

static inline int last(int k){
    return 3 * k * (k + 1) + 1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin >> n){
        if(n == 1){
            cout << 0 << ' ' << 0 << '\n';
            continue;
        }
        int k = 1;
        while(last(k) < n)  ++k;
        
        int F = last(k - 1);
        int res = n - F;
        int q = (res - 1) / k;
        int r = (res - 1) % k;
        
        int x = 0, y = 0;
        switch (q){
            case 0: x = (k - 1) - r; y = 1 + r;           break;
            case 1: x = -(r + 1);    y =  k;              break;
            case 2: x = -k;          y =  k - (r + 1);    break;
            case 3: x = -k + (r + 1);y = -(r + 1);        break;
            case 4: x =  (r + 1);    y = -k;              break;
            case 5: x =  k;          y = -k + (r + 1);    break;
        }
        cout << x << ' ' << y << '\n';
    }
    return 0;
}