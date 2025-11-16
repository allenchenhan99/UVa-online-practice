#include <bits/stdc++.h>
using namespace std;

string digits(string s){
    string t;
    for(char c: s){
        if(isdigit(c)) t += c;
    }
    return t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nStd;
    int run = 1;
    while(cin >> nStd && nStd){
        string dummy;
        getline(cin, dummy);
        string s1, s2, line;
        for(int i = 0; i < nStd; ++i){
            getline(cin, line);
            s1 += line;
            s1.push_back('\n');
        }
        int nTeam;
        cin >> nTeam;
        getline(cin, dummy);
        for(int i = 0; i < nTeam; ++i){
            getline(cin, line);
            s2 += line;
            s2.push_back('\n');
        }
        if(s1 == s2){
            cout << "Run #" << run << ": Accepted" << '\n';
            ++run;
            continue;
        }
        else if(digits(s1) == digits(s2)){
            cout << "Run #" << run << ": Presentation Error" << '\n';
            ++run;
            continue;
        }
        else{
            cout << "Run #" << run << ": Wrong Answer" << '\n';
            ++run;
            continue;
        }
    }
    return 0;
}
