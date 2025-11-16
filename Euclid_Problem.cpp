#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y){
    if(a % b == 0){
        x = 0;
        y = 1;
        return b;
    }
    else{
        int r, tx, ty;
        r = gcd(b, a % b, tx, ty);
        x = ty;
        y = tx - a / b * ty;
        return r;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, r, x, y;
    while(cin >> a >> b){
        r = gcd(a, b, x, y);
        cout << x << " " << y << " " << r << '\n';
    }
    return 0;
}