#include <bits/stdc++.h>
using namespace std;

/* ---------------------- Linear Search O(n) ----------------------*/
/*
    In linear search, we traverse the entire array and compare the
    search key with each element. If the element is found, we return
    its index. If the element is not found, we return -1.

    Best Case:
    - The element is at index 0.
    - Time Complexity: O(1)

    Average Case:
    - The element is somewhere in the middle.
    - Time Complexity: O(n)

    Worst Case:
    - The element is at the last index or does not exist.
    - Time Complexity: O(n)

    Space Complexity:
    - O(1)
*/

int linearSearch(const vector<int>& a, int key){
    for(int i = 0; i<a.size(); i++){
        if(a[i] == key) return i;
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> a = {2, 4, 0, 1, 4, 6, 9, 1};
    int searchItem = 4;
    int index = linearSearch(a, searchItem);
    if(index > -1){
        cout << "Element found at index " << index;
    }else{
        cout << "Element not found";
    }
    return 0;
}