#include <bits/stdc++.h>
using namespace std;

int m, n;
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, 1, 0, -1};

void dfs(vector<string>& grid, int x, int y, char ch){
    grid[x][y] = '#';
    for(int i = 0; i < 4; ++i){
        int new_x = x + dir_x[i];
        int new_y = y + dir_y[i];
        if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == ch)
            dfs(grid, new_x, new_y, ch);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        cin >> m >> n;
        vector<string> grid(m);
        for(int i = 0; i < m; ++i)
            cin >> grid[i];
        vector<int> count(26, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != '#'){
                    char ch = grid[i][j];
                    ++count[ch - 'a'];
                    dfs(grid, i, j, ch);
                }
            }
        }
        vector<pair<char, int>> ans;
        for(int i = 0; i < 26; ++i)
            if(count[i])
                ans.push_back({char('a' + i), count[i]});
        sort(ans.begin(), ans.end(), [](const pair<char, int>& a, const pair<char, int>& b){
            if(a.second != b.second)    return a.second > b.second;
            return a.first < b.first;
        });
        cout << "World #" << tc << '\n';
        for(auto & p: ans)
            cout << p.first << ": " << p.second << '\n';
    }
    return 0;
}