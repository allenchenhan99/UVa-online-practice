#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, m, n, Q;
    cin >> T;
    while(T--){
        cin >> m >> n >> Q;
        vector<string> grid(m);
        for(int i = 0; i < m; ++i)
            cin >> grid[i];
        cout << m << ' ' << n << ' ' << Q <<'\n';
        while(Q--){
            int r, c;
            cin >> r >> c;
            char ch = grid[r][c];
            int radius = 0;
            while(1){
                int next_rad = radius + 1;
                int r1 = r - next_rad, r2 = r + next_rad;
                int c1 = c - next_rad, c2 = c + next_rad;
                if(r1 < 0 || r2 >= m || c1 < 0 || c2 >= n)
                    break;
                bool ok = true;
                for(int x = c1; x <= c2 && ok; ++x){
                    if(grid[r1][x] != ch || grid[r2][x] != ch)
                        ok = false;
                }
                for(int y = r1 + 1; y <= r2 - 1; ++y){
                    if(grid[y][c1] != ch || grid[y][c2] != ch)
                        ok = false;
                }
                if(!ok) break;
                radius = next_rad;
            }
            cout << (2 * radius + 1) << '\n';
        }
    }
    return 0;
}