#include <bits/stdc++.h>
using namespace std;

/* ---------------------- First/Last Occurrence O(log n) ----------------------*/
/*
    We can efficiently find the first or last occurrence of an integer in a
    sorted array using the binary search technique.

    To find the first occurrence, whenever the middle element equals the key,
    we store its index as a candidate answer and continue searching the left
    half to see if an earlier occurrence exists. If the middle element is less
    than the key, we search the right half; otherwise, we search the left half.

    To find the last occurrence, we use the same idea, except that after finding
    the key we continue searching the right half to look for a later occurrence.

    If the key is not present in the array, the function returns -1.
*/

// precondition: the vector 'a' must be sorted
int first_occur(const vector<int>& a, int key){
    int low = 0;
    int high = a.size() - 1;
    int idx = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(a[mid] == key){
            idx = mid;
            high = mid-1;
        }else if(a[mid] > key){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return idx;
}

// precondition: the vector 'a' must be sorted
int last_occur(const vector<int>& a, int key){
    int low = 0;
    int high = a.size() - 1;
    int idx = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(a[mid] == key){
            idx = mid;
            low = mid+1;
        }else if(a[mid] > key){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return idx;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> a = {2, 5, 6, 6, 6, 7, 9, 11, 15};
    cout << first_occur(a, 6) << ' ' << last_occur(a, 6);
    return 0;
}