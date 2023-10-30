/**
 * Description: In unordered sets, elements are stored in an arbitrary order through hashing.
 * Insertions, deletions, and searches are all O(1) (with a high constant factor).
 * unordered set actually has worst case O(N). In any case, just default to using ordered sets.
 * Unordered sets work with primitive types, but require a custom hash function for structures/classes 
 * like vectors and pairs.
 */

unordered_set<int> s;
s.insert(1);                 // {1}
s.insert(4);                 // {1, 4}
s.insert(2);                 // {1, 4, 2}
s.insert(1);                 // does nothing because 1's already in the set
cout << s.count(1) << endl;  // 1
s.erase(1);                  // {2, 4}
cout << s.count(5) << endl;  // 0
s.erase(0);                  // does nothing because 0 wasn't in the set
