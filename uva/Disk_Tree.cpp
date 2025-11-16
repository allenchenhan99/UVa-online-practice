#include <bits/stdc++.h>
using namespace std;

static inline vector<string> splitPath(const string& path){
    vector<string> parts;
    size_t i = 0;
    while(1){
        size_t j = path.find('\\', i);
        if(j == string::npos){
            parts.push_back(path.substr(i));
            break;
        }
        else{
            parts.push_back(path.substr(i, j - i));
            i = j + 1;
        }
    }
    return parts;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while(cin >> n){
        vector<vector<string>> paths;
        paths.reserve(n);
        for(int i = 0; i < n; ++i){
            string s;
            cin >> s;
            paths.push_back(splitPath(s));
        }
        sort(paths.begin(), paths.end());

        // start printing, detected by LCP
        vector<string> prev;
        for(int i = 0; i < n; ++i){
            auto& cur = paths[i];
            int lcp = 0;
            while(lcp < cur.size() && lcp < prev.size() && cur[lcp] == prev[lcp]){
                lcp++;
            }
            for(int d = lcp; d < cur.size(); ++d){
                cout << string(d, ' ') << cur[d] << '\n';
            }
            prev = cur;
        }
        cout << '\n';
    }
    return 0;
}