#include <bits/stdc++.h>
using namespace std;

int digitSum(int n){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const int MAXN = 1e6;
    vector<char> is_prime(MAXN + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= MAXN; ++i){
        if(is_prime[i]){
            for(int j = i * i; j <= MAXN; j += i)
                is_prime[j] = false;
        }
    }
    vector<int> pref(MAXN + 1, 0);
    for(int i = 1; i <= MAXN; ++i){
        pref[i] = pref[i - 1] + (is_prime[i] && is_prime[digitSum(i)]);
    }
    int n;
    if(scanf("%d", &n) != 1)
        return 0;
    while(n--){
        int L, R;
        scanf("%d %d", &L, &R);
        printf("%d\n", pref[R] - pref[L - 1]);
    }
    return 0;
}