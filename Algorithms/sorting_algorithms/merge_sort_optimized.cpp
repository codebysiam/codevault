#include <bits/stdc++.h>
using namespace std;

/** ------------------------------- Merge Sort O(nlogn) --------------------------------- */
/*
    To optimize merge sort, we use a buffer array to temporarily store the elements
    while merging two sorted halves. During the merge operation, we insert elements
    into the buffer in sorted order, so the buffer contains the merged sorted version
    of the current range. After merging, we copy the sorted elements from the buffer
    back into the main array and reuse the same buffer for future merge operations.

    Another optimization is skipping unnecessary merge operations. After the recursive
    mergeSort calls, both halves are already sorted. If the last element of the first
    half is less than or equal to the first element of the second half, then the whole
    range is already sorted, so we don't need to merge it again.
*/

void merge(vector<int>& a, vector<int>& buff, int s, int m, int e){
    int i = s, j = m+1, k = s;
    while(i <= m && j<=e){
        if(a[i] <= a[j]){
            buff[k++] = a[i++];
        }else{
            buff[k++] = a[j++];
        }
    }
    while(i <= m){
        buff[k++] = a[i++];
    }
    while(j <= e){
        buff[k++] = a[j++];
    }
    for(int x = s; x<=e; x++){
        a[x] = buff[x];
    }
}

void mergeSort(vector<int>& a, vector<int>& buff, int s, int e){
    if(s >= e) return;
    int mid = s+(e-s)/2;

    mergeSort(a, buff, s, mid);
    mergeSort(a, buff, mid+1, e);

    if(a[mid] <= a[mid+1]) return;

    merge(a, buff, s, mid, e);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a){
        cin >> x;
    }
    vector<int> buff(n);
    mergeSort(a, buff, 0, n-1);
    for(int x: a){
        cout << x << ' ';
    }
    return 0;
}