/**
 * Description: 0-1 BFS, find shortest path in 0-1 weighted graph.
 * Time: better than Dijkstra
 */

// 0-1 BFS could be use to find the minimum of edges that is needed to 
// be reversed in direction to make the path 1->N possible

int n, m;
const int inf = 1e9;
const int maxn = 1e5 + 7;
vector<pi> g[maxn];
int d[maxn];

void sssp(int s) {
    fill_n(d, n + 1, inf);
    deque<int> q;
    q.push_back(s);
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        for (auto e: g[u]) {
            int v = e.second;
            int uv = e.first;
            if (d[v] > d[u] + uv) {
                d[v] = d[u] + uv;
                if (uv == 1) {
                    q.push_back(v);
                }
                else {
                    q.push_front(v);
                }
            }
        }
    }
}
