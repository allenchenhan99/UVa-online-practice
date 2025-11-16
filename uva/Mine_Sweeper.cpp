#include <bits/stdc++.h>
using namespace std;

int dir_x[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dir_y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int tc = 0; tc < T; ++tc){
        int n;
        cin >> n;
        vector<string> grid(n);
        vector<string> walk(n);
        for(int i = 0; i < n; ++i)
            cin >> grid[i];
        for(int i = 0; i < n; ++i)
            cin >> walk[i];
        
        bool mine_hit = false;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '*' && walk[i][j] == 'x'){
                    mine_hit = true;
                    break;
                }
            }
        }
        vector<string> ans(n, string(n, '.'));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(walk[i][j] == 'x' && grid[i][j] != '*'){
                    int cnt = 0;
                    for(int d = 0; d < 8; ++d){
                        int ni = i + dir_x[d], nj = j + dir_y[d];
                        if(0 <= ni && ni < n && 0 <= nj && nj < n){
                            if(grid[ni][nj] == '*')
                                cnt++;
                        }
                    }
                    ans[i][j] = '0' + cnt;
                }
            }
        }
        if(mine_hit){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(grid[i][j] == '*')
                        ans[i][j] = '*';
                }
            }
        }
        if(tc)    cout << '\n';
        for(int i = 0; i < n; ++i)
            cout << ans[i] << '\n';
    }
    return 0;
}