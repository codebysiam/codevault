#include <bits/stdc++.h>
using namespace std;

/* --------------------------- Counting Sort O(n + k) ---------------------------

    Counting sort is a non-comparison integer sorting algorithm that runs in
    O(n + k) time, where:
        n = number of elements
        k = max_value - min_value + 1 (the range of values)

    Instead of comparing elements, counting sort counts how many times each
    distinct value appears. It first finds the minimum and maximum values in
    the array, then creates a frequency array of size (max - min + 1), where
    each index stores the frequency of its corresponding value.

    For non-negative integers, the value itself can be used as the index.
    If the array contains negative integers, the indices are shifted by
    subtracting the minimum value so that the smallest element maps to index 0.

        index = value - min_value

    Finally, the frequency array is traversed in increasing order, outputting
    each value according to its frequency to reconstruct the sorted array.

    This implementation is NOT stable because it reconstructs the sorted
    sequence directly from the frequency array. A stable version requires
    prefix sums and an auxiliary output array.

    Counting sort is most efficient when the value range (k) is relatively
    small compared to the number of elements (n). If the range is very large,
    the frequency array becomes memory-inefficient, making comparison-based
    algorithms (e.g., std::sort) a better choice.

    Counting sort is primarily used for integers. Decimal values with a fixed
    number of decimal places can also be sorted by first scaling them into
    integers without losing precision.

    Example:
        {0.2, 0.9, 0.8, 1.0}
    ->  multiply by 10
        {2, 9, 8, 10}
    ->  counting sort
        {2, 8, 9, 10}
    ->  divide by 10
        {0.2, 0.8, 0.9, 1.0}
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    if (n < 1) return 0;
    vector<int> a(n);
    int mn = INT_MAX;
    int mx = INT_MIN;
    for(auto& x: a){
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    int k = mx-mn+1;
    vector<int> freq(k, 0);
    for(int x: a){
        freq[x-mn]++;
    }
    for(int i = 0; i<k; i++){
        for(int j = 0; j<freq[i]; j++){
            cout << mn+i << ' ';
        }
    }
    return 0;
}