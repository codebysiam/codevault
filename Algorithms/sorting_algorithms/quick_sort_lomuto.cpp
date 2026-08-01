#include <bits/stdc++.h>
using namespace std;

/* ------------------------------------ Quick Sort O(n log n) Using Lomuto Partition ---------------------------------*/
/*
    In Quick Sort, we choose an element of the array as the pivot and arrange the elements such that
    all elements on the left are less than or equal to the pivot, while all elements on the right
    are greater than the pivot. We keep doing this recursively until the entire array is sorted.

    To arrange the elements around the pivot, we can use different partitioning techniques.
    Lomuto partition is one of them. In the Lomuto partition scheme, we always choose the last
    element of the current subarray as the pivot.

    Let i represent the end of the left partition (elements <= pivot), while j traverses the
    subarray from left to right (excluding the pivot). Since i points to the last element of the
    left partition, i + 1 marks the beginning of the right partition among the elements processed
    so far.

    Whenever we find a[j] <= pivot, it actually belongs to the left partition. So, we increment i
    and swap a[i] with a[j], effectively trading the first element of the right partition with
    a[j] and expanding the left partition by one element.

    After the traversal is complete, we swap the pivot (a[high]) with a[i + 1]. This places the
    pivot in its correct sorted position, with all elements on its left less than or equal to it
    and all elements on its right greater than it.

    We initialize i to low - 1 because, before the traversal begins, we haven't found any element
    that belongs to the left partition.
*/

int partition(vector<int>& a, int low, int high){
    int pivot = a[high];
    int i = low-1;
    for(int j = low; j<high; j++){
        if(a[j] <= pivot){
            i++;
            if(i!=j){
                swap(a[i], a[j]);
            }
        }
    }
    if(i+1 != high) swap(a[i+1], a[high]);
    return i+1;
}

void quickSort(vector<int>& a, int low, int high){
    if(low >= high) return;
    int p = partition(a, low, high);
    quickSort(a, low, p-1);
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