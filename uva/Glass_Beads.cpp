#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    while(n--){
        string word;
        cin >> word;
        int len = word.size();
        int i = 0, j = 1;
        int k = 0;
        while(i < len && j < len && k < len){
            char candidate1 = word[(i + k) % len];
            char candidate2 = word[(j + k) % len];
            if(candidate1 == candidate2)
                ++k;
            else{
                if(candidate1 > candidate2)
                    i = i + k + 1;
                else if(candidate1 < candidate2)
                    j = j + k + 1;
                if(i == j)
                    ++i;
                k = 0;
            }
        }
        int ans = min(i, j) + 1;
        cout << ans << '\n';
    }
    return 0;
}