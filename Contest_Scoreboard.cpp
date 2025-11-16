#include <bits/stdc++.h>
using namespace std;

struct Team{
    int id = 0;
    int solved = 0;
    int penalty = 0;
    bool seen = false;
    bool done[10] = {};
    int  wrong[10] = {};
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    string line;

    cin >> T;
    getline(cin, line);
    getline(cin, line);
    while(T--){
        Team t[101]{};
        for(int i = 0; i <= 100; ++i)
            t[i].id = i;
        while(1){
            if(!getline(cin, line)) break;
            if(line.empty())    break;
            int c, p, time;
            char L;

            istringstream iss(line);
            iss >> c >> p >> time >> L;

            t[c].seen = true;
            if(L == 'C'){
                if(!t[c].done[p]){
                    t[c].done[p] = true;
                    t[c].solved += 1;
                    t[c].penalty += (time + 20 * t[c].wrong[p]);
                }
            }
            else if(L == 'I')
                if(!t[c].done[p])
                    t[c].wrong[p] += 1;
        }
        vector<Team> board;
        for(int i = 1; i <= 100; ++i)
            if(t[i].seen)
                board.push_back(t[i]);
        sort(board.begin(), board.end(), [](const Team& a, const Team& b){
            if(a.solved != b.solved)    return a.solved > b.solved;
            if(a.penalty != b.penalty)  return a.penalty < b.penalty;
            return a.id < b.id;
        });
        for(auto x : board)
            cout << x.id << ' ' << x. solved << ' ' << x.penalty << '\n';
        if(T)   cout << '\n';
    }
    return 0;
}