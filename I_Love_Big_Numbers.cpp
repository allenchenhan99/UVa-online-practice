#include <bits/stdc++.h>
using namespace std;

static vector<int> sum(int n = 1000){
    vector<int> ans(n + 1, 0);
    vector<int> digits;
    digits.push_back(1);
    for(int i = 1; i <= 1000; ++i){
        int carry = 0;
        for(int j = 0; j < digits.size(); ++j){
            int r = digits[j] * i + carry;
            carry = r / 10;
            digits[j] = r % 10; 
        }
        while(carry){
            digits.push_back(carry % 10);
            carry /= 10;
        }
        int sum = 0;
        for(int d: digits)
            sum += d;
        ans[i] = sum;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while(cin >> n){
        vector<int> ans = sum();
        cout << ans[n] << '\n'; 
    }
    return 0;
}