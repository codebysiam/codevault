#include <bits/stdc++.h>
using namespace std;

/* --------------------------- Counting Sort O(n + k) ---------------------------

    Counting Sort is a non-comparison-based sorting algorithm. It counts the
    occurrences of each element in the array and uses that information to sort
    the elements.

    There are two versions of Counting Sort: Stable and Unstable

    This is the stable implementation of Counting Sort for both negative and
    non-negative integers.

    In this implementation, we first count the occurrences of each element and
    store them in a frequency array. Then, we compute the prefix sum of the
    frequency array. After the prefix sum, each index in the frequency array
    represents the total number of elements less than or equal to that value,
    which helps determine the correct position of every element in the sorted
    array.

    Finally, we traverse the input array from right to left and place each
    element into its correct position in the output array. Traversing from
    right to left preserves the relative order of equal elements, making the
    algorithm stable.

    Time Complexity : O(n + k)
    Space Complexity: O(n + k)

    where,
        n = number of elements
        k = range of the values (maximum value - minimum value + 1)
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;

    if(n == 0) return 0;

    vector<int> a(n);
    for(auto& x: a){
        cin >> x;
    }

    int mx = INT_MIN;
    int mn = INT_MAX;
    for(int x: a){
        mx = max(mx, x);
        mn = min(mn, x);
    }

    int freqSize = mx-mn+1;
    vector<int> freq(freqSize);
    for(int x: a){
        freq[x-mn]++;
    }

    for(int i = 1; i<freqSize; i++){
        freq[i]+=freq[i-1];
    }

    vector<int> output(n);
    for(int i = n-1; i>=0; i--){
        output[--freq[a[i]-mn]] = a[i];
    }

    for(int x: output){
        cout << x << ' ';
    }
    return 0;
}