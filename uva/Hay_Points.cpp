#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    unordered_map<string, long long> val;
    for(int i = 0; i < m; ++i){
        string w;
        long long v;
        cin >> w >> v;
        val.emplace(w, v);
    }
    string line;
    for(int i = 0; i < n; ++i){
        long long sum = 0;
        while(getline(cin, line)){
            if(line == ".") break;
            istringstream iss(line);
            string word;
            while(iss >> word){
                auto it = val.find(word);
                if(it != val.end())
                    sum += it->second;
            }
        }
        cout << sum << '\n';
    }
    return 0;
}