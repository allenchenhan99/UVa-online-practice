#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    bool first_case = true;
    while(cin >> n){
        string line;
        unordered_map<string, int> freq;
        while(getline(cin, line) && line != "EndOfText"){
            for(char &ch: line){
                if(isalpha(ch))
                    ch = tolower(ch);
                else
                    ch = ' ';
            }
            istringstream iss(line);
            string w;
            while(iss >> w){
                ++freq[w];
            }
        }
        vector<string> ans;
        ans.reserve(freq.size());
        for(auto k : freq){
            if(k.second == n)
                ans.push_back(k.first);
        }
        sort(ans.begin(), ans.end());
        if(!first_case)
            cout << '\n';
        first_case = false;
        
        if(ans.empty())
            cout << "There is no such word.\n";
        else{
            for(auto a : ans)
                cout << a << '\n';
        }
    }
    return 0;
}