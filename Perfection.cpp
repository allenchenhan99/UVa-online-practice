#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << "PERFECTION OUTPUT\n";
    int n;
    while(cin >> n && n){
        int sum = 0;
        if(n == 1)
            sum = 0;
        else{
            sum = 1;
            int r = sqrt(n);
            for(int d = 2; d <= r; ++d){
                if(n % d == 0){
                    sum += d;
                    int q = n / d;
                    if(q != d)
                        sum += q;
                }
            }
        }
        const char* output;
        if(sum == n)    output = "PERFECT";
        else if(sum > n)    output = "ABUNDANT";
        else    output = "DEFICIENT";
        cout << setw(5) << n << "  " << output << '\n';
    }
    cout << "END OF OUTPUT\n";
    return 0;
}