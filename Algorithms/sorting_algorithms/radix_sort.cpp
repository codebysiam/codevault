#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* ---------------------------------- Radix Sort O(d * (n + k)) ---------------------------------- */
/*
    Radix sort sorts the elements digit by digit, starting from the least significant digit (LSD)
    and moving toward the most significant digit (MSD). The main idea is simple: in the decimal
    number system, each digit position can only contain a value from 0 to 9. Therefore, we can
    use a stable counting sort to sort the array according to one digit at a time.

    In the counting sort function, an additional parameter named 'exp' represents the current
    place value whose digit is being processed. For example:
        exp = 1   -> units digit
        exp = 10  -> tens digit
        exp = 100 -> hundreds digit
        ...

    During each pass, counting sort rearranges the elements based only on the digit corresponding
    to the current place value. Since counting sort is stable, the relative order of elements
    having the same digit is preserved. This stability is essential because the ordering
    established by the previous digit passes must remain unchanged.

    Let d be the number of digits in the largest element of the array. By repeatedly performing
    counting sort for each digit (multiplying exp by 10 after every pass), the array becomes
    completely sorted.

    This implementation works only for non-negative integers. To support negative integers,
    one approach is to shift every element by -minValue so that all values become non-negative,
    perform radix sort, and then shift the values back.

    Counting sort runs in O(n + k) time, where n is the number of elements and k is the range
    of possible keys. Here, each digit can only take values from 0 to 9, so k = 10, which is
    constant. Therefore, each counting sort pass runs in O(n) time.

    Since counting sort is performed once for each of the d digits, the overall time complexity
    of radix sort is O(d * (n + k)), which simplifies to O(d * n) because k is constant. If the
    number of digits d is small, radix sort runs in O(n)
*/

void counting_sort(vector<int>& a, ll exp){
    int n = a.size();
    vector<int> count(10, 0);
    for(int x: a){
        count[(x/exp)%10]++;
    }
    for(int i = 1; i<10; i++){
        count[i]+=count[i-1];
    }
    vector<int> output(n);
    for(int i = n-1; i>=0; i--){
        output[--count[(a[i]/exp)%10]] = a[i];
    }
    for(int i = 0; i<n; i++){
        a[i] = output[i];
    }
}

void radix_sort(vector<int>& a){
    if(a.empty()) return;
    int mx = a[0];
    for(int x: a){
        mx = max(x, mx);
    }
    for(ll exp = 1; mx/exp > 0; exp*=10){
        counting_sort(a, exp);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a){
        cin >> x;
    }
    radix_sort(a);
    for(int x: a){
        cout << x << ' ';
    }
    return 0;
}