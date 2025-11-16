#include <bits/stdc++.h>
using namespace std;

int maxareaDP(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<int> height(n, 0), left(n, 0), right(n, n);
    int best = 0;

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j)
            height[j] = grid[i][j] == 0 ? height[j] + 1 : 0;
        
        int cur_left = 0;
        for(int j = 0; j < n; ++j){
            if(grid[i][j] == 0)
                left[j] = max(left[j], cur_left);
            else{
                left[j] = 0;
                cur_left = j + 1;
            }
        }
        int cur_right = n;
        for(int j = n - 1; j >= 0; --j){
            if(grid[i][j] == 0)
                right[j] = min(right[j], cur_right);
            else{
                right[j] = n;
                cur_right = j;
            }
        }
        for(int j = 0; j < n; ++j)
            best = max(best, (right[j] - left[j]) * height[j]);
    }
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m, n;
    while(cin >> m >> n && m && n){
        vector<vector<int>> grid(m, vector<int>(n));
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                cin >> grid[i][j];
        
        cout << maxareaDP(grid) << '\n';
    }
    return 0;
}