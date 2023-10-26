/**
 * Description: BFS
 * Time: O(V + E)
 */

void BFS(int s) {
    queue<int> q;
    visited[s] = true;
    q.push(s);
    
    while (!q.empty()){
        int u = q.front(); 
        q.pop();
        for (auto v : g[u]){
            if (!visited[v]){
                visited[v] = true;
                d[v] = d[u] + 1;
                path[v] = u;
                q.push(v);
            }
        }
    }
}

// Tracing 
void printPath(int u) {
    if (!visited[u]) cout << "No path!";
    else {
        vi path;
        for (int v = u; v != -1; v = path[v]){
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (auto v: path) cout << v << " ";
    }
}