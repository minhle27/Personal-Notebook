/**
 * Description: Bipartiteness 
 * Time: O(V + E)
 */

int n, l;
const int maxn = 210;
vector<vi> g(maxn);
int color[maxn];

// A Bipartite Graph has no odd-length cycle

bool checkBipartite() {
    fill_n(color, n + 1, -1);

    queue<int> q;
    q.push(0);
    color[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (color[v] == color[u]) return false;
            if (color[v] == -1) {
                color[v] = !color[u];
                q.push(v);
            }
        }
    }
    return true;
}