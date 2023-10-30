/**
 * Description: Find shortest cycle starting from a source vertex
 */


int bfs(int s) {
    fill_n(d, n + 1, 0);
    fill_n(visit, n + 1, false);

    queue <int> q;
    q.push(s);
    visit[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            
            // If get back to source, return cycle length and end BFS
            if (v == s) return d[u] + 1;
            
            if (!visit[v]) {
                d[v] = d[u] + 1;
                visit[v] = true;
                q.push(v);
            }
        }
    }
    return 0;
}