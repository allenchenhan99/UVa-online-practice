#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while(cin >> n && n){
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        int cur_max = arr[0], glob_max = cur_max;
        for(int i = 1; i < arr.size(); ++i){
            cur_max = max(arr[i], cur_max + arr[i]);
            glob_max = max(glob_max, cur_max);
        }
        if(glob_max > 0)
            cout << "The maximum winning streak is " << glob_max << ".\n";
        else
            cout << "Losing streak.\n";
    }
    return 0;
}