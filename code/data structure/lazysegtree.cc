/**
 * Description: Segment Tree with lazy propagation
 */

// everything should be 1-based index

// 1 x y val: Increase all elements in [x, y] by val
// 2 x y: max value in [x, y]

struct SegTree {
    int n;  // size of A
    vi A, st, lazy;

    SegTree(int sz) : n(sz), st(4 * n), lazy(4 * n, 0) {}

    SegTree(const vi& initialA, int a_size): SegTree(a_size) {
        A = initialA;
        build(1, 1, n);
    }

    void build(int id, int l, int r) { // O(n)
        if (l == r) {
            st[id] = A[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        st[id] = max(st[2 * id], st[2 * id + 1]); 
    }

    // propagate
    void fix(int id, int l, int r) {
        if (!lazy[id]) return; 
        st[id] += lazy[id]; // careful about how to update info from lazy to node
    
        if (l != r){ // if not a leaf then propagate downwards
            lazy[2 * id] += lazy[id];
            lazy[2 * id + 1] += lazy[id];
        }
        else {
            A[l] += lazy[id]; 
        }
    
        lazy[id] = 0; // erase lazy flag
    }

    void update(int id, int l, int r, int u, int v, int val) { // O(log n)
        fix(id, l, r);
        if (l > v || r < u) return;
        if (l >= u && r <= v) {
            lazy[id] += val;
            fix(id, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(2 * id, l, mid, u, v, val);
        update(2 * id + 1, mid + 1, r, u, v, val);
        st[id] = max(st[2 * id], st[2 * id + 1]);
    }

    long long get(int id, int l, int r, int u, int v) { // O(log n)
        fix(id, l, r);
        if (l >  v || r <  u) return -inf;
        if (l >= u && r <= v) return st[id];

        int mid = (l + r) >> 1;
        long long get1 = get(2 * id, l, mid, u, v);
        long long get2 = get(2 * id + 1, mid + 1, r, u, v);
        return max(get1, get2);
    }

    void update(int u, int v, int val) { update(1, 1, n, u, v, val); }
    long long get(int u, int v) { return get(1, 1, n, u, v); }
};

int main()
{
    cin >> n >> m;
    vll A(n + 1, 0);
    SegTree st(A, n);

    while (m--) {
        int t; cin >> t;
        if (t == 0) {
            int u, v, val;
            cin >> u >> v >> val;
            st.update(u, v, val);
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << st.get(x, y) << endl;
        }
    }
    
    return 0;
}