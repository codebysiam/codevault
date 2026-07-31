#include <bits/stdc++.h>
using namespace std;

/* ----------------------------- Quick Sort [Average O(nlogn)] Naive Approach -----------------------------*/
/*
    In Quick Sort, we choose one element of the array as a pivot. The pivot can be the first element,
    last element, middle element, or a randomly chosen element. Then we rearrange the array around
    the pivot so that all elements on the left side are smaller than or equal to the pivot and all
    elements on the right side are greater than the pivot. This process is called partitioning.

    After partitioning, the pivot reaches its final sorted position. The partition function returns
    the pivot index, and we recursively apply Quick Sort on the left and right subarrays excluding
    the pivot. We continue this process until a subarray has zero or one element, which is already sorted.

    In the code below, we use the naive partitioning approach. During partitioning, we use an auxiliary
    array to store elements smaller than or equal to the pivot, followed by the pivot, and then elements
    greater than the pivot. Finally, we copy these elements back into the original array.

    This approach requires O(n) extra space for partitioning.
*/

int partition(vector<int>& a, int low, int high){
    int pivot = a[low];
    int leftCount = 0;
    vector<int> buff(high-low+1);
    int k = 0;
    for(int i = low+1; i<=high; i++){
        if(a[i] <= pivot){
            buff[k++] = a[i];
            leftCount++;
        }
    }
    buff[k++] = pivot;
    int pivotPos = low+leftCount;
    for(int i = low+1; i<=high; i++){
        if(a[i] > pivot){
            buff[k++] = a[i];
        }
    }
    for(int i = low; i<=high; i++){
        a[i] = buff[i-low];
    }
    return pivotPos;
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