#include <bits/stdc++.h>
using namespace std;

static vector<int> catalan(int n = 10){
    vector<int> cat(n + 1, 0);
    cat[0] = 1;
    for(int i = 1; i <= n; ++i){
        int comb = 1;
        for(int k = 1; k <= i; ++k){
            comb = comb  * (i + k) / k;
        }
        cat[i] = comb / (i + 1);
    }
    return cat;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    bool first_case = true;
    vector<int> cat = catalan();
    while(cin >> n){
        if(!first_case)
            cout << '\n';
        first_case = false;
        cout << cat[n] << '\n';
    }
    return 0;
}