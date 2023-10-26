/**
 * Description: Kruskal Algo
 * Time: if the graph is densed, use Prim for better performance
 */

struct DSU {
    vi lab;
    DSU(int n) { lab = vi(n, -1); }

    int get(int x) { return lab[x] < 0 ? x : lab[x] = get(lab[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    bool unite(int x, int y) {  
		x = get(x), y = get(y);
		if (x == y) return false;
		if (lab[x] > lab[y]) swap(x, y);
		lab[x] += lab[y];
		lab[y] = x;
		return true;
	}
};

ll kruskal(int n, vector<pair<ll, pi>> Edges) {
    DSU d(n); 
    ll res = 0; int taken = 0;

    sort(Edges.begin(), Edges.end());

    for (auto edge: Edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        if (d.unite(u, v)) {
            res += edge.first;
            taken++;
        }
        if (taken == n - 1) break;
    }
    if (taken != n - 1) return -1;
    return res;
}