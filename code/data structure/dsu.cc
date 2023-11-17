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

// Reverse query technique
const int N = 1e5 + 5;
int n, ans;
int a[N], p[N], res[N];
bool flag[N];

struct DSU{
    vector<int> parent, sz, sum;

    DSU(int n) : parent(n), sz(n), sum(n) {};

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
        sum[v] = a[v];
    }
     
    int find_set(int v) {
        return v == parent[v] ? v : parent[v] = find_set(parent[v]);
    }

    void join_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a,b);
            parent[b] = a;
            sz[a] += sz[b];
            sum[a] += sum[b];
        }
    }
};

signed main() {
        
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> p[i];

    DSU g(n + 5);
    for (int i = 1; i <= n; i++) g.make_set(i);    
    for (int i = n; i >= 1; i--) {
        flag[p[i]] = true;

        if (p[i] > 1 && flag[p[i] - 1]) g.join_sets(p[i], p[i] - 1);
        if (p[i] < n && flag[p[i] + 1]) g.join_sets(p[i], p[i] + 1);

        ans = max(ans, g.sum[g.find_set(p[i])]);
        res[i - 1] = ans;
    }
        
    for (int i = 1; i <= n; i++) cout << res[i] << "\n";
        
}