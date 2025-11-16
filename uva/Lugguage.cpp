#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string space;
    getline(cin, space);
    while(n--){
        string line;
        getline(cin, line);
        istringstream iss(line);
        vector<int> weight;
        int x, sum = 0;
        while(iss >> x){
            weight.push_back(x);
            sum += x;
        }
        if(sum % 2){
            cout << "NO\n";
            continue;
        }
        int half = sum / 2;
        vector<char> dp(half + 1, 0);
        dp[0] = 1;
        for(int w: weight){
            for(int i = half; i >= w; --i)
                if(dp[i - w])
                    dp[i] = 1;
        }
        cout << (dp[half] ? "YES" : "NO") << '\n';
    }
    return 0;
}