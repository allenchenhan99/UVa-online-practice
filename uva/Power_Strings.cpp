#include <bits/stdc++.h>
using namespace std;

int prefix_function(const string& s){
    int n = s.size();
    vector<int> pi(n, 0);
    for(int i = 1; i < n; ++i){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if(s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    int p = n - pi[n - 1];
    if(n % p == 0)
        return n / p;
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while(1){
        if(!getline(cin, s)) break;
        if(s == ".") break;
        cout << prefix_function(s) << '\n';
    }
    return 0;
}