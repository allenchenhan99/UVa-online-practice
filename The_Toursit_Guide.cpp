#include <bits/stdc++.h>
using namespace std;

int p[101];

struct edge{
    int u, v, w;
};

int Find(int x){
    return (x == p[x]) ? x : (p[x] = Find(p[x]));
}

void Union(int a, int b){
    p[Find(a)] = Find(b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    edge e[10001];
    int n, r, tc = 1;
    while(cin >> n >> r && n && r){
        r <<= 1;
        for(int i = 0; i < r; i += 2){
            int u, v, w;
            cin >> u >> v >> w;
            e[i].u = e[i + 1].v = u;
            e[i].v = e[i + 1].u = v;
            e[i].w = e[i + 1].w = w - 1;
        }
        int begin, end, all, ans;
        cin >> begin >> end >> all;
        sort(e, e + r, [](const edge &a, const edge &b){
            return a.w > b.w;
        });
        for(int i = 0; i <= n; ++i)
            p[i] = i;
        for(int i = 0, j = 0; i < n - 1 && j < r; ++i){
            while(Find(e[j].u) == Find(e[j].v))
                ++j;
            Union(e[j].u, e[j].v);
            if(Find(begin) == Find(end)){
                ans = e[j].w;
                break;
            }
        }
        cout << "Scenario #" << tc++ <<'\n';
        cout << "Minimum Number of Trips = " << (all + ans - 1) / ans << "\n\n";
    }
    return 0;
}