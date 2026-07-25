#include <bits/stdc++.h>
using namespace std;

// This function returns a vector of boolean values that indicate
// if the index is a prime number. [index <= N+1];
// [false, false, true, true, false, true] -> [0, 1, 2, 3, 4, 5]
vector<bool> sieve(int N){
    vector<bool> sv(N+1, true);
    if(N > 1 ) sv[0] = false;
    if(N > 1 )  sv[1] = false;
    for(int i = 2; i*i<=N; i++){
        if(sv[i]){
            for(int m = i*i; m<=N; m+=i){
                sv[m] = false;
            }
        }
    }
    return sv;
};


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<bool> sv = sieve(1000);
    int total = 0;
    for(int i = 0; i<sv.size(); i++){
        if(sv[i]){
            cout << i << ' ';
            total++;
        }
    }
    cout << '\n'<< "Total: " << total;
    return 0;
}