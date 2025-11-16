#include <bits/stdc++.h>
using namespace std;

int arr[20] = {0, 1, 5, 2, 8, 3, 9, 2, 8, 7, 7, 8, 4, 7, 3, 8, 4, 1, 5, 4};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while(cin >> s && s != "0"){
        int val = s.back() - '0';
        if(s.size() > 1)
            val += 10 * (s[s.size() - 2] - '0');
        cout << (arr[val % 20] + 4 * (val / 20)) % 10 << '\n';
    }
    return 0;
}