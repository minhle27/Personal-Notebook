/**
 * Description: Binary Lifting, find kth ancestor of a node in a tree
 */

int par[N], up[N][17];
void preprocess() {
    for (int u = 1; u <= n; ++u) up[u][0] = par[u];
    for (int j = 1; j < 17; ++j)
        for (int u = 1; u <= n; ++u)
            up[u][j] = up[up[u][j - 1]][j - 1];
}

int ancestor_k(int u, int k) {
    for (int j = 0; (1 << j) <= k; ++j)
        if (k >> j & 1) u = up[u][j];
    return u;
}

/**
 * Description: find the furthest ancestor of a node in which dist <= x
 * Time: O(N/logN + Q\log^{2}N)
 */

// Algo 1
int dist[N][17];
int calc_dist(int u, int k) {
    int sum = 0;
    for (int j = 0; (1 << j) <= k; ++j)
        if (k >> j & 1) {
            sum += dist[u][j];
            u = up[u][j];
        }
    return sum;
}

    // binary search to find ans
int solve(int u, int x) {
    int lo = 0, hi = h[u], mid, ans = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (calc_dist(u, mid) <= x) {
            ans = mid;    
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return ancestor_k(u, ans);
}

// Algo 2 (Efficient)
int dist[N][17];
int solve(int u, int x) {
    int now_dist = 0, k = 0;
    for (int j = __lg(h[u]); j >= 0; --j) {
        if (h[u] >= (1 << j) && now_dist + dist[u][j] <= x) {
            now_dist += dist[u][j];
            k |= 1 << j;
            u = up[u][j];
        }
    }
    return u;
}