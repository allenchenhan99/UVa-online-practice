#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int MAXN = 10000;
    cpp_int f[MAXN + 1];
    f[0] = 0;
    if(MAXN >= 1)
        f[1] = 1;
    int i = 2;
    int k = 1;
    while(i <= MAXN){
        cpp_int add = cpp_int(1) << k;
        for(int j = 0; j <= k && i <= MAXN; ++j){
            f[i] = f[i - 1] + add;
            ++i;
        }
        ++k;
    }
    int n;
    while(cin >> n){
        string s = f[n].convert_to<string>();
        cout << s << '\n';
    }
    return 0;
}