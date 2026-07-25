#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll nod(ll N){
    ll NOD = 1;
    for(ll i = 2; i<=N/i; i++){
        ll d = 1;
        while(N%i == 0){
            d++;
            N/=i;
        }
        NOD*=d;
    }
    if(N > 1) NOD*=2;
    return NOD;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll N;
    cin >> N;
    cout << "The number " << N << " has " << nod(N) << " divisors";
    return 0;
}