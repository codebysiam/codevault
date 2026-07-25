#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll b, ll p, ll mod){
    b%=mod;
    if(b < 0) b+=mod;
    if(p == 0) return 1;
    ll tmp = power(b, p/2, mod);
    tmp = (tmp * tmp)%mod;
    if(p%2 != 0){
        tmp = (tmp * b)%mod;
    }
    return tmp;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll b = 1e6, MOD = 1e9+7;
    cout << power(b, 5, MOD);
    return 0;
}