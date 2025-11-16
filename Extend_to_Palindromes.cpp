#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string &s){
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
    return pi;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string S;
    while(cin >> S){
        string R = S;
        reverse(R.begin(), R.end());
        string T = R + "#" + S;
        vector<int> pi = prefix_function(T);
        int L = pi.back();
        cout << S << R.substr(L) << '\n';
    }
    return 0;
}