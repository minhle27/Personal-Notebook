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

for (int i = 0; i < v.size(); i++) { 
    cout << v[i] << "\n";
}

for (auto x : v) { 
    cout << x << "\n";
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
