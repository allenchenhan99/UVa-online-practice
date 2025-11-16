#include <bits/stdc++.h>
using namespace std;

int DFS(vector<string>& grid, int x, int y){
    int count = 1;
    grid[x][y] = '1';
    int dir_x[4] = {-1, 0, 1, 0};
    int dir_y[4] = {0, 1, 0, -1};
    for(int d = 0; d < 4; ++d){
        int new_x = x + dir_x[d];
        int new_y = y + dir_y[d];
        if(new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size() && grid[new_x][new_y] == '0')
            count += DFS(grid, new_x, new_y);
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    while(tc--){
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        string newline;
        getline(cin, newline);

        vector<string> grid;
        string line;
        while(getline(cin, line)){
            if(line.empty()) break;
            grid.push_back(line);
        }
        cout << DFS(grid, x, y) << '\n';
        if(tc) cout << '\n';
    }
    return 0;
}