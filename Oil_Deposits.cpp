#include <bits/stdc++.h>
using namespace std;

int m, n;
int dir_x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dir_y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(vector<string>& grid, int x, int y){
    grid[x][y] = '*';

    for(int i = 0; i < 8; ++i){
        int new_x = x + dir_x[i];
        int new_y = y + dir_y[i];
        if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == '@'){
            DFS(grid, new_x, new_y);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> m >> n && m){
        vector<string> grid(m);
        string line;
        for(int i = 0; i < m; ++i){
            cin >> grid[i];
        }
        int count = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '@'){
                    count++;
                    DFS(grid, i, j);
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}