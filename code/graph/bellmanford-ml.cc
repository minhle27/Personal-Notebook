/**
 * Description: Bellman-Frod
 * Time: O(MN)
 */

struct Edge {
    int u, v, w;
    Edge(int u = 0, int v = 0, int w = 0) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

vi d(maxn, INF);
vi path(maxn, -1);
vector<Edge> g;
int n, m;

bool BellmanFord(int s) {
    int u, v, w;
    d[s] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            u = g[j].u;
            v = g[j].v;
            w = g[j].w;
            if (d[u] != INF && d[u] + w < d[v]) {
                d[v] = d[u] + w;
                path[v] = u;
            }
        }
    }

    // check if graph contains a negative cycle
    for (int i = 0; i < m; i++) {
        u = g[i].u; v = g[i].v; w = g[i].w;
        if (d[u] != INF && d[u] + w < d[v]) {
            return false;
        }
    }
    return true;
}

vector<int> trace_path(int s, int t) {
    if (t != s && path[t] == -1) return vi(0);

    vi res;
    while (t != -1) {
        res.push_back(t);
        t = path[t];
    }
    reverse(res.begin(), res.end());
    return res;
}

bool findNegativeCycle(vector<int> &negCycle) {
    // after running Bellman-ford n - 1 times
    int negStart = -1;
    for (auto E: g) {
        int u = E.u;
        int v = E.v;
        int w = E.w;
        if (d[u] != INF && d[v] > d[u] + w) {
            d[v] = -INF; 
            path[v] = u;
            negStart = v;
        }
    }

    if (negStart == -1) return false; // no negative cycle

    int u = negStart;
    // To get the vertices that are guaranteed to lie in a negative cycle
    for (int i = 0; i < n; i++) {
        u = path[u];
    }

    negCycle = vector<int>(1, u);
    for (int v = path[u]; v != u; v = path[u]) {
        negCycle.push_back(v); // truy vet mot dong
    }
    reverse(negCycle.begin(), negCycle.end());
    
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back(Edge(u, v, w));
    }

    int s = 0;
    bool res = BellmanFord(s);

    if (!res) {
        // if there is a negative cycle, identify all nodes that does not exist shortest path
        for (int i = 0; i < n; i++) {
            for (auto E : g) {
                int u = E.u; 
                int v = E.v; 
                int w = E.w; 
                if (d[u] != INF && d[v] > d[u] + w) {
                    d[v] = -INF; path[v] = u;
                }
            }
        }
    }

    return 0;
}