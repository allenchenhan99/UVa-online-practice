#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<string>& grid, int x, int y){
    if (x < 0 || x >= 10 || y < 0 || y >= 10) return false;
    if (grid[x][y] == '#' || grid[x][y] == '*' || grid[x][y] == '+') return false;
    if (grid[x][y] == 'G') return true;

    int dir_x[4] = {-1, 0, 1, 0};
    int dir_y[4] = {0, 1, 0, -1};

    char orig = grid[x][y];
    if(orig != 'S')
        grid[x][y] = '*';

    for(int d = 0; d < 4; ++d){
        int new_x = x + dir_x[d];
        int new_y = y + dir_y[d];
        if(DFS(grid, new_x, new_y)){
            if(orig != 'S')
                grid[x][y] = '+';
            return true;
        }
    }
    if(orig != 'S')
        grid[x][y] = '.';
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<string> grid(10);
    string line;
    for(int i = 0; i < 10; ++i){
        getline(cin, line);
        grid[i] = line;
    }

    int sx, sy, gx, gy;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            if(grid[i][j] == 'S'){
                sx = i; sy = j;
            }
            if(grid[i][j] == 'G'){
                gx = i; gy = j;
            }
        }
    }

    bool ok = DFS(grid, sx, sy);
    if (ok){
        grid[sx][sy] = '+';
        grid[gx][gy] = '+';
        for(int i = 0; i < 10; ++i) cout << grid[i] << '\n';
        cout << '\n';
    } else {
        cout << "No solution\n";
    }
    return 0;
}