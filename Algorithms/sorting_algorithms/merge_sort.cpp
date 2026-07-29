#include <bits/stdc++.h>
using namespace std;

/** -------------------------- Merge Sort O(n log n) ---------------------------- */
/*
    Merge Sort follows the Divide and Conquer paradigm.

    The idea is simple:
    1. Divide a large problem into smaller subproblems.
    2. Solve each smaller problem recursively.
    3. Combine the solutions to obtain the final answer.

    Let's understand it with an example.

    vector<int> arr = {4, 2, 0, 1};

    Divide the array until each subarray contains only one element.

            {4, 2, 0, 1}
             /        \
         {4, 2}      {0, 1}
         /   \       /    \
       {4}  {2}    {0}   {1}

    A subarray containing only one element is already sorted.

    Now start merging the sorted subarrays.

        {4} + {2}  -> {2, 4}
        {0} + {1}  -> {0, 1}

    Finally,

        {2, 4} + {0, 1}
               ↓
        {0, 1, 2, 4}

    Since each merge combines two already sorted subarrays, the resulting
    merged subarray is also sorted.

    Merge Sort uses recursion to repeatedly divide the array into two halves.
    After both halves are sorted recursively, they are merged together using
    the same technique used to merge two sorted arrays.

    Eventually, after all recursive calls finish, the entire array becomes sorted.
*/


void merge(vector<int>& a, int s, int mid, int e){
    int left_len = mid-s+1;
    int right_len = e-mid;

    vector<int> left(left_len);
    vector<int> right(right_len);

    for(int i = 0; i<left_len; i++){
        left[i] = a[s+i];
    }

    for(int i = 0; i<right_len; i++){
        right[i] = a[mid+i+1];
    }

    int i = 0, j = 0, k = s;
    while(i < left_len && j < right_len){
        if(left[i] <= right[j]){
            a[k++] = left[i++];
        }else{
            a[k++] = right[j++];
        }
    }

    while(i < left_len){
        a[k++] = left[i++];
    }

    while(j < right_len){
        a[k++] = right[j++];
    }
}

void mergeSort(vector<int>& a, int s, int e){
    if(s >= e) return;
    int mid = (s+e)/2;

    mergeSort(a, s, mid);
    mergeSort(a, mid+1, e);

    merge(a, s, mid, e);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto&x : a){
        cin >> x;
    }
    mergeSort(a, 0, n-1);
    for(int x: a){
        cout << x << ' ';
    }
    return 0;
}