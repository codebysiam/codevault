#include <bits/stdc++.h>
using namespace std;

/* ----------------- First/Last Occurrence O(n) -----------------*/
/*
    To find the first and last occurrence of an element in an array,
    we keep two variables: one for the first occurrence index and
    one for the last occurrence index.

    We then traverse the entire array. When we find the key for the
    first time, we store its index in both `first` and `last`.
    After that, whenever we find the key again, we update only the
    `last` index.

    This way, after a single traversal, `first` contains the index
    of the first occurrence and `last` contains the index of the
    last occurrence.

    If the key does not exist, both variables remain -1.
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> a = {0, 2, 4, 5, 5, 5, 6, 7, 7};
    int n = a.size();
    int key = 5;
    int first = -1;
    int last = -1;
    for(int i = 0; i<n; i++){
        if(a[i] != key) continue;

        if(first == -1){
            first = i;
        }
        
        last = i;
    }
    cout << first << ' ' << last;
    return 0;
}