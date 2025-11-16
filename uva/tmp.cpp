#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<string> dict;
    string line;
    while(1){
        getline(cin, line);
        if(line == "0") break;
        int i = 0, L = line.size();
        while(i < L){
            char c = line[i];
            if(isalpha(c)){
                int j = i;
                while(j < L && isalpha(static_cast<char>(line[j])))
                    ++j;
                string word = line.substr(i, j - i);
                cout << word;
                dict.insert(dict.begin(), word);
                i = j;
            }
            else if(isdigit(static_cast<char>(c))){
                int j = i;
                int k = 0;
                while(j < L && isdigit(static_cast<char>(line[j]))){
                    k = k * 10 + (line[j] - '0');
                    ++j;
                }
                string word = dict[k - 1];
                cout << word;
                dict.erase(dict.begin() + (k - 1));
                dict.insert(dict.begin(), word);
                i = j;
            }
            else{
                cout << c;
                ++i;
            }
        }
        cout << '\n';
    }
    return 0;
}

