/**
 * Description: Vector and iterator
 */

vector<int> v; 
v.push_back(3); // [3] 
v.push_back(2); // [3,2] 
v.push_back(5); // [3,2,5]

vector<int> v = {2,4,2,5,1};
vector<int> a(8); // size 8, initial value 0 
vector<int> b(8,2); // size 8, initial value 2

vector<int> v{1, 7, 4, 5, 2};
for (int i = 0; i < int(size(v)); i++) { cout << v[i] << " "; }
cout << endl;

for (auto x : v) { 
    cout << x << "\n";
}

for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
	cout << *it << " ";  // prints the values in the vector using the iterator
}

vector<int> v{1, 7, 4, 5, 2};
for (auto it = begin(v); it != end(v); it = next(it)) {
	cout << *it << " ";  // prints the values in the vector using the iterator
}

vector<int> v = {2,4,2,5,1}; 
cout << v.back() << "\n"; // 1 
v.pop_back();
cout << v.back() << "\n"; // 5

// An iterator is a variable that points to an element of a data structure. 
// The iterator begin points to the first element of a data structure, and the 
// iterator end points to the position after the last element. A range is a 
// sequence of consecutive elements in a data structure. The usual way to specify 
// a range is to give iterators to its first element and the position after its last element.

sort(v.begin(),v.end());
reverse(v.begin(),v.end());
random_shuffle(v.begin(),v.end());

cout << *v.begin() << "\n";

vector<int> v = {2,3,3,5,7,8,8,8};
// If there is no such element, the functions return an iterator to the element after the last element in the range.
auto a = lower_bound(v.begin(),v.end(),5); 
auto b = upper_bound(v.begin(),v.end(),5); 
cout << *a << " " << *b << "\n";

// counts the number of elements whose value is x
auto r = equal_range(array, array+n, x);
cout << r.second-r.first << "\n";

// creates a vector that contains the unique elements of the original vector in a sorted order:
sort(v.begin(),v.end());
v.erase(unique(v.begin(),v.end()),v.end());

// reverse iterator
sort(A.rbegin(), A.rend());

// insert val to position of iterator
vi::iterator it;
it = v.begin() + 2;
v.insert(it, 9);
v.erase(it); // erase an element
v.clear(); // delete all element

vector<int> v;
v.push_back(2);          // [2]
v.push_back(3);          // [2, 3]
v.push_back(7);          // [2, 3, 7]
v.push_back(5);          // [2, 3, 7, 5]
v[1] = 4;                // sets element at index 1 to 4 -> [2, 4, 7, 5]
v.erase(v.begin() + 1);  // removes element at index 1 -> [2, 7, 5]
// this remove method is O(n); to be avoided
v.push_back(8);        // [2, 7, 5, 8]
v.erase(v.end() - 1);  // [2, 7, 5]
// here, we remove the element from the end of the list; this is O(1).
v.push_back(4);                     // [2, 7, 5, 4]
v.push_back(4);                     // [2, 7, 5, 4, 4]
v.push_back(9);                     // [2, 7, 5, 4, 4, 9]
cout << v[2];                       // 5
v.erase(v.begin(), v.begin() + 3);  // [4, 4, 9]
// this erases the first three elements; O(n)

vector<int> v(n);
// Set the initial values to 0, 1...7
iota(v.begin(), v.end(), 0);

// find
std::vector<int> vec = {1, 2, 3, 4, 5};
int element = 3;

// Use std::find to search for the element
auto it = std::find(vec.begin(), vec.end(), element);

// Check if the element was found
if (it != vec.end()) {
	std::cout << "Element found!" << std::endl;
} else {
	std::cout << "Element not found!" << std::endl;
}

/**
 * In array-based contest problems, we'll use one-, two-, and three-dimensional static arrays much of the time. 
 * However, we can also have dynamic arrays of dynamic arrays (e.g. vector<vector<int>>) 
 * static arrays of dynamic arrays (e.g. array<vector<int>,5>),
 *  dynamic arrays of static arrays (e.g. vector<array<int,5>>), and so on.
 */