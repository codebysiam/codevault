#include <bits/stdc++.h>
using namespace std;

/* -------------------------------- Selection Sort O(n^2) -------------------------------*/
/*
    In Selection Sort, for each position a[i] where i < n-1, we search the
    unsorted portion a[i...n-1] to find the minimum element. After finding
    the minimum element, we swap it with a[i].

    After each pass, one element is placed in its correct sorted position.
    Therefore, n-1 passes are enough because after placing the first n-1
    elements, the last remaining element is automatically in the correct
    position.

    Unlike optimized Bubble Sort or Insertion Sort, Selection Sort does not
    become faster when the array is already sorted or nearly sorted. It still
    performs exactly n-1 passes and scans the remaining unsorted portion in
    every pass. Therefore, its best-, average-, and worst-case time
    complexity is O(n²).

    One advantage of Selection Sort is that it performs at most n-1 swaps
    (one swap per pass). In contrast, Bubble Sort may perform significantly
    more swaps, making Selection Sort preferable when swapping elements is
    expensive.

    So, using selection sort can be beneficial when swapping is more expensive
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto&x : a){
        cin >> x;
    }
    for(int i = 0; i<n-1; i++){
        int mn = i;
        for(int j = i+1; j<n; j++){
            if(a[mn] > a[j]){
                mn = j;
            }
        }
        if(mn != i){
            swap(a[i], a[mn]);
        }
    }

    for(int x: a){
        cout << x << ' ';
    }
    return 0;
}