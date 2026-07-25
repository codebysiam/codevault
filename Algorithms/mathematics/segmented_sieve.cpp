#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<bool> sieve(ll N){
    vector<bool> sv(N+1, true);
    if(N >= 1) sv[1] = false;
    if(N >= 0) sv[0] = false;

    for(ll i = 4; i<=N; i+=2){
        sv[i] = false;
    }

    for(ll i = 3; i<=N/i; i+=2){
        if(sv[i]){
            for(ll d = (ll)i*i; d<=N; d+=i*2){
                sv[d] = false;
            }
        }
    }

    return sv;
}

vector<bool> segmented_sieve(ll L, ll R){
    if(L >= R) return {};
    ll limit = sqrtl(R);
    vector<bool> sv = sieve(limit);

    vector<bool> ssv(R-L+1, true);
    for(size_t p = 2; p<=limit; p++){
        if(sv[p]){
            ll start = max((ll)p * p, ((L+p-1)/p)*p);
            for(ll I = start; I<=R; I+=p){
                ssv[I-L] = false;
            }
        }
    }

    if(L == 1) ssv[0] = false;
    if(L == 0){
        ssv[0] = false;
        if(R >= 1){
            ssv[1] = false;
        }
    }

    return ssv;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll L, R;
    cin >> L >> R;
    vector<bool> ssv = segmented_sieve(L, R);
    for(size_t i = 0; i<ssv.size(); i++){
        if(ssv[i]){
            cout << i+L << ' ';
        }
    }
    return 0;
}