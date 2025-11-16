#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin >> n && n){
        deque<int> row = {3, 1, 4};
        deque<int> col = {2, 1, 5, 6};
        for(int i = 0; i < n; ++i){
            string command;
            cin >> command;
            if(command == "north"){
                int tmp = col.front();
                col.pop_front();
                col.push_back(tmp);
                row[1] = col[1];
            }
            else if(command == "south"){
                int tmp = col.back();
                col.pop_back();
                col.push_front(tmp);
                row[1] = col[1];
            }
            else if(command == "east"){
                int tmp = row.back();
                row.pop_back();
                int buttom = col.back();
                row.push_front(buttom);
                col[1] = row[1];
                col.pop_back();
                col.push_back(tmp);
            }
            else if(command == "west"){
                int tmp = row.front();
                row.pop_front();
                int buttom = col.back();
                row.push_back(buttom);
                col[1] = row[1];
                col.pop_back();
                col.push_back(tmp);
            }
        }
        cout << row[1] << '\n';
    }
    return 0;
}