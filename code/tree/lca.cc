/**
 * Description: Different methods for finding LCA in a tree
 */

// Method 1: Euler tour + RMQ (SegTree / Sparse Table). Node should be numbered from 0
// O(N) preprocessing, O(logN) queries: segtree
// O(NlogN) preprocessing, O(1) queries: Sparse Table (static data)
struct LCA {
    vi height, euler, first, st;
    int n;

    LCA(int _n, int root = 0) {
        n = _n;
        height.resize(n);
        first.resize(n);
        euler.reserve(2 * n);
        dfs(root, -1);
        int m = sz(euler);
        st.resize(4 * m);
        build(1, 0, m - 1);
    }

    // build euler path
    void dfs(int cur, int par, int h = 0) {
        height[cur] = h;
        first[cur] = sz(euler);
        euler.push_back(cur);
        for (auto next : g[cur]) {
            if (next == par) continue;
            dfs(next, cur, h + 1);
            euler.push_back(cur);
        }
    }

    // Segtree
    void build(int id, int l, int r) { // O(n)
        if (l == r) {
            st[id] = euler[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        int lchild = st[2 * id], rchild = st[2 * id  + 1];
        st[id] = (height[lchild] < height[rchild]) ? lchild : rchild;
    }

    int get(int id, int l, int r, int u, int v) { // O(log n)
        if (l >  v || r <  u) return -inf;
        if (l >= u && r <= v) return st[id];

        int mid = (l + r) >> 1;
        int get1 = get(2 * id, l, mid, u, v);
        int get2 = get(2 * id + 1, mid + 1, r, u, v);
        if (get1 == -inf) return get2;
        if (get2 == -inf) return get1;
        return height[get1] < height[get2] ? get1 : get2;
    }
    

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right) swap(left, right);
        return get(1, 0, sz(euler) - 1, left, right);
    }
};

// Method 2: Binary Lifting 
// init up
void dfs(int u) {
    for (int v : g[u]) {
        if (v == up[u][0]) continue;
        h[v] = h[u] + 1;
        
        up[v][0] = u;
        for (int j = 1; j < 20; ++j)
            up[v][j] = up[up[v][j - 1]][j - 1];

        dfs(v);
    }
}

int h[N], up[N][20];
int lca(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
    
        // find ancestor u' of u in which h(u') = h(v)
        int k = h[u] - h[v];
        for (int j = 0; (1 << j) <= k; ++j)
            if (k >> j & 1) // if jth bit of k is 1
                u = up[u][j];
    }
    if (u == v) return u;
    
    // Find LCA(u,v)
    int k = __lg(h[u]);
    for (int j = k; j >= 0; --j)
        if (up[u][j] != up[v][j]) // if (1<<j)th ancestors of u and v are different
            u = up[u][j], v = up[v][j];
    return up[u][0];
}

// Properties
/*
1. lca(v1, v2) lies on a shortest path from v1 and v2
2. dist(a, b) = depth(a) + depth(b) - 2depth(c) where c = lca(a, b)
3. if v1 is ancestor of v2 => lca(v1,v2) = v1
*/