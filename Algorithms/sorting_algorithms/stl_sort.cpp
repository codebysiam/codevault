#include <bits/stdc++.h>
using namespace std;

/* ---------------------------- C++ STL sort() O(n log n) ---------------------------- */
/*
    The C++ Standard Library's sort() function uses Introsort internally.
    Introsort is a highly optimized hybrid sorting algorithm that combines:

        - Quick Sort      -> Fast average-case performance
        - Heap Sort       -> Guarantees O(n log n) worst-case complexity
        - Insertion Sort  -> Efficient for small subarrays

    sort() is NOT stable.
    Equal elements may not preserve their relative order.

    * Syntax
    sort(first_iterator, last_iterator);
    sort(first_iterator, last_iterator, comparator);
*/

bool compare(int a, int b){
    return abs(a) > abs(b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {4, 10, -24, 400, 20};
    // vector<char> c = {'A', 'X', 'C', 'F', 'D', 'a', 'e'};
    // vector<string> fruits = {"banana", "avocado", "apple", "orange", "grapes"};
    // string name = "John Doe";

    // sort(a.begin(), a.end());                  // Sort the entire vector
    // sort(a.begin(), a.begin() + a.size());     // Sort the entire vector
    // sort(a.begin() + 1, a.end() - 1);          // Sort from index 1 to the second-last element
    // sort(c.begin(), c.end());                  // Sort characters in ascending ASCII order
    // sort(fruits.begin(), fruits.end());        // Sort strings lexicographically
    // sort(name.begin(), name.end());            // Sort characters in the string

    // Sort by descending absolute value (using custom comparator)
    sort(a.begin(), a.end(), compare);

    for (auto x : a) {
        cout << x << ' ';
    }

    return 0;
}