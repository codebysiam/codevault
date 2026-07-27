#include <bits/stdc++.h>
using namespace std;

/** ------------------- Bubble Sort O(n^2) ------------------------ */
/*
    In the bubble sort algorithm, we repeatedly compare adjacent elements
    and swap them if they are in the wrong order (left one is greater than
    the right one).

    If we perform one pass, we get the largest element at the end.
    If we perform two passes, we get the two largest elements at the end.

    If we perform n-1 passes, we place all the elements in ascending order.
    We don't have to perform n passes because after n-1 passes, the remaining
    element at index 0 is already in its correct position.

    We can use the same logic to sort the array in descending order.
    In that case, we swap when the left element is smaller than the right
    element. This places the smallest element at the end after each pass.

    In some cases, the array becomes sorted before completing all n-1 passes.
    So, we can optimize it by breaking the loop if no swaps occur in a pass.
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
        int swp = 0;
        for(int j = 0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                swp=1;
            }
        }
        if(!swp) break;
    }

    for(int x: a){
        cout << x << ' ';
    }
    return 0;
}