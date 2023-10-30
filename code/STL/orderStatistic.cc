/**
 * Description: The one that we will use to solve the selection and ranking problems easily.
 * A data structure that supports all the operations as a set in C++ in addition to the following: 
 * 1. orderofkey(x): counts the number of elements in the set that are strictly less than x.
 * 2. findbyorder(k): similar to find, returns the iterator corresponding to the k-th lowest 
 * element in the set (0-indexed).
 */


#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>                    // pbds
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
// for multiset, change less to less_equal
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() { 
    ordered_set X;
    // X = {1, 2, 4, 8, 16}
    
    for(int i = 1; i <= 16; i *= 2)
        X.insert(i); // O(n log n)
    
    // O(log n) select
    cout << *X.find_by_order(0) << endl; // 1 , 1-smallest = 1
    cout << *X.find_by_order(1) << endl; // 2 
    cout << *X.find_by_order(2) << endl; // 4
    cout << *X.find_by_order(4) << endl; // 16, 5-smallest or largest = 16
    cout << (X.end()==X.find_by_order(6)) << endl; // true

    // O(log n) rank
    cout<<X.order_of_key(-5)<<endl;  // 0
    cout<<X.order_of_key(1)<<endl;   // 0
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5
}