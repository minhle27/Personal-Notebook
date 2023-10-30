/**
 * Description: Comparators in sorting and ordered STL DS
 */

// Essentially, the comparator determines whether object x belongs to the left 
// of object y in a sorted ordering.

// Method 1: Overloading the Less Than Operator. Only works for objects (not primitives)
struct Edge {
	int a, b, w;
	bool operator<(const Edge &y) { return w < y.w; }
};

// We can also overload the operator outside of the class:
struct Edge {
	int a, b, w;
};
bool operator<(const Edge &x, const Edge &y) { return x.w < y.w; }

// Method 2: Comparison Function. Works for both objects and primitives, 
// can declare many different comparators for the same object.
struct Edge {
	int a, b, w;
};

// If object x is less than object y , return true
bool cmp(const Edge &x, const Edge &y) { return x.w < y.w; } 
sort(begin(v), end(v), cmp);

sort(begin(v), end(v), [](const Edge &x, const Edge &y) { return x.w < y.w; }); // lambda expression


// C++ Sets with Custom Comparators
/*
make sure to include the second const or you'll get a compilation error.
[The second const] means you cannot modify member variables of the current object.
*/
struct Edge {
	int a, b, w;
	bool operator<(const Edge &y) const { return w < y.w; }
};

int main() {
	int M = 4;
	set<Edge> v;
	for (int i = 0; i < M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		v.insert({a, b, w});
	}
	for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}

// With a function
struct Edge {
	int a, b, w;
};

bool cmp(const Edge &x, const Edge &y) { return x.w < y.w; }

int main() {
	int M = 4;
	set<Edge, bool (*)(const Edge &, const Edge &)> v(cmp);
	for (int i = 0; i < M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		v.insert({a, b, w});
	}
	for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}
// You can also use the following syntax to declare set v using a function:
set<Edge,decltype(&cmp)> v(cmp);

// With lambda expression
auto cmp = [](const Edge &x, const Edge &y) { return x.w < y.w; };

int main() {
	int M = 4;
	set<Edge, bool (*)(const Edge &, const Edge &)> v(cmp);
	for (int i = 0; i < M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		v.insert({a, b, w});
	}
	for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}
// You can also use the following syntax to declare set v using a lambda
// even though decltype(cmp) is not actually equivalent to bool(*)(const Edge&,const Edge&). 
set<Edge,decltype(cmp)> v(cmp);

// Functors. One functor can be used for multiple objects.
struct Edge {
	int a, b, w;
};

struct cmp {
	bool operator()(const Edge &x, const Edge &y) const { return x.w < y.w; }
};

int main() {
	int M = 4;
	set<Edge, cmp> v;
	for (int i = 0; i < M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		v.insert({a, b, w});
	}
	for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}

// We can also use cmp like a normal function by adding () after it.
int main() {
	int M = 4;
	vector<Edge> v;
	for (int i = 0; i < M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		v.push_back({a, b, w});
	}
	sort(begin(v), end(v), cmp());
	for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}

// Built-in functor
// Overloading the less than operator (<) automatically generates the functor less<Edge>. 
// Similarly, overloading (>) automatically generates the functor greater<Edge>. 
// We can use this to store a set in reverse order.

struct Edge {
	int a, b, w;
	bool operator>(const Edge &y) const { return w > y.w; }
};

int main() {
	int M = 4;
	set<Edge, greater<Edge>> v;
	for (int i = 0; i < M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		v.insert({a, b, w});
	}
	for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}

/* Output:
2 3 10
1 2 9
1 3 7
2 4 3
*/

// other Containers
set<int, greater<int>> a;
map<int, string, greater<int>> b;
priority_queue<int, vector<int>, greater<int>> c;