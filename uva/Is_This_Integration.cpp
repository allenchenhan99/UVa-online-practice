#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const double PI = acos(-1.0);
    double n;
    while(cin >> n){
        double A = (1.0 - sqrt(3.0) + PI / 3.0) * n * n;
        double B = (-4.0 + PI / 3.0 + 2 * sqrt(3.0)) * n * n;
        double C = (4.0 - 2 * PI / 3.0 - sqrt(3.0)) * n * n;
        cout << fixed << setprecision(3) << A << ' ' << B << ' ' << C << '\n';
    }
    return 0;
}