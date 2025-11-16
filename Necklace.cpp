#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int V, V0;
    while(cin >> V >> V0 && (V || V0)){
        if(V <= V0){
            cout << 0 << '\n';
            continue;
        }
        double x = double(V) / (2 * V0);
        double f = x - floor(x);

        if(fabs(f - 0.5) < 1e-10){
            cout << 0 << '\n';
            continue;
        }
        int n = fabs(f < 0.5) ? floor(x) : round(x);
        if(n < 1)   cout << 0 << '\n';
        else    cout << n << '\n';
    }
    return 0;
}