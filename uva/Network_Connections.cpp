#include <bits/stdc++.h>
using namespace std;

int p[30005];

int Find(int a){
    return a == p[a] ? a : p[a] = Find(p[a]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, success, fail;
    cin >> T;
    string line;
    getline(cin, line);
    while (T--) {
        int n;
        do{
            getline(cin, line); 
        } while(line.size() == 0);
        n = stoi(line);
        for(int i = 1; i <= n; ++i)
            p[i] = i;
        success = fail = 0;
        while(getline(cin, line)){
            if(line.empty()) break;
            char op; int a, b;
            istringstream iss(line);
            iss >> op >> a >> b;

            int pa = Find(a);
            int pb = Find(b);

            if (op == 'c') {
                if (pa != pb) p[pa] = pb;
            }
            else if(op == 'q'){
                if(pa == pb) ++success;
                else            ++fail;
            }
        }
        cout << success << "," << fail << "\n";
        if (T) cout << "\n"; 
    }
    return 0;
}