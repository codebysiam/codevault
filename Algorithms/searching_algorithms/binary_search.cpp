#include <bits/stdc++.h>
using namespace std;

/* ----------------------------------- Binary Search O(log n) ----------------------------------- */
/*
    Binary search is an efficient searching algorithm that works only on
    sorted arrays.

    We compare the key with the middle element of the current search range.
    - If they are equal, we return the index.
    - If the key is smaller, we continue searching in the left half.
    - If the key is larger, we continue searching in the right half.

    This process repeatedly halves the search range until the key is found
    or the search range becomes empty. If the key does not exist, we return -1.

    Binary search runs in O(log n) time, making it much faster than linear
    search for large sorted arrays.

    If the array is not sorted, we usually sort it first in O(n log n) time.
    Therefore, binary search is most beneficial when we need to perform many
    searches on the same array, since the sorting cost is paid only once.
    For a single search on an unsorted array, a linear search may be more
    efficient because it avoids the cost of sorting.
*/

// Precondition: The vector 'a' have to be sorted
int binarySearch(const vector<int>& a, int key){
    int n = a.size();
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low+(high-low)/2;
        if(a[mid] == key){
            return mid;
        }

        if(key < a[mid]){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> a = {1, 5, 3, 2, 0, 10, 56, 34};
    sort(begin(a), end(a));
    cout << binarySearch(a, 5);
    return 0;
}