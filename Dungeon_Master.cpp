#include <bits/stdc++.h>
using namespace std;

const int direction[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

struct Node{
    int z, y, x;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L, R, C;
    while(cin >> L >> R >> C){
        if(!L && !R && !C)  break;
        vector<vector<string>> grid(L, vector<string>(R));
        Node S, E;
        for(int z = 0; z < L; ++z){
            for(int y = 0; y < R; ++y){
                cin >> grid[z][y];
                for(int x = 0; x < C; ++x){
                    if(grid[z][y][x] == 'S')
                        S = {z, y, x};
                    else if(grid[z][y][x] == 'E')
                        E = {z, y, x};
                }
            }
        }
        vector<vector<vector<int>>> dist(L, vector<vector<int>>(R, vector<int>(C, -1)));
        queue<Node> q;
        dist[S.z][S.y][S.x] = 0;
        q.push(S);

        int ans = -1;
        while(!q.empty()){
            Node cur = q.front();
            q.pop();
            if(cur.z == E.z && cur.y == E.y && cur.x == E.x){
                ans = dist[cur.z][cur.y][cur.x];
                break;
            }
            for(int d = 0; d < 6; ++d){
                int nz = cur.z + direction[d][0];
                int ny = cur.y + direction[d][1];
                int nx = cur.x + direction[d][2];
                if(0 <= nz && nz < L && 0 <= ny && ny < R && 0 <= nx && nx < C){
                    if(grid[nz][ny][nx] != '#' && dist[nz][ny][nx] == -1){
                        dist[nz][ny][nx] = dist[cur.z][cur.y][cur.x] + 1;
                        q.push({nz, ny, nx});
                    }
                }
            }
        }
        if(ans >= 0)
            cout << "Escaped in " << ans << " minute(s)." << '\n';
        else    cout << "Trapped!" << '\n';
    }
    return 0;
}