#include <bits/stdc++.h>
using namespace std;

vector<int> factors(int n){
    int d = 2;
    vector<int> fctrs;
    for(; d*d <= n; d++){
        while(n%d == 0){
            fctrs.push_back(d);
            n/=d;
        }
    }
    if(n > 1) fctrs.push_back(n);
    return fctrs;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int num; cin >> num;
    vector<int> fact = factors(num);
    for(int x : fact){
        cout << x << ' ';
    }
    return 0;
}
