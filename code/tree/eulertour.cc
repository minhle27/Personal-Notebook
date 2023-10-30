/**
 * Description: Euler tour. Using dfs traversal to flatten out tree in an array 
 * where each subtree is represented by a range. Use with BIT or segtree for subtree 
 * queries
 */

vector<vector<int>> g(maxn);
vector<int> start;
vector<int> en;
int timer = 0;

// tour or tree traversal array will be 0-based (which will be used to construct FT or segtree)
// Node: tree traversal array is just a record of the first occurence of a node in an euler tour/path
void euler_tour(int at, int prev) {
	start[at] = timer++;
	for (int n : g[at]) {
		if (n != prev) { euler_tour(n, at); }
	}
	en[at] = timer;
}

start.resize(node_num);
en.resize(node_num);
euler_tour(0, -1);

/*
[start[i], en[i] - 1] is the subtree root i. en[i] - start[i] is the subtree size
*/

// Generally when doing euler tour, we should use 0-based node 
// Complete Euler path