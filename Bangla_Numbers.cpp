#include <bits/stdc++.h>
using namespace std;

const long long KUTI = 10000000LL;
const long long LAKH = 100000LL;
const long long HAJAR = 1000LL;
const long long SHATA = 100LL;

void bangla_chunk(long long n, vector<string>& ans){
    if(n == 0)  return;
    if(n >= KUTI){
        bangla_chunk(n / KUTI, ans);
        ans.push_back("kuti");
        n %= KUTI;
    }
    if(n >= LAKH){
        ans.push_back(to_string(n / LAKH));
        ans.push_back("lakh");
        n %= LAKH;
    }
    if(n >= HAJAR){
        ans.push_back(to_string(n / HAJAR));
        ans.push_back("hajar");
        n %= HAJAR;
    }
    if(n >= SHATA){
        ans.push_back(to_string(n / SHATA));
        ans.push_back("shata");
        n %= SHATA;
    }
    if(n > 0){
        ans.push_back(to_string(n));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    int tc = 1;
    while(cin >> n){
        cout << setw(4) << tc++ << ". ";
        if (n == 0) {
            cout << "0\n";
            continue;
        }
        vector<string> ans;
        bangla_chunk(n, ans);
        for(int i = 0; i < ans.size(); ++i){
            if(i)   cout << " ";
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}