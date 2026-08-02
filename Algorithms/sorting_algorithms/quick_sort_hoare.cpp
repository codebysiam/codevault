#include <bits/stdc++.h>
using namespace std;

/* -------------------------------- Quick Sort O(nlogn) Using Hoare's Partition Scheme --------------------------------*/
/*
    Quick Sort works by selecting a pivot element and partitioning the array into
    two parts. After partitioning, elements in the left part are less than or equal
    to the pivot, while elements in the right part are greater than or equal to the
    pivot. The same process is then applied recursively to both parts until the
    entire array is sorted.

    Hoare's Partition Scheme is one of the most efficient partitioning methods used
    in Quick Sort. Compared to Lomuto's Partition Scheme, it generally performs fewer
    swaps and offers better practical performance. Unlike Lomuto's scheme, Hoare's
    partition does not necessarily place the pivot in its final sorted position after
    each partition.

    For more information about Hoare's Partition Scheme, see:
    ../arrays/hoare_partition.cpp
*/

int partition(vector<int>& a, int low, int high){
    int pivot = a[low];
    int i = low-1;
    int j = high+1;
    while(true){
        do{
            i++;
        }while(a[i] < pivot);
        do{
            j--;
        }while(a[j] > pivot);
        if(i >= j) return j;
        swap(a[i], a[j]);
    }
}

void quickSort(vector<int>& a, int low, int high){
    if(low >= high) return;
    int p = partition(a, low, high);
    quickSort(a, low, p);
    quickSort(a, p+1, high);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a){
        cin >> x;
    }
    quickSort(a, 0, n-1);
    for(int x: a){
        cout << x << ' ';
    }
    return 0;
}