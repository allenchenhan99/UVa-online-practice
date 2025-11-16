#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, M;
    string line;
    cin >> T;
    getline(cin, line);
    for(int tc = 0; tc < T; ++tc){
        getline(cin, line);
        cin >> M;
        int L, R;
        vector<pair<int, int>> interval;
        while(cin >> L >> R){
            if(L == 0 && R == 0)    break;
            interval.push_back({L, R});
        }
        sort(interval.begin(), interval.end(),
            [](const pair<int, int>& a, const pair<int, int>& b){
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        
        //Greedy pick
        vector<pair<int, int>> chosen;
        int n = interval.size();
        int i = 0;
        int cur = 0;
        bool ok = true;
        while(cur < M){
            int bestR = cur;
            pair<int, int> bestSeg = {0, 0};
            while(i < n && interval[i].first <= cur){
                if(interval[i].second > bestR){
                    bestR = interval[i].second;
                    bestSeg = interval[i];
                }
                ++i;
            }
            if(bestR == cur){
                ok = false;
                break;
            }
            chosen.push_back(bestSeg);
            cur = bestR;
        }
        if(tc)  cout << '\n';
        if(!ok) cout << 0 << '\n';
        else{
            sort(chosen.begin(), chosen.end(), [](const pair<int, int>& a, const pair<int, int>& b){
                if(a.first != b.first)  return a.first < b.first;
                return a.second < b.second;
            });
            cout << chosen.size() << '\n';
            for(auto c: chosen)
                cout << c.first << " " << c.second << '\n';
        }
    }
    return 0;
}