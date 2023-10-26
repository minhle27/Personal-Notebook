/**
 * Description: Disjoint-set data structure.
 * Time: O(alpha(N)), almost constant
 */

struct DSU {
    vi lab;
    DSU(int n) { lab = vi(n, -1); }

    // get representive component (uses path compression)
    int get(int x) { return lab[x] < 0 ? x : lab[x] = get(lab[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (lab[x] > lab[y]) swap(x, y);
		lab[x] += lab[y];
		lab[y] = x;
		return true;
	}
};

int main() {
    DSU dsu(node_num);
    return 0;
}