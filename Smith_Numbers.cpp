#include <bits/stdc++.h>
using namespace std;

inline int digitSum(int x){
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

bool isPrime(int x, const vector<int>& primes){
    if (x < 2) return false;
    for (int p : primes){
        if (p * p > x) break;
        if (x % p == 0) return false;
    }
    return true;
}

int digitSumFactor(int x, const vector<int>& primes){
    int sum = 0;
    int tmp = x;
    for(int p : primes){
        if(p * p > tmp)   break;
        while(tmp % p == 0){
            sum += digitSum(p);
            tmp /= p;
        }
    }
    if(tmp > 1)
        sum += digitSum(tmp);
    return sum;
}

vector<int> build_primes(int n = 100000){
    vector<bool> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;
    for(int i = 2; i * i <= n; ++i){
        if(is_prime[i])
            for(int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    }
    for(int i = 2; i <= n; ++i)
        if(is_prime[i])
            primes.push_back(i);
    return primes;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> primes = build_primes();
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int x = n + 1;
        for(;;++x){
            if(isPrime(x, primes))    continue;
            if(digitSum(x) == digitSumFactor(x, primes)){
                cout << x << '\n';
                break;
            }
        }
    }
    return 0;
}