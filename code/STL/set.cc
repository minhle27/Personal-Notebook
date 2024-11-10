/**
 * Description: In sorted sets, the elements are sorted in order of element.
 * Insertions, deletions, and searches are all O(logN)
 * all the essential operations that unordered set has 
 */

set<int> s;
s.insert(1);                        // [1]
s.insert(14);                       // [1, 14]
s.insert(9);                        // [1, 9, 14]
s.insert(2);                        // [1, 2, 9, 14]

// lower_bound: returns an iterator to the least element greater than or equal to some element k.
// upper_bound: returns an iterator to the least element strictly greater than some element k.
// if the requested element does not exist, the return value is end().
cout << *s.upper_bound(7) << '\n';  // 9
cout << *s.upper_bound(9) << '\n';  // 14
cout << *s.lower_bound(5) << '\n';  // 9
cout << *s.lower_bound(9) << '\n';  // 9
cout << *s.begin() << '\n';         // 1
auto it = s.end();
cout << *(--it) << '\n';    // 14
s.erase(s.upper_bound(6));  // [1, 2, 14]

for (int element : s) { cout << element << endl; }

auto it = s.find(x); 
if (it == s.end()) {
    // x is not found
}

// Real Runtime: Set > unordered_set > normal sorting

// insert method return a pair of iterator and a boolean value
// if the element is already present in the set, the boolean value is false
// and the iterator points to the element that is already present
// otherwise, the boolean value is true and the iterator points to the newly inserted element