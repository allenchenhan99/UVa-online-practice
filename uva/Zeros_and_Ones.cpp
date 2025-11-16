#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int c = 1;
    while(cin >> s){
        cout << "Case " << c << ":" << '\n';
        vector<int> change(s.size(), 0);
        change[0] = 0;
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == s[i - 1])
                change[i] = change[i - 1];
            else    change[i] = change[i - 1] + 1;
        }
        int n;
        cin >> n;
        int start, end;
        for(int i = 0; i < n; ++i){
            cin >> start >> end;
            if(change[start] != change[end])
                cout << "No" << '\n';
            else    cout << "Yes" << '\n';
        }
        c++;
    }
    return 0;
}
