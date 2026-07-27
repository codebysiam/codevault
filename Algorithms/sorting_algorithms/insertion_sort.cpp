#include <bits/stdc++.h>
using namespace std;

/** ---------------------- Insertion Sort O(n^2) ------------------------ */
/*
    In Insertion Sort, we traverse the array from left to right. For each
    element, we store it in a variable (let's call it 'key') and compare it
    with the elements to its left.

    While there are elements greater than 'key', we shift those elements one
    position to the right. We continue shifting until we either reach the
    beginning of the array or find an element that is less than or equal to
    'key'.

    At this point, all elements greater than 'key' have been shifted to the
    right, creating an empty position (conceptually) where 'key' belongs.
    We then insert 'key' into that position.

    In each iteration, one element is placed into its correct position within
    the already sorted left portion of the array.

    We start from index 1 because the element at index 0 has no elements to
    its left to compare with. Therefore, the first element can be considered
    a sorted subarray of size 1.
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto&x : a){
        cin >> x;
    }
    for(int i = 1; i<n; i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    for(int x: a){
        cout << x << ' ';
    }
    return 0;
}