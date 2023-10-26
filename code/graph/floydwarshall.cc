/**
 * Description: Floyd warshall
 * Time: O(N^3)
 */

void init_trace(vector<vector<int>> &trace) {
    int n = trace.size();
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            trace[u][v] = u;
        }
    }
}

bool floydWarshall(int n, vector<vector<long long>> &w, vector<vector<long long>> &D, vector<vector<int>> &trace) {
    D = w; // if d[i][i] = 0, d[i][j] = INF if no edge
    init_trace(trace); // neu can do duong di
    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // if the graph has negative weight edges, it is better to write the Floyd-Warshall algorithm in the following way, so that it does not perform transitions using paths that don't exist.
                if (D[i][k] < INF && D[k][j] < INF) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]); 
                    trace[i][j] = trace[k][j];

                    // make sure that D[i][j] wont be overflow when graph contains negative cycles
                    D[i][j] = max(D[i][j], -INF);
                }
            }
        }
    }

    // check if graph contain negative cycle
    for (int i = 0; i < n; i++) {
        if (D[i][i] < 0) return false;
    }
    return true;
}

vector<int> trace_path(vector<vector<int>> &trace, int u, int v) {
    vector<int> path;
    while (v != u) { // truy vet nguoc tu v ve u
        path.push_back(v);
        v = trace[u][v];
    }
    path.push_back(u);
    
    reverse(path.begin(), path.end()); // can reverse vi duong di tu v nguoc ve u
    
    return path;
}