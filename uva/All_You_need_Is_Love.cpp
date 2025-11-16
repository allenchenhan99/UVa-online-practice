#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> s1(n), s2(n);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        s1[i] = stoi(s, nullptr, 2);
        cin >> s;
        s2[i] = stoi(s, nullptr, 2);
    }
    for (int i = 0; i < n; ++i){
        int g = gcd(s1[i], s2[i]);
        if (g > 1)
            cout << "Pair #" << i + 1 << ": All you need is love!\n";
        else
            cout << "Pair #" << i + 1 << ": Love is not all you need!\n";
    }
    return 0;
}