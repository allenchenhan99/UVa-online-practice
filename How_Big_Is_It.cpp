#include <bits/stdc++.h>
using namespace std;

double calculate(vector<double> radius){
    sort(radius.begin(), radius.end());
    double best = DBL_MAX;
    do{
        int m = radius.size();
        vector<double> x(m, 0);
        for(int i = 0; i < m; ++i){
            double xi = 0.0;
            for(int j = 0; j < i; ++j){
                xi = max(xi, x[j] + 2.0 * sqrt(radius[i] * radius[j]));
            }
            x[i] = xi;
        }
        double L = x[0] - radius[0], R = x[0] + radius[0];
        for(int i = 1; i < m; ++i){
            L = min(L, x[i] - radius[i]);
            R = max(R, x[i] + radius[i]);
        }
        best = min(best, R - L);
    }while(next_permutation(radius.begin(), radius.end()));
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        vector<double> radius(num);
        for(int i = 0; i < num; ++i)
            cin >> radius[i];
        double ans = calculate(radius);
        cout << fixed << setprecision(3) << (ans + 1e-9) << '\n';
    }
    return 0;
}