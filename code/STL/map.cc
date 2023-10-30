/**
 * Description: A map is a set of entries, each consisting of a key and a value. 
 * In a map, all keys are required to be unique, but values can be repeated. 
 * Maps have three primary methods: add, retrive, remove.
 * In sorted maps, the pairs are sorted in order of key.
 * Insertions, deletions, and searches are all O(logN)
 * In unordered maps, the pairs aren't kept in sorted order 
 * and all insertions, deletions, and searches are all O(1)
 */

map<int, int> m;
// unordered_map<int, int> m;
m[1] = 5;                    // [(1, 5)]
m[3] = 14;                   // [(1, 5); (3, 14)]
m[2] = 7;                    // [(1, 5); (2, 7); (3, 14)]
m[0] = -1;                   // [(0, -1); (1, 5); (2, 7); (3, 14)]
m.erase(2);                  // [(0, -1); (1, 5); (3, 14)]
cout << m[1] << endl;        // 5
cout << m.count(7) << endl;  // 0
cout << m.count(1) << endl;  // 1
cout << m[2] << endl;        // 0

for (const auto &x : m) { cout << x.first << " " << x.second << endl; }

for (auto &x : m) {
	x.second = 1234;  // Change all values to 1234
}

// Note: it is generally a bad idea to insert or remove elements of a map while iterating over it.
// One way to get around this is to just create a new map instead of removing from the old one.
// Another is to maintain a list of all the keys you want to erase and erase them after 
// the iteration finishes

map<int, int> m;
m[3] = 5;     // [(3, 5)]
m[11] = 4;    // [(3, 5); (11, 4)]
m[10] = 491;  // [(3, 5); (10, 491); (11, 4)]
cout << m.lower_bound(10)->first << " " << m.lower_bound(10)->second << '\n';  // 10 491
cout << m.upper_bound(10)->first << " " << m.upper_bound(10)->second << '\n';  // 11 4
m.erase(11);   // [(3, 5); (10, 491)]
if (m.upper_bound(10) == m.end()) {
	cout << "end" << endl;  // Prints end
}

// Note: unordered_map is about three times faster than map, an array is almost a hundred times faster.