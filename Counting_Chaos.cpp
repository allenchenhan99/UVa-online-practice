#include <bits/stdc++.h>
using namespace std;

inline bool pal(int h, int m){
    if(h == 0)
        return (m < 10) || (m % 11 == 0);
    if(h < 10)
        return (m % 10 == h);
    return m == h % 10 * 10 + h / 10;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int h = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3, 2));

        int t = h * 60 + m;
        for(int i = 1; i <= 1440; ++i){
            int nt = (t + i) % 1440;
            int nh = nt / 60, nm = nt % 60;
            if(pal(nh, nm)){
                cout << setw(2) << setfill('0') << nh << ':' << setw(2) << setfill('0') << nm << '\n';
                break;
            }
        }
    }
    return 0;
}