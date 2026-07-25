#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Steps:
 * find a prime factor of N (let say 2)
 * find the powers of the prime factor from p^0 to p^x
 * add them
 * search for other prime factors
 * then multiple all of them
 * return the product
 * 
 * Mathematical:
 * lets say N = 36;
 * or N = 2^2 * 3^2
 * so, sum of divisors of N will be:
 * (2^0 + 2^1 + 2^2) * (3^0 + 3^1 + 3^2)
 * (1 + 2 + 4) * (1 + 3 + 9)
 * (1 + 3 + 9 + 2 + 6 + 18 + 4 + 12 + 36)
 * (1 + 2 + 3 + 4 + 6 + 12 + 18 + 36) // See, we are adding all the divisors of N
 * Ans: 91
 */

ll SOD(ll N){
    ll sod = 1;
    for(ll p = 2; p<=N/p; p++){
        ll pow = 1;
        ll term = 1;
        while(N%p == 0){
            N/=p;
            pow*=p;
            term+=pow;
        }
        sod*=term;
    }
    if(N > 1) {
        sod*=(1 + N);
    }
    return sod;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        cout << "The sum of divisors of " << N << " is " << SOD(N) << '\n';
    }
    return 0;
}