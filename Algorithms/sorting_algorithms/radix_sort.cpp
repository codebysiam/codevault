#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* --------------------------------- Radix Sort O(d*(n+k)) ------------------------------ */
/*
    In this implementation, we split the main array into two parts: negative and positive.
    Then we convert the negative numbers into positive by taking their absolute values and
    apply radix sort to them. After sorting, we reverse the negative array and restore the
    negative signs by multiplying each element by -1. Next, we radix sort the positive
    numbers. Finally, we merge both arrays to obtain the fully sorted array.
*/

void counting_sort(vector<ll>& a, ll exp){
    int n = a.size();
    vector<ll> count(10);
    for(ll x: a){
        count[(x/exp)%10]++;
    }
    for(int i = 1; i<10; i++){
        count[i]+=count[i-1];
    }

    vector<ll> output(n);
    for(int i = n-1; i>=0; i--){
        output[--count[(a[i]/exp)%10]] = a[i];
    }
    a.swap(output);
}

void radix_sort_positive(vector<ll>& a){
    if(a.size() < 2) return;
    ll mx = a[0];
    for(ll x: a){
        mx = max(mx, x);
    }
    for(ll exp = 1; mx/exp > 0; exp*=10){
        counting_sort(a, exp);
    }
}

void radix_sort(vector<ll>& a){
    int n = a.size();
    if(n < 2) return;
    vector<ll> negative;
    vector<ll> positive;
    for(ll x: a){
        if (x < 0){
            negative.push_back(llabs(x));
        }else{
            positive.push_back(x);
        }
    }
    radix_sort_positive(negative);
    radix_sort_positive(positive);
    int k = 0;
    for(int i = (int)negative.size()-1; i>=0; i--){
        a[k++] = -negative[i];
    }
    for(ll x: positive){
        a[k++] = x;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto& x: a){
        cin >> x;
    }
    radix_sort(a);
    for(ll x: a){
        cout << x << ' ';
    }
    return 0;
}