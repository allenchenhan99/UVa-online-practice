#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int node, edge;
    while(cin >> node && node){
        cin >> edge;
        vector<vector<int>> G(node);
        for(int i = 0; i < edge; ++i){
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        vector<int> color(node, -1);
        bool flag = true;
        for(int i = 0; i < node; ++i){
            if(color[i] != -1)  continue;
            color[i] = 0;
            queue<int> q;
            q.push(i);

            while(!q.empty() && flag){
                int u = q.front();
                q.pop();
                for(int v: G[u]){
                    if(color[v] == -1){
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if(color[v] == color[u]){
                        flag = false;
                        break;
                    }
                }
            }
        }
        cout << (flag ? "BICOLORABLE." : "NOT BICOLORABLE.") << '\n';
    }
    return 0;
}