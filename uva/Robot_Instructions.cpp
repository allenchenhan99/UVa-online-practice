#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    while(n--){
        int step;
        cin >> step;
        string command;
        vector<int> instructions(step);
        for(int i = 0; i < step; ++i){
            cin >> command;
            if(command == "LEFT")
                instructions[i] = -1;
            else if(command == "RIGHT")
                instructions[i] = 1;
            else if(command == "SAME"){
                int index;
                string as;
                cin >> as >> index;
                instructions[i] = instructions[index - 1];
            }
        }
        int pos = 0;
        for(int i = 0; i < step; ++i){
            pos += instructions[i];
        }
        cout << pos << '\n';
    }
    return 0;
}